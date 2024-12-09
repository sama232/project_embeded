#include <Ultrasonic.h>
#include <Keypad.h>
#include <Servo.h>
Servo myservo;
Ultrasonic ultrasonicF(9, 10); // trig, echo
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 =4 , d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int distanceF;

int pos = 0;

char Data[Password_Lenght]; // 6 is the number of chars it can hold 
char Master[Password_Lenght] = "123456";     //Change PASSWORD here
byte data_count = 0, master_count = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);
  myservo.attach(13);
}

void loop() {
  // put your main code here, to run repeatedly:
  distanceF = ultrasonicF.read();
  //Serial.print(distanceF);

  if(distanceF<10)
  {
      if(distanceF<10)
   {
    asm(" start :");
                asm( "ldi r16, ob00001000");
                 asm("out DDRB, R16");
                 asm ("ldi r17, 0xff");
                 asm ("out BORTB , r17 ") ; 
                 lcd.setCursor(0, 0);
      lcd.print("WELCOME!");
      delay(2000);
      lcd.clear(); 
      delay(1000);
      lcd.setCursor(0, 0);
      lcd.print("ENTER YOUR PASSWORD PLEASE!");
      for (pos = 0; pos <= 180; pos += 1)
      { 
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(50);                       // waits 50 ms for the servo to reach the position
      }
   }
 }
      
      
     
    }
  
}
