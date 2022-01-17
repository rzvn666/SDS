#include <stdio.h>
#include <termios.h>    //termios, TCSANOW, ECHO, ICANON
#include <unistd.h>     //STDIN_FILENO

/*
  please run this on a unix like operating system. Linux/macOS works fine
  !!!DISCLAIMER!!!!
  This program modifies how the TERMINAL normally behaves
  It should restore the original values after quitting but I don't take any
  responsibilites for any damage that might occur while running this program
  !!!DISCLAIMER!!!!

  ADVENTURE GAME
  Made by: TuxTheXplorer
  Date   : 20.11.2018 - Finished 23.11.2018
  Sources used: https://stackoverflow.com/questions/1798511/how-to-avoid-pressing-enter-with-getchar
                https://www.gnu.org/software/libc/manual/html_node/Local-Modes.html
                https://en.wikipedia.org/wiki/Box-drawing_character
*/
#define clear() printf("\e[1;1H\e[2J") //Macro to clear the screen
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x)) //Macro to move the cursos


//Function to print the rooms of the game. Takes an integer and prints the corresponding room
void printRoom(int room){
  switch (room) {
    case 1: printf(
    "▛▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▜\n"
    "▌                                      ▐\n"
    "▌           CONGRATULATIONS            ▐\n"
    "▌            YOU FOUND THE             ▐\n"
    "▌               EASTER                 ▐\n"
    "▌                EGG                    \n"
    "▌                                       \n"
    "▌                ▞▒▚                   ▐\n"
    "▌                ▚▒▞                   ▐\n"
    "▌                                      ▐\n"
    "▌                                      ▐\n"
    "▙▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▟\n");
            break;
    case 2: printf(
    "▛▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▜\n"
    "▌                                      ▐\n"
    "▌       Could there be secrets?        ▐\n"
    "▌                                      ▐\n"
    "▌                                      ▐\n"
    "▌                                       \n"
    "▌                                       \n"
    "▌                                      ▐\n"
    "▌                                      ▐\n"
    "▌                                      ▐\n"
    "▌                                      ▐\n"
    "▙▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▟\n");
            break;
    case 3: printf(
    "▛▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀   ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▜\n"
    "▌                                      ▐\n"
    "▌    Oh no! Looks like the princess    ▐\n"
    "▌       has been locked in a cage      ▐\n"
    "▌         Do you have the key?         ▐\n"
    "▌                                      ▐\n"
    "▌                                      ▐\n"
    "▌                                      ▐\n"
    "▌                                      ▐\n"
    "▌                                      ▐\n"
    "▌                                      ▐\n"
    "▙▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▟\n");
            break;
    case 4: printf(
    "▛▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀   ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▜\n"
    "▌                                      ▐\n"
    "▌                                      ▐\n"
    "▌                                      ▐\n"
    "▌                                      ▐\n"
    "                                        \n"
    "                                        \n"
    "▌                                      ▐\n"
    "▌                                      ▐\n"
    "▌                                      ▐\n"
    "▌                                      ▐\n"
    "▙▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▟\n");
            break;
    case 5: printf(
    "▛▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▜\n"
    "▌                                      ▐\n"
    "▌        IT'S DANGEROUS TO GO          ▐\n"
    "▌          ALONE! TAKE THIS.           ▐\n"
    "▌                                      ▐\n"
    "▌    )                           )     ▐\n"
    "▌   ) \\                         ) \\    ▐\n"
    "▌  / ) (                       / ) (   ▐\n"
    "▌  \\(_)/                       \\(_)/   ▐\n"
    "▌                                      ▐\n"
    "▌                                      ▐\n"
    "▙▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▟\n");
            break;
    case 6: printf(
    "▛▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▜\n"
    "▌  Eww, such a scary monster. It is    ▐\n"
    "▌    invincible! Only the wand of      ▐\n"
    "▌     Dereferencing can destroy it.    ▐\n"
    "▌       (Hint: His eyes are weak)      ▐\n"
    "                                       ▐\n"
    "                                       ▐\n"
    "▌                                      ▐\n"
    "▌                                      ▐\n"
    "▌                                      ▐\n"
    "▌                                      ▐\n"
    "▙▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▟\n");
          break;
  }
}

