#include <bits/stdc++.h>
const int N = 100010;
int deg[N], w[N][3];
int main() {
  int n, m, i, x, y, ans = 0;
  memset(deg, 0, sizeof(deg));
  scanf("%d %d", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d %d", &x, &y);
    deg[x]++;
    deg[y]++;
    if (deg[x] <= 2) w[x][deg[x]] = y;
    if (deg[y] <= 2) w[y][deg[y]] = x;
  }
  for (i = 1; i <= n; i++)
    if (deg[i] % 2 == 1) ans++;
  ans /= 2;
  for (i = 1; i <= n; i++)
    if (deg[i] == 2) {
      if (w[i][1] == w[i][2]) {
        ans++;
        deg[w[i][1]] = 0;
      } else {
        x = w[i][1];
        y = w[i][2];
        if (w[x][1] == i)
          w[x][1] = y;
        else
          w[x][2] = y;
        if (w[y][1] == i)
          w[y][1] = x;
        else
          w[y][2] = x;
      }
    }
  printf("%d %d", ans, m);
  return (0);
}
