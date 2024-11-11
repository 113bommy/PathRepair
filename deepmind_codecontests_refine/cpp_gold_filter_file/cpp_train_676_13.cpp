#include <bits/stdc++.h>
using namespace std;
int n, m, k;
char g;
int a[150][150][150];
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int c = 0; c < k; c++) {
        cin >> g;
        a[i][j][c] = (g == '1');
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int c = 0; c < k; c++) {
        if (a[i][j][c] == 1) {
          bool f = false;
          if (i - 1 >= 0 && a[i - 1][j][c] == 1) {
            if (i + 1 < n && a[i + 1][j][c] == 1) f = true;
            if (j + 1 < m && a[i][j + 1][c] == 1 && a[i - 1][j + 1][c] == 0)
              f = true;
            if (c + 1 < k && a[i][j][c + 1] == 1 && a[i - 1][j][c + 1] == 0)
              f = true;
          }
          if (j - 1 >= 0 && a[i][j - 1][c] == 1) {
            if (j + 1 < m && a[i][j + 1][c] == 1) f = true;
            if (c + 1 < k && a[i][j][c + 1] == 1 && a[i][j - 1][c + 1] == 0)
              f = true;
            if (i + 1 < n && a[i + 1][j][c] == 1 && a[i + 1][j - 1][c] == 0)
              f = true;
          }
          if (c - 1 >= 0 && a[i][j][c - 1] == 1) {
            if (c + 1 < k && a[i][j][c + 1] == 1) f = true;
            if (i + 1 < n && a[i + 1][j][c - 1] == 0 && a[i + 1][j][c] == 1)
              f = true;
            if (j + 1 < m && a[i][j + 1][c] == 1 && a[i][j + 1][c - 1] == 0)
              f = true;
          }
          if (f) ans++;
        }
      }
    }
  }
  cout << ans;
}
