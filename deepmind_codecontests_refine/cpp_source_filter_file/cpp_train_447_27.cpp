#include <bits/stdc++.h>
int a[50][50];
int main() {
  int n, i, j, k, tmp1, tmp2;
  scanf("%d", &n);
  int ans = 0;
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j) scanf("%d", &a[i][j]);
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j) {
      tmp1 = tmp2 = 0;
      for (k = 1; k <= n; ++k) {
        tmp1 += a[i][k];
        tmp2 += a[k][j];
      }
      if (tmp1 > tmp2) ++ans;
    }
  printf("%d\n", ans);
  return 0;
}
