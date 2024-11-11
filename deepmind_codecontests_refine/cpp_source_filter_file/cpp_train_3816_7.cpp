#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, c, i, j, flag = 0;
  cin >> r >> c;
  char a1[r][c];
  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      cin >> a1[i][j];
    }
  }
  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      if (a1[i][j] == '.') {
        a1[i][j] = 'D';
      }
    }
  }
  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      if (a1[i][j] == 'S') {
        if (i > 0) {
          if (a1[i - 1][j] == 'W') {
            cout << "No";
            return 0;
          }
        }
        if (i < r - 1) {
          if (a1[i + 1][j] == 'W') {
            cout << "No";
            return 0;
          }
        }
        if (j > 0) {
          if (a1[i][j - 1] == 'W') {
            cout << "No";
            return 0;
          }
        }
        if (i < c - 1) {
          if (a1[i][j + 1] == 'W') {
            cout << "No";
            return 0;
          }
        }
      }
    }
  }
  cout << "Yes" << endl;
  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      cout << a1[i][j];
    }
    cout << endl;
  }
}
