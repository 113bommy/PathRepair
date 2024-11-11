#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, sum = 0;
  cin >> n >> m >> k;
  char t;
  int a[n][m][k];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int l = 0; l < k; l++) {
        cin >> t;
        a[i][j][l] = t - '0';
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int l = 0; l < k - 2; l++) {
        if ((a[i][j][l] == 1 || a[i][j][l] == 2) && a[i][j][l + 1] == 1 &&
            (a[i][j][l + 2] == 1 || a[i][j][l + 2] == 2)) {
          a[i][j][l + 1] = 2;
          sum++;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m - 2; j++) {
      for (int l = 0; l < k; l++) {
        if ((a[i][j][l] == 1 || a[i][j][l] == 2) && a[i][j + 1][l] == 1 &&
            (a[i][j + 2][l] == 1 || a[i][j + 2][l] == 2)) {
          a[i][j + 1][l] = 2;
          sum++;
        }
      }
    }
  }
  for (int i = 0; i < n - 2; i++) {
    for (int j = 0; j < m; j++) {
      for (int l = 0; l < k; l++) {
        if ((a[i][j][l] == 1 || a[i][j][l] == 2) && a[i + 1][j][l] == 1 &&
            (a[i + 2][j][l] == 1 || a[i + 2][j][l] == 2)) {
          a[i + 1][j][l] = 2;
          sum++;
        }
      }
    }
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      for (int l = 0; l < k; l++) {
        if ((a[i][j][l] == 1 || a[i][j][l] == 2) &&
            (a[i + 1][j + 1][l] == 1 || a[i + 1][j + 1][l] == 2)) {
          if (a[i + 1][j][l] == 1 && a[i][j + 1][l] == 0) {
            a[i + 1][j][l] = 2;
            sum++;
          } else {
            if (a[i + 1][j][l] == 0 && a[i][j + 1][l] == 1) {
              a[i][j + 1][l] = 2;
              sum++;
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m - 1; j++) {
      for (int l = 0; l < k - 1; l++) {
        if ((a[i][j][l] == 1 || a[i][j][l] == 2) &&
            (a[i][j + 1][l + 1] == 1 || a[i][j + 1][l + 1] == 2)) {
          if (a[i][j + 1][l] == 1 && a[i][j][l + 1] == 0) {
            a[i][j + 1][l] = 2;
            sum++;
          } else {
            if (a[i][j + 1][l] == 0 && a[i][j][l + 1] == 1) {
              a[i][j][l + 1] = 2;
              sum++;
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m; j++) {
      for (int l = 0; l < k - 1; l++) {
        if ((a[i][j][l] == 1 || a[i][j][l] == 2) &&
            (a[i + 1][j][l + 1] == 1 || a[i + 1][j][l + 1] == 2)) {
          if (a[i + 1][j][l] == 1 && a[i][j][l + 1] == 0) {
            a[i + 1][j][l] = 2;
            sum++;
          } else {
            if (a[i + 1][j][l] == 0 && a[i][j][l + 1] == 1) {
              a[i][j][l + 1] = 2;
              sum++;
            }
          }
        }
      }
    }
  }
  cout << sum;
}
