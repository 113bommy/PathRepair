#include <bits/stdc++.h>
using namespace std;
const int INF = 1e18 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int maxn = 25;
namespace MaxFlow {
struct Edge {
  int to, cap, rev;
  Edge(int to, int cap, int rev) : to(to), cap(cap), rev(rev) {}
};
static const int maxv = maxn * maxn * 3;
int iter[maxv], level[maxv];
vector<Edge> g[maxv];
inline void clear() {
  for (int i = (0); i < (maxv); ++i) g[i].clear();
}
inline void addEdge(int from, int to, int cap) {
  g[from].push_back(Edge(to, cap, g[to].size()));
  g[to].push_back(Edge(from, 0, g[from].size() - 1));
  return;
}
inline int dfs(int u, int t, int f) {
  if (u == t) return f;
  for (int &i = iter[u]; i < g[u].size(); ++i) {
    Edge &e = g[u][i];
    if (level[e.to] > level[u] && e.cap > 0) {
      int d = dfs(e.to, t, min(f, e.cap));
      if (d > 0) {
        e.cap -= d;
        g[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}
inline void bfs(int s, int t) {
  memset(level, -1, sizeof(level));
  queue<int> q;
  q.push(s);
  level[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = (0); i < (g[u].size()); ++i) {
      Edge &e = g[u][i];
      if (!(~level[e.to]) && e.cap > 0) {
        level[e.to] = level[u] + 1;
        if (e.to == t) return;
        q.push(e.to);
      }
    }
  }
  return;
}
inline int maxFlow(int s, int t) {
  int ret = 0;
  for (;;) {
    bfs(s, t);
    if (!(~level[t])) break;
    memset(iter, 0, sizeof(iter));
    for (int f; f = dfs(s, t, INF); ret += f)
      ;
  }
  return ret;
}
inline void print(int totv) {
  for (int i = (0); i <= (totv); ++i) {
    for (int j = (0); j < (g[i].size()); ++j) {
      printf("u=%d v=%d cap=%d\n", i, g[i][j].to, g[i][j].cap);
    }
  }
  return;
}
}  // namespace MaxFlow
struct Scayger {
  int x, y, spd;
} boss;
int n, m, male, female, cel, s, t;
int dis[maxn][maxn][maxn][maxn];
char str[maxn][maxn];
Scayger b[maxn * maxn], g[maxn * maxn];
inline int id(int x, int y) { return x * m + y; }
inline bool canGo(int x, int y) {
  return (x >= 0 && x < n && y >= 0 && y < m && str[x][y] == '.');
}
inline void bfs(int sx, int sy) {
  if (str[sx][sy] == '#') {
    for (int i = (0); i < (n); ++i)
      for (int j = (0); j < (n); ++j) dis[sx][sy][i][j] = INF;
    return;
  }
  queue<pair<int, int> > q;
  dis[sx][sy][sx][sy] = 0;
  q.push(make_pair(sx, sy));
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    q.pop();
    for (int i = (0); i < (4); ++i) {
      int nx = x + dx[i], ny = y + dy[i];
      if (canGo(nx, ny) && !(~dis[sx][sy][nx][ny])) {
        q.push(make_pair(nx, ny));
        dis[sx][sy][nx][ny] = dis[sx][sy][x][y] + 1;
      }
    }
  }
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (m); ++j)
      if (!(~dis[sx][sy][i][j])) dis[sx][sy][i][j] = INF;
  return;
}
inline bool check(long long md) {
  MaxFlow::clear();
  for (int u = (0); u < (male); ++u) {
    MaxFlow::addEdge(s, u, 1);
    for (int i = (0); i < (n); ++i) {
      for (int j = (0); j < (m); ++j) {
        if (dis[b[u].x][b[u].y][i][j] == INF) continue;
        if (1ll * dis[b[u].x][b[u].y][i][j] * b[u].spd > 1ll * md) continue;
        MaxFlow::addEdge(u, male + (id(i, j) << 1), 1);
      }
    }
  }
  for (int u = (0); u < (female); ++u) {
    MaxFlow::addEdge(u + male + cel * 2, t, 1);
    for (int i = (0); i < (n); ++i) {
      for (int j = (0); j < (m); ++j) {
        if (dis[g[u].x][g[u].y][i][j] == INF) continue;
        if (1ll * dis[g[u].x][g[u].y][i][j] * g[u].spd > 1ll * md) continue;
        MaxFlow::addEdge(male + (id(i, j) << 1 | 1), u + male + cel * 2, 1);
      }
    }
  }
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (m); ++j) {
      if (str[i][j] == '.') {
        MaxFlow::addEdge(male + (id(i, j) << 1), male + (id(i, j) << 1 | 1), 1);
      }
    }
  int res = MaxFlow::maxFlow(s, t);
  return (res == male);
}
int main() {
  scanf("%d%d%d%d", &n, &m, &male, &female);
  cel = n * m;
  s = male + female + 1 + cel * 2;
  t = s + 1;
  if (abs(male - female) != 1) {
    puts("-1");
    return 0;
  }
  for (int i = (0); i < (n); ++i) scanf("%s", str + i);
  memset(dis, -1, sizeof(dis));
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (m); ++j) bfs(i, j);
  scanf("%d%d%d", &boss.x, &boss.y, &boss.spd);
  --boss.x, --boss.y;
  for (int i = (0); i < (male); ++i)
    scanf("%d%d%d", &b[i].x, &b[i].y, &b[i].spd), --b[i].x, --b[i].y;
  for (int i = (0); i < (female); ++i)
    scanf("%d%d%d", &g[i].x, &g[i].y, &g[i].spd), --g[i].x, --g[i].y;
  if (male < female)
    b[male++] = boss;
  else
    g[female++] = boss;
  long long l = -1, r = 1e11, md;
  while (l + 1 < r) {
    md = (l + r) >> 1;
    if (check(md))
      r = md;
    else
      l = md;
  }
  printf("%I64d\n", (r == INF) ? (-1) : (r));
  return 0;
}
