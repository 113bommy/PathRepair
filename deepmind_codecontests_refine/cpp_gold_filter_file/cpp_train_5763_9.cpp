#include <bits/stdc++.h>
long long int n, m, i, j, k, l, r, a[1005][1005], x, y;
long long int mi = -1, mi1 = -1;
int main() {
  scanf("%I64d", &n);
  scanf("%I64d", &m);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      scanf("%I64d", &a[i][j]);
      a[i][0] += a[i][j];
      a[0][j] += a[i][j];
    }
  for (i = 0; i <= n; i++) {
    r = 0;
    for (j = 1; j <= n; j++)
      r += a[j][0] * (4 * i - ((j - 1) * 4 + 2)) * (4 * i - ((j - 1) * 4 + 2));
    if (r < mi || mi == -1) {
      mi = r;
      x = i;
    }
  }
  for (j = 0; j <= m; j++) {
    r = 0;
    for (i = 1; i <= m; i++)
      r += a[0][i] * (4 * j - ((i - 1) * 4 + 2)) * (4 * j - ((i - 1) * 4 + 2));
    if (r < mi1 || mi1 == -1) {
      mi1 = r;
      y = j;
    }
  }
  printf("%I64d\n", mi + mi1);
  printf("%I64d %I64d", x, y);
}
