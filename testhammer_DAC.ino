#include <Wire.h>
#include <Adafruit_MCP4725.h>
#include <Arduino.h>
#include <Scheduler.h>
#include <EEPROM.h>
#include <SoftwareSerial.h>
#define ESP_SPI_FREQ 4000000
#include <AccelStepper.h>

// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver:
#define dirPin 3
#define stepPin 1
#define motorInterfaceType 1

// Create a new instance of the AccelStepper class:
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);
SoftwareSerial mySerial(13, 12); // RX, TX

Adafruit_MCP4725 MCP4725;

unsigned char v = 1, u = 1,p=1,gt=1,cd=1,cdr=1;
int spe1=5,spe11=4500;
int speed11=5,speed111=15000,spe2=700,snp=1500;
int peri1,peri11,perist=190;
int ncm=5,stepep=50,stepep111=560;
String i;
char x;
uint32_t MCP4725_value;
float MCP4725_reading, MCP4725_set;
int p1, p11, sp2, sp22, n2, n3, n33, sv;
int adr1 ,adr2,adr3,adr4 ;


class PrintTask : public Task {
  protected:


    void setup()
    {
      pinMode(16, OUTPUT);
      digitalWrite(16,0);
      stepper.setMaxSpeed(1000);
      mySerial.begin(9600);
   // Serial.begin(9600);
      EEPROM.begin(512); 
      MCP4725.begin(0x60); // The I2C Address of my module
      MCP4725.setVoltage(0, false);
      pinMode(14, OUTPUT);
      digitalWrite(14, LOW);
      
      //         pinMode(4, OUTPUT);
      //         digitalWrite(4, LOW);
      delay(700);

         mySerial.print("p0.pic=3");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
         mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
         mySerial.write(0xff);
         mySerial.write(0xff); 

         
         mySerial.print("p1.pic=2");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
         mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
         mySerial.write(0xff);
         mySerial.write(0xff);
          mySerial.print("p2.pic=6");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
         mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
         mySerial.write(0xff);
         mySerial.write(0xff);

          mySerial.print("p3.pic=10");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
         mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
         mySerial.write(0xff);
         mySerial.write(0xff);


          mySerial.print("n3.val=5");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);

          mySerial.print("t1.pco=65518");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
         // mySerial.print(0.2);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
          
          mySerial.print("n4.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.print(stepep);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
           mySerial.print("n5.val=0");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
        //  mySerial.print(spe1);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
          ///
           mySerial.print("n2.val=15000");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          //mySerial.print(spe1);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);

            mySerial.print("n0.val=4500");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          //mySerial.print(spe1);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
          //

          mySerial.print("p4.pic=14");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);
            