//This function adds the Wand to room 5 and when the player "picks" up the wand then it blocks from drawing it again
int dagger(int x,int y,int wand) {
  int counter = wand;
  if(counter==0) {
    if ((x==20) && (y!=7)){   //The wand is in position 20,7 on the x,y axis.
      gotoxy(20, 7);
      printf("ƒ");
    }else if ((x!=20) && (y==7)) {
      gotoxy(20, 7);
      printf("ƒ");
    }else if ((x!=20) && (y!=7)) {
      gotoxy(20, 7);
      printf("ƒ");
    }else if ((x==20) && (y==7)) {
      counter=1;
      printf("You picked up The Wand of Dereferencing!\nPress j,k,i,l to use it!");
      }
  }
  return counter;
}

//Function that handles monster printing
int monster(int monster){
  int counter = monster;
  if (counter==0) {
    gotoxy(18,7);
    printf("  oo`'._..---.___..-");
    gotoxy(18,8);
    printf(" (_,-.        ,..'` ");
    gotoxy(18,9);
    printf("      `'.    ;      ");
    gotoxy(18,10);
    printf("         : :`       ");
    gotoxy(18,11);
    printf("        _;_;        ");
  }else if(counter==1){
    gotoxy(0,13);
    printf("You Picked up the KEY\n");
    gotoxy(10,8);
    printf("You are a real warrior!");
    gotoxy(6,9);
    printf("Here, take this key as a reward!");
  }
return counter;
}

//Funcion that handles princess printing
int princess(int cage){
  int counter = cage;
  if (counter ==0) {
    gotoxy(8,8);
    printf("▛▀▀▜");
    gotoxy(8,9);
    printf("▌:(▐▚");
    gotoxy(8,10);
    printf("▙▄▄▟");
  }else if(counter==1){
    gotoxy(0,13);
    printf("Hurraaay You are the Hero!\nThe Princess is Free\nThanks for playing!");
    gotoxy(9,9);
    printf(":)");
  }
  return counter;
}



