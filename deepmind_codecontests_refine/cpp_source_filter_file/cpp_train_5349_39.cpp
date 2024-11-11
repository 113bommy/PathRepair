#include <bits/stdc++.h>
using namespace std;
string a;
int main() {
  int b[1000], t;
  getline(cin, a);
  switch (a[0]) {
    case 'a':
      a[0] = 'A';
      break;
    case 'b':
      a[0] = 'B';
      break;
    case 'c':
      a[0] = 'C';
      break;
    case 'd':
      a[0] = 'D';
      break;
    case 'e':
      a[0] = 'E';
      break;
    case 'f':
      a[0] = 'F';
      break;
    case 'g':
      a[0] = 'G';
      break;
    case 'h':
      a[0] = 'H';
      break;
    case 'i':
      a[0] = 'I';
      break;
    case 'j':
      a[0] = 'J';
      break;
    case 'k':
      a[0] = 'K';
      break;
    case 'l':
      a[0] = 'L';
      break;
    case 'm':
      a[0] = 'M';
      break;
    case 'n':
      a[0] = 'N';
      break;
    case 'o':
      a[0] = 'O';
      break;
    case 'p':
      a[0] = 'P';
      break;
    case 'q':
      a[0] = 'Q';
      break;
    case 'r':
      a[0] = 'R';
      break;
    case 's':
      a[0] = 'S';
      break;
    case 't':
      a[0] = 'T';
      break;
    case 'u':
      a[0] = 'U';
      break;
    case 'v':
      a[0] = 'V';
      break;
    case 'w':
      a[0] = 'W';
      break;
    case 'x':
      a[0] = 'X';
      break;
    case 'y':
      a[0] = 'Y';
      break;
    case 'z':
      a[0] = 'Z';
      break;
  }
  t = a.length();
  for (int i = 0; i <= t; i++) {
    cout << a[i];
  }
  return 0;
}
