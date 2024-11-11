#include <bits/stdc++.h>
int n, m, k, d[1005][105];
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &d[i][j]);
  printf("%d\n", (m * (m - 1)) / 2);
  for (int i = 1; i <= m; i++)
    for (int j = i + 1; j <= m; j++)
      if (!k)
        printf("%d %d\n", i, j);
      else
        printf("%d %d\n", j, i);
  return 0;
}
