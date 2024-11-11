#include <bits/stdc++.h>
using namespace std;
int a[2005][2005], visit[2005][2005], cx[2005 * 2005], cy[2005 * 2005],
    can[2005 * 2005], c1, n, cnt, cntC, cntS;
double dist[2005 * 2005], Ox, Oy;
void dfs(int x, int y) {
  if (visit[x][y]) return;
  visit[x][y] = 1;
  ++cnt;
  bool bo = 0;
  Ox += x;
  Oy += y;
  for (int dx = -1; dx <= 1; ++dx)
    for (int dy = -1; dy <= 1; ++dy) {
      int x1 = x + dx, y1 = y + dy;
      if (!a[x1][y1])
        ++bo;
      else
        dfs(x1, y1);
    }
  if (bo) ++c1, cx[c1] = x, cy[c1] = y;
}
int main() {
  scanf("%d", &n);
  memset(visit, 1, sizeof(visit));
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) scanf("%d", &a[i][j]), visit[i][j] = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (!visit[i][j] && a[i][j]) {
        c1 = 0;
        cnt = 0;
        Ox = 0;
        Oy = 0;
        dfs(i, j);
        if (cnt < 130) continue;
        double ave_d = 0;
        int c1_pre = c1;
        Ox /= cnt;
        Oy /= cnt;
        for (int k = 1; k <= c1; ++k)
          dist[k] =
              sqrt((Ox - cx[k]) * (Ox - cx[k]) + (Oy - cy[k]) * (Oy - cy[k]));
        sort(dist + 1, dist + c1 + 1);
        reverse(dist + 1, dist + c1 + 1);
        c1 = min(c1, int(8.1 * sqrt(1.0 * cnt / 0.8)));
        int _c1 = c1;
        for (int k = 1; k <= c1; ++k) ave_d += dist[k];
        ave_d /= c1;
        for (int k = 1; k <= c1; ++k) can[k] = 1;
        for (int k = 1; k <= c1; ++k)
          if (dist[k] < ave_d * 0.87) --_c1, can[k] = 0;
        ave_d = 0;
        for (int k = 1; k <= c1; ++k)
          if (can[k]) ave_d += dist[k];
        ave_d /= _c1;
        double ave = 0, sum = 0;
        for (int k = 1; k <= c1; ++k)
          if (can[k]) ave += dist[k];
        ave /= _c1;
        for (int k = 1; k <= c1; ++k)
          if (can[k]) sum += fabs(dist[k] - ave);
        sum /= _c1;
        if (sum / ave < 0.05)
          ++cntC;
        else
          ++cntS;
      }
end:;
  printf("%d %d\n", cntC, cntS);
  return 0;
}
