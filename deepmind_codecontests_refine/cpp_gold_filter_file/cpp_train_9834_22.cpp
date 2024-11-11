#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  char a[6][26];
  a[0][0] = '+';
  a[0][25] = '+';
  for (int i = 1; i < 25; i++) a[0][i] = '-';
  a[5][0] = '+';
  a[5][25] = '+';
  a[1][25] = '|';
  a[2][25] = '|';
  a[3][25] = '|';
  a[4][25] = '|';
  a[1][0] = '|';
  a[2][0] = '|';
  a[3][0] = '|';
  a[4][0] = '|';
  a[1][24] = 'D';
  a[1][23] = '|';
  a[2][24] = '.';
  a[3][24] = '.';
  a[4][24] = '.';
  a[2][23] = '|';
  a[3][23] = '.';
  a[4][23] = '|';
  for (int j = 1; j <= 4; j++) {
    for (int i = 1; i <= 22; i++) {
      if (j == 3)
        a[j][i] = '.';
      else if (i % 2)
        a[j][i] = '#';
      else
        a[j][i] = '.';
    }
  }
  a[3][1] = '#';
  int j = 1;
  while (j <= 4 && (t)) {
    a[j][1] = 'O';
    j = j + 1;
    t = t - 1;
  }
  if (t) {
    int i = 1, k = 3, j = 1;
    while (t) {
      i = 1;
      a[i][k] = 'O';
      t = t - 1;
      i = i + 1;
      if (t) {
        a[i][k] = 'O';
        i = i + 2;
        t = t - 1;
      }
      if (t) {
        a[i][k] = 'O';
        t = t - 1;
      }
      k = k + 2;
    }
  }
  for (int i = 1; i < 25; i++) a[5][i] = '-';
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 26; j++) {
      cout << a[i][j];
    }
    if (i == 1 || i == 4) cout << ")";
    cout << endl;
  }
  return 0;
}
