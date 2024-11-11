#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f7f7f7f;
const int MAXN = 305;
const double eps = 1e-10;
int maze[MAXN][MAXN];
int dis[2][MAXN * MAXN];
int n, m, p;
struct node {
  int x, y, len, id;
  node(int x = 0, int y = 0, int len = 0, int id = 0)
      : x(x), y(y), len(len), id(id) {}
};
vector<node> g[MAXN * MAXN];
bool cmp(node X, node Y) { return X.len < Y.len; }
int ABS(int x) { return x < 0 ? -x : x; }
int getdis(int x1, int y1, int x2, int y2) {
  return ABS(x1 - x2) + ABS(y1 - y2);
}
int getdis(node tx, node ty) { return ABS(tx.x - ty.x) + ABS(tx.y - ty.y); }
int main() {
  int i, j, k, now;
  while (scanf("%d%d%d", &n, &m, &p) != EOF) {
    for (i = 0; i <= p; i++) g[i].clear();
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        scanf("%d", &maze[i][j]);
        g[maze[i][j]].push_back(node(i, j, INF));
      }
    }
    g[0].push_back(node(1, 1));
    for (i = 1; i <= p; i++) {
      int sz1 = g[i - 1].size();
      int sz2 = g[i].size();
      node tx, ty;
      now = 1 - now;
      for (j = 0; j < sz1 && j <= 600; j++) {
        tx = g[i - 1][j];
        for (k = 0; k < sz2; k++) {
          ty = g[i][k];
          g[i][k].len = min(ty.len, tx.len + getdis(tx, ty));
        }
      }
      sort(g[i].begin(), g[i].end(), cmp);
    }
    int ans = INF;
    int sz = g[p].size();
    for (i = 0; i < sz; i++) {
      ans = min(ans, g[p][i].len);
    }
    printf("%d\n", ans);
  }
  return 0;
}
