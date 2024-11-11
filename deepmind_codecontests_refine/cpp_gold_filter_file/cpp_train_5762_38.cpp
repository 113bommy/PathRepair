#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int h, w;
vector<vector<int> > f;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
bool check(int x, int y) {
  return 0 <= x && x < w && 0 <= y && y < h && f[y][x];
}
vector<vector<int> > was;
double sumx, sumy;
int cnt;
void dfs1(int x, int y) {
  if (was[y][x] >= 1) return;
  was[y][x] = 1;
  sumx += x;
  sumy += y;
  cnt++;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (!check(nx, ny)) continue;
    dfs1(nx, ny);
  }
}
vector<double> dis;
vector<pair<int, int> > pts;
void dfs2(int x, int y) {
  if (was[y][x] >= 2) return;
  was[y][x] = 2;
  bool bord = false;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (!check(nx, ny)) {
      bord = true;
      continue;
    }
    dfs2(nx, ny);
  }
  if (bord) {
    pts.push_back(make_pair(x, y));
    dis.push_back((x - sumx) * (x - sumx) + (y - sumy) * (y - sumy));
  }
}
int main() {
  while (scanf("%d", &h) >= 1) {
    w = h;
    f = vector<vector<int> >(h, vector<int>(w));
    for (int y = 0; y < h; y++)
      for (int x = 0; x < w; x++) scanf("%d", &f[y][x]);
    vector<vector<int> > f2(h, vector<int>(w, 0));
    for (int y = 0; y < h; y++) {
      for (int x = 0; x < w; x++) {
        for (int dx = -2; dx <= 2; dx++)
          for (int dy = -2; dy <= 2; dy++) {
            if (x + dx < 0 || x + dx >= w) continue;
            if (y + dy < 0 || y + dy >= h) continue;
            f2[y][x] += f[y + dy][x + dx];
          }
        f2[y][x] = (f2[y][x] >= 10);
      }
    }
    f = f2;
    int c1 = 0, c2 = 0;
    was = vector<vector<int> >(h, vector<int>(w, 0));
    for (int y = 0; y < h; y++)
      for (int x = 0; x < w; x++)
        if (!was[y][x] && f[y][x]) {
          sumx = 0, sumy = 0;
          cnt = 0;
          dfs1(x, y);
          assert(cnt > 0);
          if (cnt < 140) continue;
          sumx /= cnt, sumy /= cnt;
          dis.clear();
          pts.clear();
          dfs2(x, y);
          sort(dis.begin(), dis.end());
          double maxd = 0;
          for (int a = 0; a < ((int)(pts).size()); a++)
            for (int b = 0; b < ((int)(pts).size()); b++)
              maxd = max(maxd, (double)(((pts[a].first - pts[b].first) *
                                         (pts[a].first - pts[b].first)) +
                                        ((pts[a].second - pts[b].second) *
                                         (pts[a].second - pts[b].second))));
          maxd = sqrt(maxd);
          double diff = dis[((int)(dis).size()) - 1] - dis[0];
          double k = diff / dis[0];
          fprintf(stderr, "%.2lf\n", k);
          if (k > 0.5)
            c2++;
          else
            c1++;
        }
    printf("%d %d\n", c1, c2);
  }
  return 0;
}
