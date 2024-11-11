#include <bits/stdc++.h>
using namespace std;
struct aa {
  int x, y;
} tt[1100000];
int n, m, ans, i, j, len, x, y, a[1100][1100];
bool used[1100][1100], q[1100][1100];
bool cmp(aa x, aa y) { return a[x.x][x.y] < a[y.x][y.y]; }
int main() {
  ans = 0;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) {
      len++;
      tt[len].x = i;
      tt[len].y = j;
    }
  sort(tt + 1, tt + len + 1, cmp);
  for (i = len; i; i--) {
    for (j = 1; j <= n; j++)
      if (q[tt[i].x][j]) {
        x = tt[i].y;
        y = j;
        if (x > y) swap(x, y);
        if (used[x][y]) {
          ans = a[tt[i].x][tt[i].y];
          break;
        }
        used[x][y] = true;
      }
    q[tt[i].x][tt[i].y] = true;
    if (ans) break;
  }
  printf("%d\n", ans);
}