int main() {
//DANGER ZONE!!!! Stroring current terminal configuration in "oldt" and then editing it so that
//Inputs (In our case from stdin) don't buffer (Don't wait for EOF or \n) Don't need to press ENTER
//More on this: https://www.gnu.org/software/libc/manual/html_node/Local-Modes.html
/////////////////////////////////////////////////
  static struct termios oldt, newt;
  tcgetattr( STDIN_FILENO, &oldt); //storing terminal settings in oldt
  newt = oldt; //copying oldt to newt
  newt.c_lflag &= ~(ICANON | ECHO); //Turning off canoninal input bit and echo bit
  tcsetattr( STDIN_FILENO, TCSANOW, &newt); //Setting terminal to the new settings
/////////////////////////////////////////////////
int c; //Using c to store the keystrokes from keyboard
int x = 20; //X coordinate for use in moving the cursos
int y = 8;  //Y coordinate for use in moving the cursos
int rum = 4; //Stores which ROOM you are in. SEE "assets.txt" FOR MORE
int gotWand = 0; //Storing the state of The Wand of Dereferencing
int gotMonster = 0; //Store the state of monster
int gotKey = 0; //Store the state of key

//Initial setup of the game. Printing default room + some guide text
clear();

printf(
"  ___               __                     _           \n"
" |   \\ ___ _ _ ___ / _|___ _ _ ___ _ _  __(_)_ _  __ _ \n"
" | |) / -_) '_/ -_)  _/ -_) '_/ -_) ' \\/ _| | ' \\/ _` |\n"
" |___/\\___|_| \\___|_| \\___|_| \\___|_||_\\__|_|_||_\\__, |\n"
"              Loading... Please Stand By         |___/ \n");
gotoxy(7,20);
sleep(5);



clear();
printRoom(rum);
gotoxy(6,3);
printf("Welcome! Press any key to start");
gotoxy(12,4);
printf("Movement: w a s d");
gotoxy(15,5);
printf("(e) to quit");
gotoxy(20,8);
getchar();

clear();
printRoom(rum);
gotoxy(x,y);

  //MOVEMENT HANDLING
  //Here I basically capture keystrokes from the keyboard and move the cursor.
  //Also clearing the screen and reprinting the Room so that it's smooooth
  while((c=getchar())!= 'e'){ //Pressing e quits the whole program

    clear();
    printRoom(rum);

    //This is where the magic happens. I switch between inputs and then test for which room the player is in
    //currrently and then depending on the room I limit/allow the cursos to move + choose new room
    //Also printing dynamic objects like Wand and Princess and Monster where needed
    switch (c) {
      case 'w': y--;
                switch (rum) {
                  case 1: if(y<=1){ y++; gotoxy(x,y);} break;
                  case 2: if(y<=1){ y++; gotoxy(x,y);} break;
                  case 3: if(x==20){
                            princess(gotKey);
                            if(y<=0){y=11; rum = 2; clear(); printRoom(rum);}
                            gotoxy(x,y);
                            break;
    /*break?*/              }else if(y<=1){ y++; gotoxy(x,y);} princess(gotKey);
                            break;
                  case 4: if(x==20){
                            //IN HERE I also call dagger() which handles the wand printing
                            if(y<=0){y=11; rum = 5; clear(); printRoom(rum); gotWand=dagger(x,y,gotWand);}
                            gotoxy(x,y);
                            break;
    /*break?*/              }else if(y<=1){ y++; gotoxy(x,y);}
                            break;
                  case 5: if(y<=1){ y++; gotoxy(x,y);} gotWand=dagger(x,y,gotWand); break;
                  case 6: if(y<=1){ y++; gotoxy(x,y);} monster(gotMonster); break;
                }

                gotoxy(x,y);
                break;
      case 'a': x--;
        switch (rum) {
          case 1: if(x<=1){ x++; gotoxy(x,y);} break;
          case 2: if((y==6) || (y==7)){
                    if(x<=0){x=39; rum = 1; clear(); printRoom(rum);}
                  gotoxy(x,y);
                  break;
                }else if(x<=1){ x++; gotoxy(x,y);}
                  break;
          case 3: if(x<=1){ x++; gotoxy(x,y);} princess(gotKey); break;
          case 4: if((y==6) || (y==7)){
                    if(x<=0){x=39; rum = 2; clear(); printRoom(rum);}
                  gotoxy(x,y);
                  break;
                }else if(x<=1){ x++; gotoxy(x,y);}
                  break;
                //IN HERE I also call dagger() which handles the wand printing
          case 5: if(x<=1){ x++; gotoxy(x,y);} gotWand=dagger(x,y,gotWand); break;
          case 6: if((y==6) || (y==7)){
                    monster(gotMonster);
                    if(x<=0){x=39; rum = 4; clear(); printRoom(rum);}
                  gotoxy(x,y);
                  break;
                }else if(x<=1){ x++; gotoxy(x,y);} monster(gotMonster);
              }
                gotoxy(x,y);
                break;
      case 's': y++;
              switch (rum) {
                  case 1: if(y>=12){ y--; gotoxy(x,y);} break;
                  case 2: if(x==20){
                            if(y>=13){y=2; rum = 3; clear(); printRoom(rum); princess(gotKey);}
                          gotoxy(x,y);
                          break;
                        }else if(y>=12){ y--; gotoxy(x,y);}
                          break;
                  case 3: if(y>=12){ y--; gotoxy(x,y);} princess(gotKey); break;
                  case 4: if(y>=12){ y--; gotoxy(x,y);} break;
                  //IN HERE I also call dagger() which handles the wand printing
                  case 5: if(x==20){
                            gotWand=dagger(x,y,gotWand);
                            if(y>=13){y=2; rum = 4; clear(); printRoom(rum);}
                          gotoxy(x,y);
                          break;
                        }else if(y>=12){ y--; gotoxy(x,y);} gotWand=dagger(x,y,gotWand);
                          break;
                  case 6: if(y>=12){ y--; gotoxy(x,y);} monster(gotMonster); break;
                }
                gotoxy(x,y);
                break;

      case 'd': x++;
      switch (rum) {
          case 1: if((y==6) || (y==7)){
                    if(x>=41){x=2; rum = 2; clear(); printRoom(rum);}
                  gotoxy(x,y);
                  break;
                }else if(x>=40){ x--; gotoxy(x,y);}
                  break;
          case 2: if((y==6) || (y==7)){
                    if(x>=41){x=2; rum = 4; clear(); printRoom(rum);}
                  gotoxy(x,y);
                  break;
                }else if(x>=40){ x--; gotoxy(x,y);}
                  break;
          case 3: if(x>=40){ x--; gotoxy(x,y);} princess(gotKey); break;
          case 4: if((y==6) || (y==7)){
                    if(x>=41){x=2; rum = 6; clear(); printRoom(rum); monster(gotMonster);}
                  gotoxy(x,y);
                  break;
                }else if(x>=40){ x--; gotoxy(x,y);}
                  break;
                //IN HERE I also call dagger() which handles the wand printing
          case 5: if(x>=40){ x--; gotoxy(x,y);} gotWand=dagger(x,y,gotWand); break;
          case 6: if(x>=40){ x--; gotoxy(x,y);} monster(gotMonster); break;
        }
                gotoxy(x,y);
                break;

      //These next 4 cases are controlling the Wand of Dereferencing
      case 'l': if (gotWand==1) {
                if(rum==6) { //This here removes the monster from the screen
                  monster(gotMonster);
                  if(((x==19) || (x==18)) && (y==7)){ gotMonster=1;}
                }
                gotoxy(x+1,y);
                printf("-*");
                usleep(20);}
                if(rum==3) princess(gotKey);    //Also printing the princess and the monster here when player is in the room
                if(rum==6) monster(gotMonster); //So that it looks smooooth
                if(rum==5) gotWand=dagger(x,y,gotWand);
                gotoxy(x,y);
                break;
      case 'k': if (gotWand==1) {
                gotoxy(x,y+1);
                printf("|");
                gotoxy(x,y+2);
                printf("*");
                usleep(20);}
                if(rum==6) monster(gotMonster);
                if(rum==3) princess(gotKey);
                if(rum==5) gotWand=dagger(x,y,gotWand);
                gotoxy(x,y);
                break;
      case 'j': if (gotWand==1) {
                if((gotMonster==1) && (rum==3)){  //Room specific action. When in room 2. Use key instead of Wand
                    gotoxy(x-2,y);
                    printf("#-");
                    if(((x==13) || (x==14)) && (y==9)) gotKey=1; //When Using wand next to princess set gotKey to 1. This causes
                }else{                                           //The princess to be freed and the game is finished.
                  gotoxy(x-2,y);
                  printf("*-");}
                usleep(20);}
                if(rum==6) monster(gotMonster);
                if(rum==3) princess(gotKey);
                if(rum==5) gotWand=dagger(x,y,gotWand);
                gotoxy(x,y);
                break;
      case 'i': if (gotWand==1) {
                gotoxy(x,y-1);
                printf("|");
                gotoxy(x,y-2);
                printf("*");
                usleep(20);}
                if(rum==6) monster(gotMonster);
                if(rum==3) princess(gotKey);
                if(rum==5) gotWand=dagger(x,y,gotWand);
                gotoxy(x,y);
                break;
      default: if(rum==6) monster(gotMonster);
               if(rum==3) princess(gotKey);
               if(rum==5) gotWand=dagger(x,y,gotWand);
               gotoxy(x,y);
               break;
      }
    }


//Preaparing game to quit
  clear();
  printRoom(rum);

  gotoxy(0,13);
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt); //restoring original terminal configuration
  clear();
  return 0;
}
