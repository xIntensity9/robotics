/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\royalrobotics                                    */
/*    Created:      Tue Sep 28 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// frontLeft            motor         1               
// backLeft             motor         12              
// frontRight           motor         10              
// backRight            motor         18              
// clawLifter1          motor         9               
// clawOpener           motor         15              
// clawLifter2          motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

void move(float duration,std::string direction)
{
  if (direction == "forward") {

    frontLeft.spin(forward,100,rpm);
    backLeft.spin(forward, 100, rpm);
    backRight.spin(forward, 100, rpm);
    frontRight.spin(forward,100, rpm);

    wait(duration,sec);

    frontLeft.stop();
    backLeft.stop();
    backRight.stop();
    frontRight.stop();
  }

  if (direction == "backward"){
    frontLeft.spin(reverse,110,rpm);
    backLeft.spin(reverse,110,rpm);
    backRight.spin(reverse,100,rpm);
    frontRight.spin(reverse,100,rpm);

    wait(duration,sec);

    frontLeft.stop();
    backLeft.stop();
    backRight.stop();
    frontRight.stop();
  }

  if (direction == "left"){
    frontLeft.spin(forward,110,rpm);
    backLeft.spin(forward, 110, rpm);

    wait(duration,sec);

    frontLeft.stop();
    backLeft.stop();
  }
  
  if (direction == "right"){
    frontRight.spin(forward,110,rpm);
    backRight.spin(forward, 110, rpm);

    wait(duration,sec);

    frontRight.stop();
    backRight.stop();
  }

}

void autonomous(void) {
  
  Brain.Screen.print("start");

  // 2nd auto 1st part

  clawLifter1.spin(reverse, 100,rpm);
  clawLifter2.spin(reverse, 100,rpm);

  wait(0.35,sec);

  // closes onto a ring

  clawOpener.spin(reverse,100,rpm);
  wait(0.3,sec);

  clawLifter1.stop();
  clawLifter2.stop();

  // turn 45 degrees

  move(0.76,"left");

  // lifts the claw up

  clawLifter1.spin(forward, 100,rpm);
  clawLifter2.spin(forward, 100,rpm);
  
  wait(0.75,sec);

  clawLifter1.stop();
  clawLifter2.stop();

  // moves forward towards red goal

  move(0.35,"forward");


  // drops the ring in

  wait(0.5,sec);

  clawOpener.spin(forward,100,rpm);
  wait(0.25,sec);
  clawOpener.stop();

  // lowers claw

  clawLifter1.spin(reverse, 100, rpm);
  clawLifter2.spin(reverse, 100, rpm);

  wait(0.5,sec);
  clawLifter1.stop();
  clawLifter2.stop();
  wait(0.5,sec);

  // grabs red goal

  wait(0.25,sec);
  clawOpener.spin(reverse,100,rpm);
  wait(0.25,sec);

  // go backwards, func not included since it specifies speed

  frontLeft.spin(reverse,60,rpm);
  backLeft.spin(reverse, 60, rpm);
  backRight.spin(reverse, 50, rpm);
  frontRight.spin(reverse,50, rpm);

  wait(1.5,sec);

  frontLeft.stop();
  backLeft.stop();
  backRight.stop();
  frontRight.stop();

  clawOpener.spin(forward, 100,rpm);
  wait(0.25,sec);
  clawOpener.stop();

  move(0.4,"right");

  // 2nd auto 2nd part
  /*
  // opens claw
  clawOpener.spin(forward,100,rpm);
  wait(0.5,sec);
  clawOpener.stop();

  // lifts claw a little bit

  clawLifter1.spin(forward,100,rpm);
  clawLifter2.spin(forward,100,rpm);

  wait(0.15,sec);

  clawLifter1.stop();
  clawLifter2.stop();

  // moves towards yellow goal
  move(2.2,"forward");

  // closes
  clawOpener.spin(reverse,100,rpm);
  wait(0.5,sec);

  // moves backward

  frontLeft.spin(reverse,50,rpm);
  backLeft.spin(reverse, 50, rpm);
  backRight.spin(reverse, 50, rpm);
  frontRight.spin(reverse,50, rpm);

  wait(5,sec);

  frontLeft.stop();
  backLeft.stop();
  backRight.stop();
  frontRight.stop();

  clawOpener.stop();
  */

  // 1st auto
  /*
  clawLifter1.spin(reverse, 100,rpm);
  clawLifter2.spin(reverse, 100,rpm);

  wait(0.35,sec);

  // closes onto a ring

  clawOpener.spin(reverse,100,rpm);
  wait(0.3,sec);

  clawLifter1.stop();
  clawLifter2.stop();

  // turn 45 degrees

  move(0.725,"left");

  // lifts the claw up

  clawLifter1.spin(forward, 100,rpm);
  clawLifter2.spin(forward, 100,rpm);
  
  wait(0.75,sec);

  clawLifter1.stop();
  clawLifter2.stop();

  // moves forward

  move(0.35,"forward");

  // lowers claw a little bit so ring doesn't bounce

  clawLifter1.spin(reverse, 100, rpm);
  clawLifter2.spin(reverse, 100, rpm);

  wait(0.15,sec);
  clawLifter1.stop();
  clawLifter2.stop();
  wait(0.15,sec);

  // drops the ring in

  wait(0.5,sec);

  clawOpener.spin(forward,100,rpm);
  wait(0.25,sec);
  clawOpener.stop();

  // lowers claw

  clawLifter1.spin(reverse, 100, rpm);
  clawLifter2.spin(reverse, 100, rpm);

  wait(0.5,sec);
  clawLifter1.stop();
  clawLifter2.stop();
  wait(0.5,sec);

  // grabs red goal

  wait(0.25,sec);
  clawOpener.spin(reverse,100,rpm);
  wait(0.25,sec);

  // go backwards, func not included since it specifies speed

  frontLeft.spin(reverse,60,rpm);
  backLeft.spin(reverse, 60, rpm);
  backRight.spin(reverse, 50, rpm);
  frontRight.spin(reverse,50, rpm);

  wait(1.5,sec);

  frontLeft.stop();
  backLeft.stop();
  backRight.stop();
  frontRight.stop();

  clawOpener.spin(forward, 100,rpm);
  wait(0.25,sec);
  clawOpener.stop();

  */
  }



void controls(void) 
{
  while(1)
  {
  backLeft.spin(directionType::fwd,Controller1.Axis3.position(),percentUnits::pct);
  frontLeft.spin(directionType::fwd,Controller1.Axis3.position(),percentUnits::pct);
  
  backRight.spin(directionType::fwd,Controller1.Axis2.position(),percentUnits::pct);
  frontRight.spin(directionType::fwd,Controller1.Axis2.position(),percentUnits::pct);

  clawLifter1.spin(forward, 100*(Controller1.ButtonL2.pressing() - Controller1.ButtonR2.pressing()), rpm);
  clawLifter2.spin(forward, 100*(Controller1.ButtonL2.pressing() - Controller1.ButtonR2.pressing()), rpm);
  clawOpener.spin(forward, -200*(Controller1.ButtonL1.pressing() - Controller1.ButtonR1.pressing()), rpm);

  }
}

vex::competition Competition;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Competition.drivercontrol(controls);
  Competition.autonomous(autonomous);
}
