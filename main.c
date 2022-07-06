#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <Ultrasonic.h>



SoftwareSerial mySoftwareSerial(4, 6); // RX, TX

DFRobotDFPlayerMini myDFPlayer;


Ultrasonic ultrasonic1(12, 10); // trig 12 echo 10
char language = 'A' ; 
int inputPin = 8 ;               // choose the input pin (for PIR sensor)
int distance = 0 ;


void setup() {
 pinMode(inputPin, INPUT);     // declare sensor as input
 pinMode(13, INPUT); 
 Serial.begin (9600);
 
  mySoftwareSerial.begin(9600);

  
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
//connecting with sd card
    while(true);
  }

  
    myDFPlayer.volume(25);  //Set volume value (0~30).
delay (1000);
}




  
void loop() {
  if (digitalRead(13) == HIGH ) {
    
if ( language == 'A' ) {
  language = 'E' ;
}
    else if (language == 'E' ) {
        language = 'A' ;
    }

    
    delay ( 500 ) ;
         speak (4 , 1 );
    delay ( 500 ) ;
    
  }
   // read input value
  
 distance =  ultrasonic1.read() ;

 Serial.println(distance);
delay ( 250 ) ; 

if ( distance < 100 && digitalRead(inputPin)==1) {

  
  delay ( 50 ) ; 
 speak ( 5 , 2 ) ;
        delay (3000);
 distance =  ultrasonic1.read() ;

   while ( true ) {
 distance =  ultrasonic1.read() ;
delay ( 250 ) ; 
 Serial.println(distance);

    if (distance > 100 ){
       speak ( 6 , 3 ) ;
       delay (3000);
      break ;    }
       
      }
      
      } 
      
      
      }




   
void speak ( int y , int z ) {
switch (language) {
case 'E' :
myDFPlayer.play(y);
break; 
case 'A' :
myDFPlayer.play(z);
break; } 


}
