#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[4][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (a[i][j] == 'x') {
        if (a[i + 1][j] == '.' && i + 2 < 4) {
          if (a[i + 2][j] == 'x') {
            cout << "YES";
            return 0;
          }
        } else if (a[i + 1][j] == 'x' && i + 2 < 4) {
          if (a[i + 2][j] == '.') {
            cout << "YES";
            return 0;
          }
        }
        if (a[i + 1][j + 1] == '.' && i + 2 < 4 && j + 2 < 4) {
          if (a[i + 2][j + 2] == 'x') {
            cout << "YES";
            return 0;
          }
        } else if (a[i + 1][j + 1] == 'x' && i + 2 < 4 && j + 2 < 4) {
          if (a[i + 2][j + 2] == '.') {
            cout << "YES";
            return 0;
          }
        }
        if (a[i + 1][j - 1] == '.' && i + 2 < 4 && j - 2 > -1) {
          if (a[i + 2][j - 2] == 'x') {
            cout << "YES";
            return 0;
          }
        } else if (a[i + 1][j - 1] == 'x' && i + 2 < 4 && j - 2 > -1) {
          if (a[i + 2][j - 2] == '.') {
            cout << "YES";
            return 0;
          }
        }
        if (a[i][j + 1] == '.' && j + 2 < 4) {
          if (a[i][j + 2] == 'x') {
            cout << "YES";
            return 0;
          }
        } else if (a[i][j + 1] == 'x' && j + 2 < 4) {
          if (a[i][j + 2] == '.') {
            cout << "YES";
            return 0;
          }
        }
      } else if (a[i][j] == '.') {
        if (a[i + 1][j] == 'x' && i + 2 < 4) {
          if (a[i + 2][j] == 'x') {
            cout << "YES";
            return 0;
          }
        }
        if (a[i + 1][j + 1] == 'x' && i + 2 < 4 && j + 2 < 4) {
          if (a[i + 2][j + 2] == 'x') {
            cout << "YES";
            return 0;
          }
        }
        if (a[i + 1][j - 1] == 'x' && i + 2 < 4 && j - 2 > -1) {
          if (a[i + 2][j - 2] == 'x') {
            cout << "YES";
            return 0;
          }
        }
        if (a[i][j + 1] == 'x' && j + 2 < 4) {
          if (a[i][j + 2] == 'x') {
            cout << "YES";
            return 0;
          }
        }
      }
    }
  }
  cout << "NO";
  return 0;
}
