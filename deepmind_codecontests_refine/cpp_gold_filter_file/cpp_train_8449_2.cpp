#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int maxn = 1005;
namespace Dinic {
const int maxv = 405;
const int maxe = 400005;
int vn, tot;
int head[maxv], nxt[maxe], to[maxe], cap[maxe], iter[maxv], dis[maxv], q[maxv];
void init() {
  tot = 0;
  memset(head, -1, sizeof(head));
  return;
}
void addEdge(int u, int v, int _cap) {
  nxt[tot] = head[u], nxt[tot ^ 1] = head[v];
  to[tot] = v, to[tot ^ 1] = u;
  cap[tot] = _cap, cap[tot ^ 1] = 0;
  head[u] = tot, head[v] = tot ^ 1;
  tot += 2;
  return;
}
bool bfs(int s, int t) {
  int hd = 0, tl = 0;
  memset(dis, -1, sizeof(dis));
  q[tl++] = s;
  dis[s] = 0;
  for (; hd < tl; hd++) {
    int u = q[hd];
    for (int e = head[u]; ~e; e = nxt[e]) {
      int v = to[e], c = cap[e];
      if (c > 0 && !~dis[v]) {
        dis[v] = dis[u] + 1;
        q[tl++] = v;
      }
    }
  }
  return (~dis[t]);
}
int dfs(int u, int t, int f) {
  if (u == t) return f;
  for (int &e = iter[u]; ~e; e = nxt[e]) {
    int v = to[e];
    if (cap[e] > 0 && dis[v] > dis[u]) {
      int d = dfs(v, t, min(f, cap[e]));
      if (d > 0) {
        cap[e] -= d;
        cap[e ^ 1] += d;
        return d;
      }
    }
  }
  return 0;
}
int maxFlow(int s, int t) {
  int ret = 0;
  for (; bfs(s, t);) {
    for (int u = (0); u < (vn); ++u) iter[u] = head[u];
    for (int f; f = dfs(s, t, INF); ret += f)
      ;
  }
  return ret;
}
}  // namespace Dinic
int n, m;
int x1234567890[maxn], y1234567890[maxn], x2345678901[maxn], y2345678901[maxn];
int vis[maxn][maxn];
vector<int> vx, vy;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (0); i < (m); ++i) {
    scanf("%d%d%d%d", x1234567890 + i, y1234567890 + i, x2345678901 + i,
          y2345678901 + i);
    ++x2345678901[i];
    ++y2345678901[i];
    vx.push_back(x1234567890[i]);
    vx.push_back(x2345678901[i]);
    vy.push_back(y1234567890[i]);
    vy.push_back(y2345678901[i]);
  }
  vx.push_back(1);
  vy.push_back(1);
  sort(vx.begin(), vx.end());
  sort(vy.begin(), vy.end());
  vx.erase(unique(vx.begin(), vx.end()), vx.end());
  vy.erase(unique(vy.begin(), vy.end()), vy.end());
  Dinic::init();
  Dinic::vn = vx.size() + vy.size() + 2;
  for (int i = (0); i < (m); ++i) {
    x1234567890[i] =
        lower_bound(vx.begin(), vx.end(), x1234567890[i]) - vx.begin();
    x2345678901[i] =
        lower_bound(vx.begin(), vx.end(), x2345678901[i]) - vx.begin();
    y1234567890[i] =
        lower_bound(vy.begin(), vy.end(), y1234567890[i]) - vy.begin();
    y2345678901[i] =
        lower_bound(vy.begin(), vy.end(), y2345678901[i]) - vy.begin();
    for (int x = (x1234567890[i]); x < (x2345678901[i]); ++x)
      for (int y = (y1234567890[i]); y < (y2345678901[i]); ++y)
        vis[x][y] = true;
  }
  for (int i = (0); i < (vx.size() - 1); ++i)
    Dinic::addEdge(vx.size() + vy.size(), i, vx[i + 1] - vx[i]);
  for (int i = (0); i < (vy.size() - 1); ++i)
    Dinic::addEdge(i + vx.size(), vx.size() + vy.size() + 1, vy[i + 1] - vy[i]);
  for (int i = (0); i < (vx.size()); ++i)
    for (int j = (0); j < (vy.size()); ++j)
      if (vis[i][j]) Dinic::addEdge(i, j + vx.size(), INF);
  printf("%d\n",
         Dinic::maxFlow(vx.size() + vy.size(), vx.size() + vy.size() + 1));
  return 0;
}
