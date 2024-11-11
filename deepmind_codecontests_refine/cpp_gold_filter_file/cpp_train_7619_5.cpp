#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, i, j, sum = 0, z, x;
  cin >> n >> m;
  int a[n][m];
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (i = n - 1; i >= 0; i--) {
    for (j = m - 1; j >= 0; j--) {
      if (a[i][j] == 0) {
        if (a[i][j + 1] == 0) {
          a[i][j] = a[i + 1][j] - 1;
        } else if (a[i + 1][j] == 0) {
          a[i][j] = a[i][j + 1] - 1;
        } else if (a[i][j + 1] <= a[i + 1][j]) {
          a[i][j] = a[i][j + 1] - 1;
        } else if (a[i][j + 1] > a[i + 1][j]) {
          a[i][j] = a[i + 1][j] - 1;
        }
        if (a[i][j] <= a[i][j - 1] || a[i][j] <= a[i - 1][j]) {
          cout << -1;
          return 0;
        }
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m - 1; j++) {
      if (a[i][j] >= a[i][j + 1]) {
        cout << -1;
        return 0;
      }
    }
  }
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < m; j++) {
      if (a[i][j] >= a[i + 1][j]) {
        cout << -1;
        return 0;
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      sum = sum + a[i][j];
    }
  }
  cout << sum;
  return 0;
}
