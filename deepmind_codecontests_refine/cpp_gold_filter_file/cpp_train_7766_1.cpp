#include <bits/stdc++.h>
using namespace std;
int n;
double c, p, q[210][20010], f[210][20010];
signed main() {
  scanf("%d%lf", &n, &c), c /= 1e6;
  for (int i = 0; i <= n; i++) scanf("%lf", &q[n % 2][i]), q[n % 2][i] /= 1e6;
  for (int i = n - 1; i >= 0; i--)
    for (int j = 0; j <= i; j++) {
      q[(i & 1)][j] = 1.0 * (j + 1) / (i + 1) * q[(i & 1) ^ 1][j + 1] +
                      1.0 * (i + 1 - j) / (i + 1) * q[(i & 1) ^ 1][j];
      if (q[(i & 1)][j] < 1e-18) continue;
      p = q[(i & 1) ^ 1][j + 1] * (j + 1) / q[(i & 1)][j] / (i + 1);
      f[(i & 1)][j] = max(0.0, f[(i & 1) ^ 1][j] * (1 - p) +
                                   (f[(i & 1) ^ 1][j + 1] + 1) * p - c);
    }
  printf("%.10f", f[0][0]);
  return 0;
}
