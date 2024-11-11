#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, a, b, p, l, k, g;
  cin >> n >> m;
  int ar[n][m];
  p = m * n;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) cin >> ar[i][j];
  cin >> a >> b;
  for (i = 0; i <= n - a; i++) {
    for (j = 0; j <= m - b; j++) {
      g = 0;
      for (k = i; k < i + a; k++) {
        for (l = j; l < j + b; l++) {
          if (ar[k][l] == 1) {
            g++;
          }
        }
      }
      if (g < p) p = g;
    }
  }
  for (i = 0; i <= m - b; i++) {
    for (j = 0; j <= n - a; j++) {
      g = 0;
      for (k = i; k < i + b; k++) {
        for (l = j; l < j + a; l++) {
          if (ar[k][l] == 1) {
            g++;
          }
        }
      }
      if (g < p) p = g;
    }
  }
  cout << p << endl;
  return 0;
}
