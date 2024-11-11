#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[9][9];
  int i, j;
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      cin >> a[i][j];
    }
  }
  int x, y;
  cin >> x >> y;
  int rx = x % 3;
  int ry = y % 3;
  if (rx == 0) rx = 3;
  if (ry == 0) ry = 3;
  int r1, r2, c1, c2;
  if (rx == 1 && ry == 1) {
    r1 = 0;
    r2 = 2;
    c1 = 0;
    c2 = 2;
  } else if (rx == 1 && ry == 2) {
    r1 = 0;
    r2 = 2;
    c1 = 3;
    c2 = 5;
  } else if (rx == 1 && ry == 3) {
    r1 = 0;
    r2 = 2;
    c1 = 6;
    c2 = 8;
  } else if (rx == 2 && ry == 1) {
    r1 = 3;
    r2 = 5;
    c1 = 0;
    c2 = 2;
  } else if (rx == 2 && ry == 2) {
    r1 = 3;
    r2 = 5;
    c1 = 3;
    c2 = 5;
  } else if (rx == 2 && ry == 3) {
    r1 = 3;
    r2 = 5;
    c1 = 6;
    c2 = 8;
  } else if (rx == 3 && ry == 1) {
    r1 = 6;
    r2 = 8;
    c1 = 0;
    c2 = 2;
  } else if (rx == 3 && ry == 2) {
    r1 = 6;
    r2 = 8;
    c1 = 3;
    c2 = 5;
  } else {
    r1 = 6;
    r2 = 8;
    c1 = 6;
    c2 = 8;
  }
  int t = 0;
  for (i = r1; i <= r2; i++) {
    for (j = c1; j <= c2; j++) {
      if (a[i][j] == '.') {
        t = 1;
        break;
      }
    }
    if (t == 1) break;
  }
  if (t == 1) {
    for (i = r1; i <= r2; i++) {
      for (j = c1; j <= c2; j++) {
        if (a[i][j] == '.') {
          a[i][j] = '!';
        }
      }
    }
  } else {
    for (i = 0; i <= 8; i++) {
      for (j = 0; j <= 8; j++) {
        if (a[i][j] == '.') {
          a[i][j] = '!';
        }
      }
    }
  }
  int c = 0;
  for (i = 0; i <= 8; i++) {
    for (j = 0; j <= 8; j++) {
      c++;
      if ((j + 1) % 3 == 0) {
        cout << a[i][j] << "  ";
      } else {
        cout << a[i][j] << " ";
      }
    }
    if (c == 27) {
      c = 0;
      cout << endl;
    }
    cout << endl;
  }
}
