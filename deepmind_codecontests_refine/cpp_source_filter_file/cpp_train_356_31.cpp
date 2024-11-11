#include <bits/stdc++.h>
using namespace std;
int n, m, x, sum[1010];
long double f[1010][2], g[1010][2], ans, p[1010], P;
int main() {
  scanf("%d%d", &n, &m);
  g[1][0] = 1.;
  double P = 1. / (long double)m;
  for (int i = 1; i <= 810; i++)
    p[i] = 1. / (long double)i, sum[i] = (1 + i) * i / 2;
  for (int i = 1; i <= n; i++) {
    x ^= 1;
    for (int j = 1; j <= min(800, i + 1); j++) {
      f[j][x] = f[j][x ^ 1] * (m - 1) * P;
      g[j][x] = g[j][x ^ 1] * (m - 1) * P;
      g[j][x] += (g[j - 1][x ^ 1] * p[j] + g[j][x ^ 1] * j * p[j + 1]) * P;
      f[j][x] += ((f[j - 1][x ^ 1] + (j - 1) * g[j - 1][x ^ 1]) * p[j] +
                  (j * f[j][x ^ 1] + sum[j] * g[j][x ^ 1]) * p[j + 1] * P) *
                 P;
    }
  }
  for (int i = 1; i <= min(800, n + 1); i++) ans += f[i][x] * m;
  printf("%.12lf\n", (double)ans);
}
