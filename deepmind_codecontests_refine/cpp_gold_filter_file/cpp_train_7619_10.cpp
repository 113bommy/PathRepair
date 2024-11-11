#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, k, sum = 0, temp = -1, f;
  cin >> n >> m;
  int a[n][m];
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (i = n - 1; i >= 0; i--) {
    temp = 8005;
    for (j = m - 1; j >= 0; j--) {
      f = 0;
      if (a[i][j] == 0) {
        a[i][j] =
            (a[i][j + 1] <= a[i + 1][j]) ? a[i][j + 1] - 1 : a[i + 1][j] - 1;
        temp = a[i][j];
        f = 1;
      }
      if (f == 0) {
        if (temp <= a[i][j]) {
          cout << -1;
          return 0;
        }
      }
    }
  }
  for (i = 0; i < n; i++) {
    temp = -1;
    for (j = 0; j < m; j++) {
      if (a[i][j]) {
        if (temp >= a[i][j]) {
          cout << -1;
          return 0;
        }
        temp = a[i][j];
      }
    }
  }
  for (j = 0; j < m; j++) {
    temp = -1;
    for (i = 0; i < n; i++) {
      if (a[i][j]) {
        if (temp >= a[i][j]) {
          cout << -1;
          return 0;
        }
        temp = a[i][j];
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      sum += a[i][j];
    }
  }
  cout << sum;
  return 0;
}
