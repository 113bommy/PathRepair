#include <bits/stdc++.h>
using namespace std;
bool a[2005][2005], visit[2005][2005];
int cx[2005 * 2005], cy[2005 * 2005], c1, n, cnt, cntC, cntS;
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
void genMap() {
  static bool tmp[2005][2005];
  memcpy(tmp, a, sizeof(a));
  memset(a, 0, sizeof(a));
  for (int i = 4; i + 3 <= n; ++i)
    for (int j = 4; j + 3 <= n; ++j) {
      int cnt = 0;
      for (int dx = -3; dx <= 3; ++dx)
        for (int dy = -3; dy <= 3; ++dy) cnt += tmp[i + dx][j + dy];
      if (cnt >= 16)
        a[i][j] = 1;
      else
        a[i][j] = 0;
    }
}
int main() {
  scanf("%d", &n);
  memset(visit, 1, sizeof(visit));
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) scanf("%d", &a[i][j]), visit[i][j] = 0;
  genMap();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (!visit[i][j] && a[i][j]) {
        c1 = 0;
        cnt = 0;
        Ox = 0;
        Oy = 0;
        dfs(i, j);
        if (cnt < 130) continue;
        double max_d = 0;
        int c1_pre = c1;
        Ox /= cnt;
        Oy /= cnt;
        for (int k = 1; k <= c1; ++k)
          dist[k] =
              sqrt((Ox - cx[k]) * (Ox - cx[k]) + (Oy - cy[k]) * (Oy - cy[k]));
        for (int k = 1; k <= c1; ++k) max_d = max(max_d, dist[k]);
        for (int k = 1; k <= c1; ++k) dist[k] /= max_d;
        double ave = accumulate(dist + 1, dist + c1 + 1, 0.0) / c1, sum = 0;
        for (int k = 1; k <= c1; ++k) sum += (dist[k] - ave) * (dist[k] - ave);
        sum /= c1;
        sum = sqrt(sum);
        double div = sum / ave;
        if (div > 0.025 && div < 0.095) printf("div=%.5lf\n", div);
        if (div < 0.05)
          ++cntC;
        else
          ++cntS;
      }
end:;
  printf("%d %d\n", cntC, cntS);
  return 0;
}
