#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int n, m;
double a[300 + 10][3000 + 10], b[300 + 10][3000 + 10], c[3000 + 10],
    d[300 + 10], ans = 0;
int main() {
  int i, j, k;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j) {
      scanf("%d", &k);
      a[j][i] = k / 1000.0;
    }
  for (i = 1; i <= m; ++i) {
    b[i][0] = 1;
    for (j = 1; j <= n; ++j) b[i][j] = b[i][j - 1] * (1 - a[i][j]);
    d[i] = b[i][n];
  }
  for (i = 1; i <= n; ++i) {
    for (k = 1, j = 2; j <= m; ++j)
      if (d[j] < d[k]) k = j;
    ans += 1 - d[k];
    for (j = 1; j <= n; ++j)
      c[j] = c[j - 1] * (1 - a[k][j]) + b[k][j - 1] * a[k][j];
    for (j = 1; j <= n; ++j) b[k][j] = c[j];
    d[k] += b[k][n];
  }
  printf("%.10lf\n", ans);
  return 0;
}
