#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x, y, mn = 10e6, s = 0;
  cin >> n >> m;
  int b[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> b[i][j];
    }
  }
  cin >> y >> x;
  if (y <= n && x <= m) {
    for (int i = 0; i < n - y + 1; i++) {
      for (int j = 0; j < m - x + 1; j++) {
        for (int k = i; k < i + y; k++) {
          for (int w = j; w < j + x; w++) {
            if (b[k][w] == 1) {
              s++;
            }
          }
        }
        if (s < mn) {
          mn = s;
        }
        s = 0;
      }
    }
  }
  swap(x, y);
  if (y <= n && x <= m) {
    for (int i = 0; i < n - y + 1; i++) {
      for (int j = 0; j < m - x + 1; j++) {
        for (int k = i; k < i + y; k++) {
          for (int w = j; w < j + x; w++) {
            if (b[k][w] == 1) {
              s++;
            }
          }
        }
        if (s < mn) {
          mn = s;
        }
        s = 0;
      }
    }
  }
  cout << mn;
}
