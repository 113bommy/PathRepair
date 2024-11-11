#include <bits/stdc++.h>
const int S = 13;
int n, m, p, k, a[S][S], res = 0;
int main() {
  scanf("%d%d%d%d", &n, &m, &p, &k);
  for (int i = 1; i <= p; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[x][y]++;
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; j++)
      a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int l = 1; l <= n; l++)
        for (int r = 1; r <= n; r++)
          if (a[l][r] - a[i - 1][r] - a[l][j - 1] + a[i - 1][j - 1] >= k) ++res;
  printf("%d\n", res);
  return 0;
}
