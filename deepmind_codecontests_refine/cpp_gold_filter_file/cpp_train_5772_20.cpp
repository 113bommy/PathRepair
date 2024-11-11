#include <bits/stdc++.h>
long long int a[1000000][20], b[1000100], c[1000100], d[1000100], e[1000100],
    f[1000100];
int main() {
  long long int n, m, k, i, x, y, j;
  scanf("%lld %lld %lld", &n, &m, &k);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) scanf("%lld", &a[i][j]);
  }
  for (i = 1; i <= k; i++) {
    scanf("%lld %lld", &b[i], &c[i]);
    x = c[i];
    d[x]++;
    y = b[i];
    e[y]++;
  }
  for (j = 1; j <= m; j++) {
    for (i = 1; i <= n; i++) {
      if (a[i][j] == 1) {
        f[i] += d[j];
      }
    }
  }
  for (i = 1; i <= n; i++) {
    if (f[i] >= e[i])
      printf("%lld ", f[i] - e[i]);
    else
      printf("%lld ", e[i] - f[i]);
  }
  printf("\n");
  return 0;
}
