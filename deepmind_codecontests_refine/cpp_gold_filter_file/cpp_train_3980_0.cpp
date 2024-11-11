#include <bits/stdc++.h>
using namespace std;
char buf[1 << 15], *fs, *ft;
inline char getc() {
  return (fs == ft &&
          (ft = (fs = buf) + fread(buf, 1, 1 << 15, stdin), fs == ft))
             ? 0
             : *fs++;
}
inline int read() {
  int x = 0, f = 1;
  char ch = getc();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getc();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getc();
  }
  return x * f;
}
const int MAXN = 1010, maxn = 41;
int c[MAXN][MAXN];
int n, m, k, Q, t, h;
int dis[MAXN][MAXN], mark[maxn];
int b[MAXN][MAXN][maxn];
int x[MAXN * MAXN], y[MAXN * MAXN];
int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};
vector<pair<int, int> > g[maxn];
inline void bfs() {
  for (int w = 1; w <= k; ++w) {
    for (int i = 1; i <= k; ++i) mark[i] = 0;
    t = h = 0;
    mark[w] = 1;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) {
        if (w != 1) b[i][j][w - 1] = dis[i][j];
        dis[i][j] = 1000000000;
        if (c[i][j] == w) {
          x[++t] = i;
          y[t] = j;
          dis[i][j] = 0;
        }
      }
    while (h++ < t) {
      int tx = x[h], ty = y[h];
      if (!mark[c[tx][ty]]) {
        int ww = c[tx][ty];
        mark[ww] = 1;
        for (unsigned int j = 0; j < g[ww].size(); ++j) {
          if (dis[g[ww][j].first][g[ww][j].second] > dis[tx][ty] + 1) {
            dis[g[ww][j].first][g[ww][j].second] = dis[tx][ty] + 1;
            x[++t] = g[ww][j].first;
            y[t] = g[ww][j].second;
          }
        }
      }
      for (int i = 1; i <= 4; ++i) {
        int xx = dx[i] + tx;
        int yy = dy[i] + ty;
        if (xx < 1 || yy < 1 || xx > n || yy > m) continue;
        if (dis[xx][yy] > dis[tx][ty] + 1) {
          dis[xx][yy] = dis[tx][ty] + 1;
          x[++t] = xx;
          y[t] = yy;
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) b[i][j][k] = dis[i][j];
}
int main() {
  n = read();
  m = read();
  k = read();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      c[i][j] = read(), g[c[i][j]].push_back(make_pair(i, j));
  bfs();
  Q = read();
  for (int i = 1; i <= Q; ++i) {
    int x, y, xx, yy;
    x = read();
    y = read();
    xx = read();
    yy = read();
    int ans = abs(xx - x) + abs(yy - y);
    for (int w = 1; w <= k; ++w)
      ans = ((ans) > (b[x][y][w] + b[xx][yy][w] + 1)
                 ? (b[x][y][w] + b[xx][yy][w] + 1)
                 : (ans));
    printf("%d\n", ans);
  }
  return 0;
}
