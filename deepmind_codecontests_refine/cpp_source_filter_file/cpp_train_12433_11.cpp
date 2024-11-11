#include <bits/stdc++.h>
using namespace std;
int main() {
  string l1[3];
  int xno, ono;
  xno = 0;
  ono = 0;
  bool xwin = false;
  bool owin = false;
  for (int i = 0; i < 3; i++) {
    cin >> l1[i];
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (l1[j][0] == l1[j][1] && l1[j][1] == l1[j][2])
        if (l1[j][0] == 'X')
          xwin = true;
        else if (l1[j][0] == '0')
          owin = true;
      if (l1[i][j] == 'X') xno++;
      if (l1[i][j] == '0') ono++;
    }
    if (l1[0][i] == l1[1][i] && l1[1][i] == l1[2][i])
      if (l1[0][i] == 'X')
        xwin = true;
      else if (l1[0][i] == '0')
        owin = true;
  }
  if (l1[0][0] == l1[1][1] && l1[1][1] == l1[2][2]) {
    if (l1[0][0] == 'X') xwin = true;
    if (l1[0][0] == '0') owin = true;
  }
  if (l1[2][0] == l1[1][1] && l1[1][1] == l1[0][2]) {
    if (l1[1][1] == 'X') xwin = true;
    if (l1[1][1] == '0') owin = true;
  }
  if ((xno - ono > 1 || ono - xno >= 1) || (xwin && owin) ||
      (xwin && xno != ono - 1) || (owin && xno != ono)) {
    cout << "illegal";
    return 0;
  }
  if (xwin) {
    cout << "the first player won";
    return 0;
  }
  if (owin) {
    cout << "the second player won";
    return 0;
  }
  if (xno + ono == 9) {
    cout << "draw";
    return 0;
  }
  if (xno - ono == 1) {
    cout << "second";
  }
  if (ono - xno == 0) {
    cout << "first";
  }
}
