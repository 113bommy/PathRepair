#include <bits/stdc++.h>
using namespace std;
int map[2010][2010];
int map2[2010][2010];
int vis[2010][2010];
int minx, maxx, miny, maxy;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n;
int cnt;
vector<pair<int, int> > pts;
int que[4000100][2], qs, qe;
inline void dfs(int x, int y) {
  qs = qe = 0;
  que[qe][0] = x;
  que[qe][1] = y;
  qe++;
  vis[x][y] = 1;
  while (qs < qe) {
    int x = que[qs][0], y = que[qs][1];
    qs++;
    pts.push_back(make_pair(x, y));
    minx = min(x, minx);
    miny = min(y, miny);
    maxx = max(x, maxx);
    maxy = max(y, maxy);
    int i;
    for (i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx >= 0 && xx < n && yy >= 0 && yy < n && map[xx][yy] &&
          !vis[xx][yy]) {
        vis[xx][yy] = 1;
        que[qe][0] = xx;
        que[qe][1] = yy;
        qe++;
      }
    }
    cnt++;
  }
}
inline bool isg(int x, int y) {
  return map[x - 1][y] + map[x][y - 1] + map[x + 1][y] + map[x][y + 1] >= 3;
}
inline bool ise(int x, int y) {
  return map[x - 1][y] + map[x][y - 1] + map[x + 1][y] + map[x][y + 1] <= 1;
}
const double pi = acos(-1);
const double sq2 = sqrt(2);
inline int isc() {
  int w = maxx - minx + 1, h = maxy - miny + 1;
  if (w <= 10 || h <= 10) return -1;
  int i, mt = 0;
  int cx = minx + w / 2, cy = miny + h / 2;
  for (i = 0; i < pts.size(); i++) {
    int x = pts[i].first - cx, y = pts[i].second - cy;
    {
      int xx = (int)((x + y) / sq2) + cx;
      int yy = (int)((x - y) / sq2) + cy;
      if (xx >= 0 && xx < n && yy >= 0 && yy < n && map[xx][yy]) mt++;
    }
    {
      int xx = (int)((x - y) / sq2) + cx;
      int yy = (int)((x + y) / sq2) + cy;
      if (xx >= 0 && xx < n && yy >= 0 && yy < n && map[xx][yy]) mt++;
    }
    {
      int xx = (int)((x + y) / sq2) + cx;
      int yy = (int)((y - x) / sq2) + cy;
      if (xx >= 0 && xx < n && yy >= 0 && yy < n && map[xx][yy]) mt++;
    }
    {
      int xx = (int)((y - x) / sq2) + cx;
      int yy = (int)((x + y) / sq2) + cy;
      if (xx >= 0 && xx < n && yy >= 0 && yy < n && map[xx][yy]) mt++;
    }
  }
  if (mt >= pts.size() * 4 * 0.88) return 1;
  return 0;
  return 0;
}
int sum[2010][2010];
int main() {
  int i, j;
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) {
      scanf("%d", &map2[i][j]);
      sum[i][j] =
          sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + map2[i][j];
    }
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      int x1 = max(i - 2, 0), x2 = min(i + 3, n), y1 = max(j - 2, 0),
          y2 = min(j + 3, n);
      int x = sum[x1][y1] + sum[x2][y2] - sum[x1][y2] - sum[x2][y1];
      if (x >= 17) map[i][j] = 1;
    }
  int c = 0, s = 0;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (map[i][j] && vis[i][j] == 0) {
        minx = miny = 10000;
        maxx = maxy = -10000;
        cnt = 0;
        pts.clear();
        dfs(i, j);
        int x = isc();
        if (x == 1)
          c++;
        else if (x == 0)
          s++;
      }
  printf("%d %d\n", c, s);
}
