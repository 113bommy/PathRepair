#include <bits/stdc++.h>
using namespace std;
char a[4][4];
bool checkrow(int i, char k) {
  for (int j = 1; j <= 3; j++) {
    if (a[i][j] != k) return false;
  }
  return true;
}
bool checkcol(int i, char k) {
  for (int j = 1; j <= 3; j++) {
    if (a[j][i] != k) return false;
  }
  return true;
}
int main() {
  bool xwin = false, owin = false;
  int countx = 0, counto = 0, count = 0;
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'X') countx++;
      if (a[i][j] == '0') counto++;
    }
  }
  if (countx - counto >= 2 || countx - counto < 0) {
    cout << "illegal";
    return 0;
  }
  for (int i = 1; i <= 3; i++) {
    if (checkrow(i, 'X') == true) {
      count++;
      xwin = true;
    }
    if (checkrow(i, '0') == true) {
      count++;
      owin = true;
    }
  }
  for (int i = 1; i <= 3; i++) {
    if (checkcol(i, '0') == true) {
      count++;
      owin = true;
    }
    if (checkcol(i, 'X') == true) {
      count++;
      xwin = true;
    }
  }
  if (a[2][2] == a[1][3] && a[2][2] == a[3][1] && a[2][2] != '.') {
    count++;
    if (a[2][2] == 'X')
      xwin = true;
    else
      owin = true;
  }
  if (a[2][2] == a[1][1] && a[2][2] == a[3][3] && a[2][2] != '.') {
    count++;
    if (a[2][2] == 'X')
      xwin = true;
    else
      owin = true;
  }
  if (xwin == true && owin == true) {
    cout << "illegal";
    return 0;
  }
  if (count > 0) {
    if (owin == true && countx == counto) {
      cout << "the second player won";
      return 0;
    }
    if (owin == true && countx != counto) {
      cout << "illegal";
      return 0;
    }
    if (xwin == true && countx == counto) {
      cout << "illegal";
      return 0;
    }
    cout << "the first player won";
    return 0;
  }
  if (count == 0) {
    if (countx == counto) cout << "first";
    if (countx + counto == 9) {
      cout << "draw";
      return 0;
    }
    if (countx != counto) cout << "second";
  }
}
