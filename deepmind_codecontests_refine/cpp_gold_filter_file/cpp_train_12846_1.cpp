#include <bits/stdc++.h>
using namespace std;
struct aa {
  int x, y;
} tt[1100000];
int n, m, ans, i, j, len, x, y, p, a[1100][1100], zhan[1100][1100];
bool used[1100][1100];
bool cmp(aa x, aa y) { return a[x.x][x.y] < a[y.x][y.y]; }
int main() {
  ans = 0;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      len++;
      tt[len].x = i;
      tt[len].y = j;
    }
  sort(tt + 1, tt + len + 1, cmp);
  ans = -1;
  for (i = len; i; i--) {
    x = tt[i].x;
    for (j = 1; j <= zhan[x][0]; j++) {
      if (zhan[x][j] < tt[i].y) {
        if (used[zhan[x][j]][tt[i].y]) ans = a[tt[i].x][tt[i].y];
        used[zhan[x][j]][tt[i].y] = true;
      } else {
        if (used[tt[i].y][zhan[x][j]]) ans = a[tt[i].x][tt[i].y];
        used[tt[i].y][zhan[x][j]] = true;
      }
    }
    if (ans >= 0) break;
    for (j = 1; j <= zhan[x][0]; j++)
      if (zhan[x][j] > tt[i].y) break;
    for (p = zhan[x][0] + 1; p > j; p--) zhan[x][p] = zhan[x][p - 1];
    zhan[x][j] = tt[i].y;
    zhan[x][0]++;
  }
  printf("%d\n", ans);
}
