#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, j, k, x, y, z;
  char a[100][100];
  for (i = 0; i <= 8; i++) {
    for (j = 0; j <= 8; j++) {
      a[i][j] = 'o';
    }
  }
  for (i = 3; i <= 6; i++) {
    cin >> a[i][3] >> a[i][4] >> a[i][5] >> a[i][6];
  }
  for (i = 3; i <= 6; i++) {
    for (j = 3; j <= 6; j++) {
      if (a[i][j] == 'x' && (a[i][j + 1] == 'x' && a[i][j + 2] == '.') ||
          a[i][j] == 'x' && (a[i][j + 1] == '.' && a[i][j + 2] == 'x')) {
        cout << "YES" << endl;
        break;
      } else if (a[i][j] == 'x' && (a[i][j - 1] == 'x' && a[i][j - 2] == '.') ||
                 a[i][j] == 'x' && (a[i][j - 1] == '.' && a[i][j - 2] == 'x')) {
        cout << "YES" << endl;
        break;
      } else if (a[i][j] == 'x' && (a[i - 1][j] == 'x' && a[i - 2][j] == '.') ||
                 a[i][j] == 'x' && (a[i - 1][j] == '.' && a[i - 2][j] == 'x')) {
        cout << "YES" << endl;
        break;
      } else if (a[i][j] == 'x' && (a[i + 1][j] == 'x' && a[i + 2][j] == '.') ||
                 a[i][j] == 'x' && (a[i + 1][j] == '.' && a[i + 2][j] == 'x')) {
        cout << "YES" << endl;
        break;
      } else if (a[i][j] == 'x' &&
                     (a[i + 1][j + 1] == 'x' && a[i + 2][j + 2] == '.') ||
                 a[i][j] == 'x' &&
                     (a[i + 1][j + 1] == '.' && a[i + 2][j + 2] == 'x')) {
        cout << "YES" << endl;
        break;
      } else if (a[i][j] == 'x' &&
                     (a[i + 1][j - 1] == 'x' && a[i + 2][j - 2] == '.') ||
                 a[i][j] == 'x' &&
                     (a[i + 1][j - 1] == '.' && a[i + 2][j - 2] == 'x')) {
        cout << "YES" << endl;
        break;
      } else if (a[i][j] == 'x' &&
                     (a[i - 1][j + 1] == 'x' && a[i - 2][j + 2] == '.') ||
                 a[i][j] == 'x' &&
                     (a[i - 1][j + 1] == '.' && a[i - 2][j + 2] == 'x')) {
        cout << "YES" << endl;
        break;
      } else if (a[i][j] == 'x' &&
                     (a[i - 1][j - 1] == 'x' && a[i - 2][j - 2] == '.') ||
                 a[i][j] == 'x' &&
                     (a[i - 1][j - 1] == '.' && a[i - 2][j - 2] == 'x')) {
        cout << "YES" << endl;
        break;
      }
    }
    if (j < 7) {
      break;
    }
  }
  if (i == 7) cout << "NO" << endl;
}
