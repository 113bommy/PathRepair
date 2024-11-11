#include <bits/stdc++.h>
long a[5005][5005] = {0};
int main() {
  long n, m, x;
  long i, j;
  long k;
  long ans = 0;
  scanf("%ld%ld%ld", &n, &m, &x);
  for (i = 1, j = 1; i <= n - i + 1 && j <= m - j + 1; i++, j++) {
    for (k = j; k <= m - j + 1; k++) a[i][k] = a[n - i + 1][k] = i;
    for (k = i; k <= n - i + 1; k++) a[k][j] = a[k][m - j + 1] = i;
  }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (((i + j) & 1) == 0 && a[i][j] == x) ans++;
  printf("%ld\n", ans);
  return 0;
}
