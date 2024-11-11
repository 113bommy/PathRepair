#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int maxn = 15;
const int maxm = 65;
const int maxt = 105;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
namespace MaxFlow {
struct Edge {
  int to, rev, cap;
  Edge(int to, int rev, int cap) : to(to), rev(rev), cap(cap) {}
};
int iter[maxt * maxm], level[maxt * maxm];
vector<Edge> g[maxt * maxm];
inline void addEdge(int from, int to, int cap) {
  g[from].push_back(Edge(to, g[to].size(), cap));
  g[to].push_back(Edge(from, g[from].size() - 1, 0));
  return;
}
inline void bfs(int s) {
  queue<int> q;
  memset(level, -1, sizeof(level));
  q.push(s);
  level[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = (0); i < (g[u].size()); ++i) {
      Edge &e = g[u][i];
      if (level[e.to] == -1 && e.cap) {
        level[e.to] = level[u] + 1;
        q.push(e.to);
      }
    }
  }
  return;
}
inline int dfs(int u, int t, int f) {
  if (u == t) return f;
  for (int &i = iter[u]; i < g[u].size(); ++i) {
    Edge &e = g[u][i];
    if (level[e.to] > level[u] && e.cap) {
      int d = dfs(e.to, t, min(e.cap, f));
      if (d) {
        e.cap -= d;
        g[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}
inline int maxFlow(int s, int t) {
  int ret = 0;
  for (;;) {
    bfs(s);
    if (!(~level[t])) break;
    memset(iter, 0, sizeof(iter));
    for (int f; f = dfs(s, t, INF); ret += f)
      ;
  }
  return ret;
}
inline void print(int tot) {
  for (int i = (0); i <= (tot); ++i) {
    for (int j = (0); j < (g[i].size()); ++j) {
      if (g[i][j].cap && i < g[i][j].to)
        printf("u=%d v=%d cap=%d\n", i, g[i][j].to, g[i][j].cap);
    }
  }
  return;
}
}  // namespace MaxFlow
int n, m, tot, mal, s, t, ans;
int cntC[maxt], cntS[maxt], dis[maxt];
bool isBlock[maxt];
char a[maxn][maxn], b[maxn][maxn];
inline int id(int x, int y) { return (x * n + y); }
inline bool canGo(int x, int y) {
  return (x >= 0 && x < n && y >= 0 && y < n && !isBlock[id(x, y)]);
}
void bfs(int sx, int sy) {
  queue<pair<int, int> > q;
  memset(dis, -1, sizeof(dis));
  q.push(make_pair(sx, sy));
  dis[id(sx, sy)] = 0;
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    q.pop();
    for (int i = (0); i < (4); ++i) {
      int nx = x + dx[i], ny = y + dy[i];
      if (canGo(nx, ny) && !(~dis[id(nx, ny)])) {
        dis[id(nx, ny)] = dis[id(x, y)] + 1;
        q.push(make_pair(nx, ny));
      }
    }
  }
  for (int i = (0); i < (tot); ++i)
    if (!(~dis[i])) dis[i] = INF;
  return;
}
int main() {
  scanf("%d%d", &n, &m);
  tot = n * n;
  s = tot * (m + 1);
  t = tot * (m + 1) + 1;
  for (int i = (0); i < (n); ++i) {
    scanf("%s", a[i]);
    for (int j = (0); j < (n); ++j) {
      if (isdigit(a[i][j]))
        cntS[id(i, j)] = a[i][j] - '0';
      else if (a[i][j] == 'Y')
        isBlock[id(i, j)] = 1;
      else if (a[i][j] == 'Z')
        mal = id(i, j);
    }
  }
  for (int i = (0); i < (n); ++i) {
    scanf("%s", b[i]);
    for (int j = (0); j < (n); ++j)
      if (isdigit(b[i][j])) cntC[id(i, j)] = b[i][j] - '0';
  }
  bfs(mal / n, mal % n);
  for (int i = (0); i <= (m); ++i) {
    for (int j = (0); j < (tot); ++j) {
      if (isBlock[j]) continue;
      int x = j / n, y = j % n;
      if (i == m) {
        MaxFlow::addEdge(j + tot * i, t, cntC[j]);
      } else {
        if (!i) MaxFlow::addEdge(s, j + tot * i, cntS[j]);
        if (dis[j] > i) {
          for (int k = (0); k < (4); ++k) {
            int nx = x + dx[k], ny = y + dy[k], nj = id(nx, ny);
            if (canGo(nx, ny) && dis[nj] > i) {
              MaxFlow::addEdge(j + tot * i, nj + tot * (i + 1), INF);
            }
          }
        }
        if (dis[j] <= i)
          MaxFlow::addEdge(j + tot * i, j + tot * (i + 1), cntC[j]);
        else
          MaxFlow::addEdge(j + tot * i, j + tot * (i + 1), INF);
      }
    }
  }
  ans = MaxFlow::maxFlow(s, t);
  printf("%d\n", ans);
  return 0;
}
