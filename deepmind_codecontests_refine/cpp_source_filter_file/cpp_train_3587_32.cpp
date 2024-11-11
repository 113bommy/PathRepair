#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, c;
long long s[1501][1501], d[1501][1501], x;
int main() {
  scanf("%i %i", &n, &m);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      scanf("%i", &c);
      s[i][j] = s[i][j - 1] + c;
      d[1][j] = s[1][j];
    }
  }
  for (i = 2; i <= n; i++) {
    x = -9e18;
    if (i % 2) {
      for (j = 1; j <= m; j++) {
        d[i][j] = s[i][j] + x;
        x = max(x, d[i - 1][j]);
      }
    } else {
      for (j = m; j > 0; j--) {
        d[i][j] = s[i][j] + x;
        x = max(x, d[i - 1][j]);
      }
    }
  }
  x = -9e18;
  for (i = 1; i <= m; i++) x = max(x, d[n][i]);
  printf("%i", x);
}
