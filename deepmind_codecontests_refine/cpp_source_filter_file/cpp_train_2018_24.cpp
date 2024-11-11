#include <bits/stdc++.h>
using namespace std;
const int N = 51;
int i, j, n, m, k, x, y, cur, tot, p, K;
int a[N];
double f[N][N][N], c[N][N], tmp, ans;
int main() {
  for (i = 1; i <= 50; i++) {
    c[i][0] = 1;
    c[i][1] = (double)(i - 1) / (double)(i);
    for (j = 2; j <= 50; j++) c[i][j] = c[i][j - 1] * c[i][1];
  }
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) scanf("%d", &a[i]);
  f[0][0][0] = 1;
  for (i = 0; i <= m - 1; i++)
    for (j = 0; j <= n; j++)
      for (k = 0; k <= n; k++)
        if (f[i][j][k] > 1e-9) {
          f[i + 1][j][k] += f[i][j][k] * c[m - i][n - j];
          tmp = 1;
          for (p = 1; p <= n - j; p++) {
            if (p % a[i + 1] == 0)
              K = p / a[i + 1];
            else
              K = p / a[i + 1] + 1;
            K = max(k, K);
            tmp *= (double)(n - j + 1 - p) / (double)(m - i) / (double)p;
            f[i + 1][j + p][K] += f[i][j][k] * tmp * c[m - i][n - j - p];
          }
        }
  for (k = 0; k <= n; k++) ans += f[m][n][k] * k;
  printf("%.15lf\n", ans);
}
