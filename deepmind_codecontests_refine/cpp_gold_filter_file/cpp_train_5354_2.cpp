#include <bits/stdc++.h>
using namespace std;
double ans[3010][3010], x, c;
int f[3010], g[3010];
int main() {
  int i, j, rr, cc, m, n, a, b;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d %d", &a, &b);
    f[a] = 1;
    g[b] = 1;
  }
  rr = 0;
  cc = 0;
  for (i = 1; i <= n; i++)
    if (f[i] == 0) rr++;
  for (i = 1; i <= n; i++)
    if (g[i] == 0) cc++;
  ans[0][0] = 0.0;
  int t = max(rr, cc);
  for (i = 1; i <= t; i++) {
    x = 1.0 * i * ans[i - 1][0] / n;
    c = 1.0 * (n - i) / n;
    ans[i][0] = 1.0 * x / (1 - c) + 1.0 / (1 - c);
  }
  for (i = 1; i <= t; i++) {
    x = 1.0 * i * ans[0][i - 1] / n;
    c = 1.0 * (n - i) / n;
    ans[0][i] = 1.0 * x / (1 - c) + 1.0 / (1 - c);
  }
  for (i = 1; i <= rr; i++) {
    for (j = 1; j <= cc; j++) {
      x = (1.0 * ans[i - 1][j - 1] * i * j + 1.0 * i * (n - j) * ans[i - 1][j] +
           1.0 * j * (n - i) * ans[i][j - 1]) /
          (n * n);
      c = 1.0 * (n - i) * (n - j) / (n * n);
      ans[i][j] = 1.0 * x / (1 - c) + 1.0 / (1 - c);
    }
  }
  printf("%.10lf\n", ans[rr][cc]);
  return 0;
}
