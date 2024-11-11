#include <bits/stdc++.h>
int n, k[3], x[3], y[3], m[3], ans[400010], rev;
long long a[3][200010];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d%I64d%d%d%d", &k[i], &a[i][1], &x[i], &y[i], &m[i]);
  for (int i = 1; i <= n; ++i)
    for (int j = 2; j <= k[i]; ++j)
      a[i][j] = (a[i][j - 1] * x[i] + y[i]) % m[i];
  int p = 0;
  for (int i = 1, j = 1; i + j <= k[1] + k[2] + 1;)
    if (i <= k[1] &&
        (j > k[2] || (p <= a[1][i] || p > a[2][j]) && a[1][i] <= a[2][j] ||
         a[1][i] >= p && p > a[2][j])) {
      ans[i + j - 1] = 1;
      if (a[1][i] < p) ++rev;
      p = a[1][i];
      ++i;
    } else {
      ans[i + j - 1] = 2;
      if (a[2][j] < p) ++rev;
      p = a[2][j];
      ++j;
    }
  printf("%d\n", rev);
  if (k[1] + k[2] <= 200000) {
    for (int i = 1, p = 1, q = 1; i <= k[1] + k[2]; ++i)
      printf("%I64d %d\n", ans[i] == 1 ? a[1][p++] : a[2][q++], ans[i]);
  }
  return 0;
}