             mySerial.print("p8.pic=17");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);

            mySerial.print("p5.pic=16");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);

            mySerial.print("p6.pic=13");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);

            mySerial.print("p7.pic=15");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);
    }





    void loop() {
//      stepper.setSpeed(sv);
//      stepper.runSpeed();
      if (mySerial.available() > 0)
      {
        i = mySerial.read();
        if ( i == "24")//hand touch
        {
          cd = 2;
          mySerial.print("p3.pic=11");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
         mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
         mySerial.write(0xff);
         mySerial.write(0xff);
          //cd=1;
          i="1";
          }

          if ( i == "23")//foot touch
        {
          cd =  1;
          //cd=1;

             mySerial.print("n5.val==0");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
         //mySerial.print(0);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);

          mySerial.print("p3.pic=10");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
         mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
         mySerial.write(0xff);
         mySerial.write(0xff);
           i="1";
          }

     // Serial.print(i);
        if ( i == "17" )
        {
          //                EEPROM.write(3,1);
          //                EEPROM.commit();
        //  gt=1;
         u = 4;
         gt=1;
         v = 1;
          mySerial.print("p1.pic=2");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
          mySerial.print("p0.pic=3");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);

        ///
            //   spe1=0;
//         mySerial.print("n0.val=0");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
//          //mySerial.print(spe1);
//          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
//          mySerial.write(0xff);
//          mySerial.write(0xff);
          mySerial.print("n5.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
         mySerial.print(speed111);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
          mySerial.print("n2.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.print(speed111);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
       //     speed11=3;

           //MCP4725.setVoltage(( speed11  * 210), false);
       //     MCP4725.setVoltage(1300, false);

        i="1";
        }


        if ( i == "18" )
        {
          //                EEPROM.write(3,2);
          //                EEPROM.commit();
         //  gt=2;
          u = 5;
          gt=1;
          v = 1;
          mySerial.print("p1.pic=1");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
          mySerial.print("p0.pic=3");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);

            // spe1=0;
//             mySerial.print("n0.val=0");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
//          //mySerial.print(spe1);
//          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
//          mySerial.write(0xff);
//          mySerial.write(0xff);
          mySerial.print("n5.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
         mySerial.print(speed111);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
          mySerial.print("n2.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.print(speed111);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
         //  speed11=3;
       //   MCP4725.setVoltage(1300, false);
          
         i="1";

        }



        if ( i == "19")
        {
        //  gt=3;
          v = v + 1;

         if (v >= 3)
          {
            v = 1;
          }
          if (cdr== 2)
          {
            gt = 1;
          }


          //  Serial.print(v);
          if (v == 2)
          {
            gt = 2;
            mySerial.print("p0.pic=4");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);
          mySerial.print("p1.pic=7");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
          
//           mySerial.print("n0.val=0");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
//          //mySerial.print(spe1);
//          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
//          mySerial.write(0xff);
//          mySerial.write(0xff);
          
          //  spe1=3;
         //    MCP4725.setVoltage(600, false);
         mySerial.print("n0.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.print(spe11);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
          
          mySerial.print("n5.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.print(spe11);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
     
//            mySerial.print("p2.pic=6");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
//            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
//            mySerial.write(0xff);
//            mySerial.write(0xff);


          }

          if (v == 1)
          {
           gt = 1;
          // spe1=500;

            mySerial.print("p0.pic=3");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);
           mySerial.print("p1.pic=1");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
           mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
           mySerial.write(0xff);
           mySerial.write(0xff);
//           mySerial.print("n2.val=0");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
//        //  mySerial.print(spe1);
//          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
//          mySerial.write(0xff);
//          mySerial.write(0xff);
          
         
         //   speed11 = 3;
        //     MCP4725.setVoltage(650, false);
         mySerial.print("n0.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.print(spe11);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
//           mySerial.print("n2.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
//        //  mySerial.print(spe1);
//          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
//          mySerial.write(0xff);
//          mySerial.write(0xff);
          mySerial.print("n5.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.print(spe11);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);


          }
          if (v >= 3)
          {
            v = 1;
          }
        i="1";
        }




        if ( i == "23" )
 
        { 
         //  gt=5;
          mySerial.print("p3.pic=10");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);
          i="1";
        }


        ////////////////////
        if ( i == "24" )
        {
        //   gt=6;
         mySerial.print("p3.pic=11");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);
         i="1";
          }

      
        ///

        if ( i == "25" )

        {
          u = 5;
           mySerial.print("p4.pic=20");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);
            
             mySerial.print("p8.pic=17");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);

            mySerial.print("p5.pic=16");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);

            mySerial.print("p6.pic=13");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);

            mySerial.print("p7.pic=15");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);
             i="1";
         
        }


        ////////////////////
        if ( i == "32")
        {
        u=6;
         mySerial.print("t1.pco=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.print(peri11);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
      
          mySerial.print("p8.pic=19");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);

            mySerial.print("p4.pic=14");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);

            mySerial.print("p5.pic=16");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);

            mySerial.print("p6.pic=13");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);

            mySerial.print("p7.pic=15");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);
             i="1";

          }

       if ( i == "33")

        {
          u = 7;
          mySerial.print("p5.pic=21");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);

             mySerial.print("p4.pic=14");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);
            
             mySerial.print("p8.pic=17");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);

         

            mySerial.print("p6.pic=13");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);

            mySerial.print("p7.pic=15");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);
             i="1";
         
        }


        ////////////////////
        if ( i == "34")
        {
        u=8;
        mySerial.print("p6.pic=22");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);


          mySerial.print("p5.pic=16");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);

             mySerial.print("p4.pic=14");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);
            
             mySerial.print("p8.pic=17");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);

            mySerial.print("p7.pic=15");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);
             i="1";

          }
     if ( i == "35")
        {
          u = 9;
            mySerial.print("p7.pic=18");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);

            mySerial.print("p5.pic=16");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);

             mySerial.print("p4.pic=14");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);
            
             mySerial.print("p8.pic=17");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);

            mySerial.print("p6.pic=13");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);
            i="1";

        }


        ////////////////////
        if ( i == "36")
        {
        u=10;
        i="1";

          }

          
   if ( u==5 && i=="21")
        {
        //   gt=7;
           spe1 = spe1 + 1;

          if (spe1 > 10)
          {
            spe1 = 10;
             
          }
            if (spe1 <= 0)
          {
            spe1=0;
           

          }

       
       spe2 = 580 + (spe1*50) ;
          if (spe1 <= 0)
          {
            spe1=0;
           

          }
//       EEPROM.write(1, 'a'); 
//       EEPROM.commit(); 
     //  spe2 = 600 + (spe1*50) ;
         spe11 = spe1 * 900;
        
       //    MCP4725.setVoltage((spe2), false);
        
         //  MCP4725.setVoltage(spe2, false);
          mySerial.print("n0.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.print(spe11);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
          mySerial.print("n5.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.print(spe11);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
          //     stepper.setSpeed(sv);
          //    stepper.runSpeed();
          //delay(600);

          
     

          
        }

        
   if ( u==5 && i=="22" )
        {
         //  gt=8;
           spe1 = spe1 - 1;

          if (spe1 > 10)
          {
            spe1 = 10;
             
          }
            if (spe1 <= 0)
          {
            spe1=0;
           

          }
       spe2 = 580 + (spe1*50) ;
          if (spe1 <= 0)
          {
            spe1=0;
           

          }
    //   spe2 = 600 + (spe1*50) ;
         spe11 = spe1 * 900;
         
         // spe2 = (50 * spe1) + (spe1*50) ;
//      if (gt == 2 && spe2>=1000)
//     
//      {
//      spe2 = (1000);
//      }
//      
       //    MCP4725.setVoltage(spe2, false);
          mySerial.print("n0.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.print(spe11);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
          mySerial.print("n5.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.print(spe11);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
          
          //     stepper.setSpeed(sv);
          //    stepper.runSpeed();
          //delay(600);

        }

 if ( u==7 && i=="21")
        {

              speed11 = speed11 + 1;
         
          if (speed11 > 10)
          {
            speed11 = 10;
           
          }

          if (speed11 <= 0)
          {
            speed11 = 0;

          }

          snp = ( speed11*170) + ( speed11*170);
         speed111 = speed11 *3000;
         
         
           //MCP4725.setVoltage(( speed11  * 210), false);
          //  MCP4725.setVoltage(snp, false);
          mySerial.print("n2.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.print(speed111);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
          mySerial.print("n5.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.print(speed111);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
          //     stepper.setSpeed(sv);
          //    stepper.runSpeed();
          //delay(600);


          /*
         // gt=11;
         
           speed11 = speed11 + 1;
         
          if (speed11 > 10)
          {
            speed11 = 10;
           
          }

          if (speed11 <= 0)
          {
            speed11 = 0;

          }

          snp = ( speed11*140) + ( speed11*140);
         speed111 = speed11 *3000;
         
         
           //MCP4725.setVoltage(( speed11  * 210), false);
            MCP4725.setVoltage(snp, false);
          mySerial.print("n2.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.print(speed111);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
          mySerial.print("n5.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.print(speed111);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
          //     stepper.setSpeed(sv);
          //    stepper.runSpeed();
          //delay(600);

          */
        }

        
   if ( u==7 && i=="22")
        {
       ///   gt=12;
       
           speed11 = speed11 - 1;
         
          if (speed11 > 10)
          {
            speed11 = 10;
           
          }

          if (speed11 <= 0)
          {
            speed11 = 0;

          }

          snp = ( speed11*170) + ( speed11*170);
         speed111 = speed11 *3000;
         
         
           //MCP4725.setVoltage(( speed11  * 210), false);
          //  MCP4725.setVoltage(snp, false);
          mySerial.print("n2.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.print(speed111);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
          mySerial.print("n5.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.print(speed111);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
          //     stepper.setSpeed(sv);
          //    stepper.runSpeed();
          //delay(600);
         

        }
 if ( u==6 && i=="21" )
        {
         //  gt=9;
        
           peri11 = peri11+ 1;
        
//            EEPROM.write(1, perist);
//            
//            EEPROM.commit();
           
          if (peri11 > 65534)
          {
            peri11 = 65534;
          }

          if (peri11 <  65517)
          {
           peri11 =  65517;

          }

  
        perist=(peri11-65516)*180;
                

          mySerial.print("t1.pco=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.print(peri11);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);

        }

        
   if ( u==6 && i=="22" )
        {
        //    gt=10;
            peri11 = peri11- 1;
           
//            EEPROM.write(1, perist);
//            EEPROM.commit(); 
//  
          if (peri11 > 65534)
          {
            peri11 = 65534;
          }

          if (peri11 <  65517)
          {
           peri11 =  65517;

          }

      perist=(peri11-65516)*180;
//      EEPROM.write(1, perist);
//            
//      EEPROM.commit();
          mySerial.print("t1.pco=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.print(peri11);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);


        }



////////////

  if ( u==8 && i=="21"  )
        {
     //     gt=13;
           ncm = ncm + 1;

          if (ncm > 6)
          {
            ncm = 6;
          }

          if (ncm < 1)
          {
            ncm = 1;

          }

  
        // speed111 = speed11 *3000;
          mySerial.print("n3.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.print(ncm);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
          //     stepper.setSpeed(sv);
          //    stepper.runSpeed();
          //delay(600);

          
        }

        
   if ( u==8 && i=="22" )
        {
       //   gt=14;
            ncm = ncm - 1;

          if (ncm > 6)
          {
            ncm = 6;
          }

          if (ncm < 1)
          {
            ncm = 1;

          }

  
        // speed111 = speed11 *3000;
          mySerial.print("n3.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.print(ncm);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
          //     stepper.setSpeed(sv);
          //    stepper.runSpeed();
          //delay(600);

        }

//stepep

 ////////////

  if ( u==9 && i=="21" )
        {
           stepep = stepep + 10;

          if (stepep> 100)
          {
            stepep= 100;
          }

          if (stepep<= 0)
          {
           stepep = 0;
          stepper.setSpeed(0);
             mySerial.print("n4.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.print(0);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
          }

   if (stepep> 0)
          {
        stepep111 =    300+(stepep *4);
          mySerial.print("n4.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.print(stepep);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
        //  stepper.setSpeed(stepep111);
            
            
          //delay(600);

          } 
        }

        
   if ( u==9 && i=="22" )
        {
               stepep = stepep - 10;

          if (stepep> 100)
          {
            stepep= 100;
          }

        
          if (stepep<= 0)
          {
           stepep = 0;
          stepper.setSpeed(0);
             mySerial.print("n4.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.print(0);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
          }

   if (stepep> 0)
          {
            
        stepep111 =  300+(stepep *4);
          mySerial.print("n4.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
          mySerial.print(stepep);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);
        //  stepper.setSpeed(stepep111);
              //stepper.setSpeed(stepep111);
           //    stepper.runSpeed();
            
          //delay(600);

          }   
        }       



           if ( i == "20")
        {

        //  gt=4;
       //   u = 4;
           p = p + 1;

          if (p >= 3)
          {
            p = 1;
          }

          //  Serial.print(v);
          if (p == 2)
          {
            //u = 2;
            mySerial.print("p2.pic=6");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);
//            mySerial.print("p2.pic=6");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
//            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
//            mySerial.write(0xff);
//            mySerial.write(0xff);
               stepper.setSpeed(0);
               stepper.runSpeed();


          }

          if (p == 1)
          {
         //   u = 3;

            mySerial.print("p2.pic=5");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
            mySerial.write(0xff);
            mySerial.write(0xff);
              stepper.setSpeed(stepep111);
               stepper.runSpeed();
//
//            mySerial.print("p3.pic=4");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
//            mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
//            mySerial.write(0xff);
//            mySerial.write(0xff);

          }
          i="0";

////
        }
      }
      stepper.runSpeed();
    
   } 
}print_task;



class BlinkTask : public Task
{
  protected:

    void setup() {



    }

    void loop()
    {

      if (gt == 2&&cd == 2)
      {
      MCP4725.setVoltage((spe2), false);
      digitalWrite(14, 1); 
      delay(perist);
        
      digitalWrite(16, 0);
      delay(100);
   digitalWrite(16, 1);
//     
      digitalWrite(14, 0);
        delay(perist);
//      digitalWrite(16, 0);
//       delay(40);
      digitalWrite(16, 1);
       delay(100);
      digitalWrite(16, 0);
     

      }

  if (gt == 1 )
      {
     digitalWrite(16, 0);
     delay(300);
     digitalWrite(16, 1);
     cdr=2;
     gt= 0;   

      }  

    if ( u == 4)
      {
     digitalWrite(16, 0);
     delay(300);
     digitalWrite(16, 1);
     cdr=2;
     u=12;
       

      }  

    if (u == 1)
      {
     digitalWrite(16, 0);
     delay(300);
     digitalWrite(16, 1);
     cdr=3;
     u=12;
       
       

      }

      if (cdr==2&&cd == 2)
      {
//     digitalWrite(16, 0);
//     delay(300);
        MCP4725.setVoltage(snp, false);
      digitalWrite(16, 1);
       digitalWrite(14, 0);
       mySerial.print("n5.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
       mySerial.print(speed111);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);


      }

      if (cdr==3&&cd == 2)
      {
 
//       digitalWrite(16, 0);
//     delay(300);
       MCP4725.setVoltage(snp, false);
       digitalWrite(16, 1);
        digitalWrite(14, 1);

      }

      if (cd == 1)
      {
 
//       digitalWrite(16, 0);
//     delay(300);
       MCP4725.setVoltage(0, false);
       digitalWrite(16, 0);
        digitalWrite(14, 1);
         mySerial.print("n5.val=0");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
         //mySerial.print(0);
          mySerial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
          mySerial.write(0xff);
          mySerial.write(0xff);

          cd = 6;

      }

    }

  private:
    uint8_t state;
} blink_task;

void setup() {



  Scheduler.start(&blink_task);
  Scheduler.start(&print_task);
  Scheduler.begin();

}
void loop()
{



}
