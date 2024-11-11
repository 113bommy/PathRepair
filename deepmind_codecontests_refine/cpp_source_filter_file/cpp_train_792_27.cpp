#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char a[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int f = 0;
      for (int k = 0; k < n; k++) {
        if (k == i) continue;
        if (a[i][j] == a[k][j]) {
          f = 1;
          k = n;
        }
      }
      if (f == 0) {
        for (int k = 0; k < m; k++) {
          if (k == j) continue;
          if (a[i][k] == a[i][j]) {
            f = 1;
            k = m;
          }
        }
      }
      if (f == 0) {
        cout << a[i][j];
      }
    }
  }
  return 0;
}
