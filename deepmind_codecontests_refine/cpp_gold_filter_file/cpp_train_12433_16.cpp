#include <bits/stdc++.h>
char a[3][3];
using namespace std;
bool victory(char c) {
  for (int i = 0; i < 3; i++) {
    int g = 0;
    for (int j = 0; j < 3; j++) {
      if (a[i][j] == c) {
        g++;
      }
    }
    if (g == 3) {
      return true;
    }
  }
  for (int i = 0; i < 3; i++) {
    int g = 0;
    for (int j = 0; j < 3; j++) {
      if (a[j][i] == c) {
        g++;
      }
    }
    if (g == 3) {
      return true;
    }
  }
  if (a[0][0] == c && a[1][1] == c && a[2][2] == c) {
    return true;
  }
  if (a[0][2] == c && a[1][1] == c && a[2][0] == c) {
    return true;
  }
  return false;
}
int main() {
  int i, j;
  int c, o;
  c = 0;
  o = 0;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'X') {
        c++;
      } else if (a[i][j] == '0') {
        o++;
      }
    }
  }
  if (c < o || (c - o > 1)) {
    cout << "illegal";
  } else {
    if (victory('X') || victory('0')) {
      if (victory('X') && !victory('0') && c - o == 1) {
        cout << "the first player won";
      } else if (victory('0') && !victory('X') && c == o) {
        cout << "the second player won";
      } else {
        cout << "illegal";
      }
    } else if (c == o) {
      cout << "first";
    } else if (c > o && c != 5) {
      cout << "second";
    } else {
      cout << "draw";
    }
  }
  return 0;
}
