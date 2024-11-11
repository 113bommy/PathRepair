#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, flg = 0;
  cin >> n >> m;
  char mat[n][m];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i % 2 != 0) {
        mat[i][j] = '#';
      } else {
        mat[i][j] = '.';
        if (i % 2 == 0) {
          mat[i][m] = '#';
          flg = 1;
        }
        if (i % 4 == 0) {
          mat[i][1] = '#';
          if (flg == 1) {
            mat[i][m] = '.';
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << mat[i][j];
    }
    cout << endl;
  }
}
