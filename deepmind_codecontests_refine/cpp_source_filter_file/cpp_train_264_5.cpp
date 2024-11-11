#include <bits/stdc++.h>
using namespace std;
char a[4][4];
int main() {
  ios::sync_with_stdio(false);
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) cin >> a[i][j];
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      if (a[i][j] == '.') {
        if (i < 2 && a[i + 1][j] == 'x' && a[i + 2][j] == 'x') {
          cout << "YES";
          return 0;
        }
        if (i > 1 && a[i - 1][j] == 'x' && a[i - 2][j] == 'x') {
          cout << "YES";
          return 0;
        }
        if (j < 2 && a[i][j + 1] == 'x' && a[i][j + 2] == 'x') {
          cout << "YES";
          return 0;
        }
        if (j > 1 && a[i][j - 1] == 'x' && a[i][j - 2] == 'x') {
          cout << "YES";
          return 0;
        }
        if (i < 2 && j < 2 && a[i + 1][j + 1] == 'x' &&
            a[i + 2][j + 2] == 'x') {
          cout << "YES";
          return 0;
        }
        if (i > 1 && j < 2 && a[i - 1][j + 1] == 'x' &&
            a[i - 2][j + 2] == 'x') {
          cout << "YES";
          return 0;
        }
        if (i < 2 && j > 1 && a[i + 1][j - 1] == 'x' &&
            a[i + 2][j - 2] == 'x') {
          cout << "YES";
          return 0;
        }
        if (i > 1 && j > 1 && a[i - 1][j - 1] == 'x' &&
            a[i - 2][j - 2] == 'x') {
          cout << "YES";
          return 0;
        }
        if (i > 0 && i < 3 && a[i - 1][j] == 'x' && a[i + 1][j] == 'x') {
          cout << "YES";
          return 0;
        }
        if (j > 0 && j < 3 && a[i][j - 1] == 'x' && a[i][j + 1] == 'x') {
          cout << "YES";
          return 0;
        }
        if (i > 0 && j > 0 && i < 3 && j < 3 &&
            ((a[i - 1][j - 1] == 'x' && a[i + 1][j + 1] == 'x') ||
             (a[i - 1][j + 1] == 'x' && a[i - 1][j + 1] == 'x'))) {
          cout << "YES";
          return 0;
        }
      }
  cout << "NO";
  return 0;
}
