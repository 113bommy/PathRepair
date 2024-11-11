#include <bits/stdc++.h>
int main() {
  int a[110][110], cost[110], i, x, y, ans, n, m, j, k;
  while (scanf("%d %d", &n, &m) == 2) {
    memset(a, 0, sizeof(a));
    for (i = 1; i <= n; i++) {
      scanf("%d", &cost[i]);
    }
    for (i = 0; i < m; i++) {
      scanf("%d %d", &x, &y);
      a[x][y] = 1;
      a[y][x] = 1;
    }
    ans = -1;
    for (i = 1; i <= n; i++) {
      for (j = i + 1; j <= n; j++) {
        for (k = j + 1; k <= n; k++) {
          if (a[i][j] & a[j][k] & a[k][i]) {
            if (ans < 0 || ans > cost[i] + cost[j] + cost[k]) {
              ans = cost[i] + cost[j] + cost[k];
            }
          }
        }
      }
    }
    printf("%d\n", ans);
  }
}
