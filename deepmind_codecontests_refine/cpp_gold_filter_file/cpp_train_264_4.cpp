#include <bits/stdc++.h>
using namespace std;
int main() {
  char str[4][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) cin >> str[i][j];
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (str[i][j] == '.') {
        if (i == 0 && j == 0) {
          if (str[i + 1][j] == 'x' && str[i + 2][j] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i][j + 1] == 'x' && str[i][j + 2] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i + 1][j + 1] == 'x' && str[i + 2][j + 2] == 'x') {
            cout << "YES";
            return 0;
          }
        }
        if (i == 0 && j == 3) {
          if (str[i + 1][j] == 'x' && str[i + 2][j] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i][j - 1] == 'x' && str[i][j - 2] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i + 1][j - 1] == 'x' && str[i + 2][j - 2] == 'x') {
            cout << "YES";
            return 0;
          }
        }
        if (i == 3 && j == 0) {
          if (str[i - 1][j] == 'x' && str[i - 2][j] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i][j + 1] == 'x' && str[i][j + 2] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i - 1][j + 1] == 'x' && str[i - 2][j + 2] == 'x') {
            cout << "YES";
            return 0;
          }
        }
        if (i == 3 && j == 3) {
          if (str[i - 1][j] == 'x' && str[i - 2][j] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i][j - 1] == 'x' && str[i][j - 2] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i - 1][j - 1] == 'x' && str[i - 1][j - 2] == 'x') {
            cout << "YES";
            return 0;
          }
        }
        if (i == 0 && j == 1) {
          if (str[i][j - 1] == 'x' && str[i][j + 1] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i + 1][j] == 'x' && str[i + 2][j] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i][j + 1] == 'x' && str[i][j + 2] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i + 1][j + 1] == 'x' && str[i + 2][j + 2] == 'x') {
            cout << "YES";
            return 0;
          }
        }
        if (i == 0 && j == 2) {
          if (str[i + 1][j] == 'x' && str[i + 2][j] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i][j - 1] == 'x' && str[i][j - 2] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i][j - 1] == 'x' && str[i][j + 1] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i + 1][j - 1] == 'x' && str[i + 2][j - 2] == 'x') {
            cout << "YES";
            return 0;
          }
        }
        if (i == 1 && j == 0) {
          if (str[i + 1][j] == 'x' && str[i + 2][j] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i + 1][j] == 'x' && str[i - 1][j] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i][j + 1] == 'x' && str[i][j + 2] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i + 1][j + 1] == 'x' && str[i + 2][j + 2] == 'x') {
            cout << "YES";
            return 0;
          }
        }
        if (i == 1 && j == 1) {
          if (str[i + 1][j] == 'x' && str[i + 2][j] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i + 1][j] == 'x' && str[i - 1][j] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i][j + 1] == 'x' && str[i][j - 1] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i][j + 1] == 'x' && str[i][j + 2] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i - 1][j - 1] == 'x' && str[i + 1][j + 1] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i + 1][j - 1] == 'x' && str[i - 1][j + 1] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i + 1][j + 1] == 'x' && str[i + 2][j + 2] == 'x') {
            cout << "YES";
            return 0;
          }
        }
        if (i == 1 && j == 2) {
          if (str[i + 1][j] == 'x' && str[i + 2][j] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i + 1][j] == 'x' && str[i - 1][j] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i - 1][j] == 'x' && str[i - 2][j] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i][j - 1] == 'x' && str[i][j + 1] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i - 1][j - 1] == 'x' && str[i + 1][j + 1] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i + 1][j - 1] == 'x' && str[i - 1][j + 1] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i + 1][j - 1] == 'x' && str[i + 2][j - 2] == 'x') {
            cout << "YES";
            return 0;
          }
        }
        if (i == 1 && j == 3) {
          if (str[i + 1][j] == 'x' && str[i + 2][j] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i + 1][j] == 'x' && str[i - 1][j] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i][j - 1] == 'x' && str[i][j - 2] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i + 1][j - 1] == 'x' && str[i + 1][j - 2] == 'x') {
            cout << "YES";
            return 0;
          }
        }
        if (i == 2 && j == 0) {
          if (str[i + 1][j] == 'x' && str[i - 1][j] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i - 1][j] == 'x' && str[i - 2][j] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i][j + 1] == 'x' && str[i][j + 2] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i - 1][j + 1] == 'x' && str[i - 2][j + 2] == 'x') {
            cout << "YES";
            return 0;
          }
        }
        if (i == 2 && j == 3) {
          if (str[i + 1][j] == 'x' && str[i - 1][j] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i - 1][j] == 'x' && str[i - 2][j] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i][j - 1] == 'x' && str[i][j - 2] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i - 1][j - 1] == 'x' && str[i - 2][j - 2] == 'x') {
            cout << "YES";
            return 0;
          }
        }
        if (i == 2 && j == 2) {
          if (str[i][j + 1] == 'x' && str[i][j - 1] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i + 1][j] == 'x' && str[i - 1][j] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i - 1][j] == 'x' && str[i - 2][j] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i][j - 1] == 'x' && str[i][j - 2] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i - 1][j - 1] == 'x' && str[i + 1][j + 1] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i + 1][j - 1] == 'x' && str[i - 1][j + 1] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i - 1][j - 1] == 'x' && str[i - 2][j - 2] == 'x') {
            cout << "YES";
            return 0;
          }
        }
        if (i == 2 && j == 1) {
          if (str[i][j + 1] == 'x' && str[i][j + 2] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i + 1][j] == 'x' && str[i - 1][j] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i - 1][j] == 'x' && str[i - 2][j] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i][j - 1] == 'x' && str[i][j + 1] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i - 1][j - 1] == 'x' && str[i + 1][j + 1] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i + 1][j - 1] == 'x' && str[i - 1][j + 1] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i - 1][j + 1] == 'x' && str[i - 2][j + 2] == 'x') {
            cout << "YES";
            return 0;
          }
        }
        if (i == 3 && j == 1) {
          if (str[i - 1][j] == 'x' && str[i - 2][j] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i][j - 1] == 'x' && str[i][j + 1] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i][j + 1] == 'x' && str[i][j + 2] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i - 1][j + 1] == 'x' && str[i - 2][j + 2] == 'x') {
            cout << "YES";
            return 0;
          }
        }
        if (i == 3 && j == 2) {
          if (str[i][j - 1] == 'x' && str[i][j - 2] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i - 1][j] == 'x' && str[i - 2][j] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i][j - 1] == 'x' && str[i][j + 1] == 'x') {
            cout << "YES";
            return 0;
          }
          if (str[i - 1][j - 1] == 'x' && str[i - 2][j - 2] == 'x') {
            cout << "YES";
            return 0;
          }
        }
      }
    }
  }
  cout << "NO";
}
