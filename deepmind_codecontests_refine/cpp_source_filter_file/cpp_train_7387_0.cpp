g#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

string s;


void run() {
    map<char, char> boin;
    boin['T'] = 'a';
    boin['L'] = 'i';
    boin['U'] = 'u';
    boin['R'] = 'e';
    boin['D'] = 'o';
    for (int i = 0; i < s.length(); i+=2) {
        int index = s[i];
        char dir = s[i+1];

        switch (index) {
            case '1':
                // do nothing
                putchar(boin[dir]);
                break;
            case '2':
                putchar('k');
                putchar(boin[dir]);
                break;
            case '3':
                putchar('s');
                putchar(boin[dir]);
                break;
            case '4':
                putchar('t');
                putchar(boin[dir]);
                break;
            case '5':
                putchar('n');
                putchar(boin[dir]);
                break;
            case '6':
                putchar('h');
                putchar(boin[dir]);
                break;
            case '7':
                putchar('m');
                putchar(boin[dir]);
                break;
            case '8':
                putchar('y');
                putchar(boin[dir]);
                break;
            case '9':
                putchar('r');
                putchar(boin[dir]);
                break;
            case '0':
                switch (dir) {
                    case 'T': 
                        putchar('w');
                        putchar('a');
                        break;
                    case 'U':
                        putchar('n');
                        putchar('n');
                        break;
                    case 'D':
                        putchar('w');
                        putchar('o');
                        break;
                }
                break;
        }
   }
}


int main() {
    cin >> s;
    run();
    putchar('\n');
    return 0;
}