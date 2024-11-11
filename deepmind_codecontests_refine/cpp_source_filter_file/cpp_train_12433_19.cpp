#include <bits/stdc++.h>
using namespace std;
char checkwin(char ch[9]) {
  char c = '.';
  for (int i = 0; i < 3; i++) {
    if (ch[i] == ch[i + 3] && ch[i] == ch[i + 6] && ch[i] != '.') {
      if (c == '0' || (c == 'X' && ch[i] == '0'))
        return 'i';
      else
        c = ch[i];
    }
  }
  for (int i = 0; i < 7; i += 3) {
    if (ch[i] == ch[i + 1] && ch[i] == ch[i + 2] && ch[i] != '.') {
      if (c == '0' || (c == 'X' && ch[i] == '0'))
        return 'i';
      else
        c = ch[i];
    }
  }
  if (ch[0] == ch[4] && ch[0] == ch[8] && ch[0] != '.') {
    if (c == '0' || (c == 'X' && ch[0] == '0'))
      return 'i';
    else
      c = ch[0];
  }
  if (ch[2] == ch[4] && ch[2] == ch[6] && ch[2] != '.') {
    if (c == '0' || (c == 'X' && ch[2] == '0'))
      return 'i';
    else
      c = ch[2];
  }
  return c;
}
int main() {
  int xs = 0, os = 0;
  char ch[9], c;
  for (int i = 0; i < 9; i++) {
    cin >> ch[i];
    if (ch[i] == 'X')
      xs++;
    else if (ch[i] == '0')
      os++;
  }
  if (xs - os > 1 || xs - os < 0)
    cout << "illegal";
  else {
    c = checkwin(ch);
    if (c == 'i')
      cout << "illegal";
    else if (c == 'X')
      if (xs == os)
        cout << "illegal";
      else
        cout << "the first player won";
    else if (c == '0')
      if (xs > os)
        cout << "illegal";
      else
        cout << "the second player won";
    else if (os == 4)
      cout << "draw";
    else if (xs == os)
      cout << "first";
    else
      cout << "second";
  }
}
