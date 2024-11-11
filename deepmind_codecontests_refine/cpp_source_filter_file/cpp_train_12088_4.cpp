#include <bits/stdc++.h>
const int MAXN = 100000;
const int MAXM = 300000;
const int MAXL = 20;
const long long INF = 1e18;
using namespace std;
inline void enableFileIO() {
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
}
inline int read() {
  int x = 0, w = 1;
  char c = ' ';
  while (c < '0' || c > '9') {
    c = getchar();
    if (c == '-') w = -1;
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return x * w;
}
struct Edge {
  int to, w, nxt;
  Edge() {}
  Edge(int _to, int _w, int _nxt) : to(_to), w(_w), nxt(_nxt) {}
} edge[MAXM + 5];
int tot, head[MAXN + 5];
inline void add(int u, int v, int w) {
  edge[tot] = Edge(v, w, head[u]);
  head[u] = tot++;
  edge[tot] = Edge(u, w, head[v]);
  head[v] = tot++;
}
int un[MAXN + 5], cnt;
int level[MAXN + 5], an[MAXN + 5][MAXL + 5];
long long depth[MAXN + 5];
bool vis[MAXN + 5];
void dfs(int u, int fa) {
  an[u][0] = fa;
  vis[u] = true;
  for (int i = head[u]; ~i; i = edge[i].nxt) {
    int v = edge[i].to, w = edge[i].w;
    if (v == fa) continue;
    if (!vis[v]) {
      depth[v] = depth[u] + w;
      level[v] = level[u] + 1;
      dfs(v, u);
    } else {
      un[++cnt] = u;
      un[++cnt] = v;
    }
  }
}
int n, q, m;
void init() {
  tot = 0;
  memset(head, -1, sizeof(head));
  n = read();
  m = read();
  for (int i = 1; i <= m; ++i) {
    int u = read(), v = read(), w = read();
    add(u, v, w);
  }
  dfs(1, 0);
  for (int i = 1; i < MAXL; ++i) {
    for (int u = 1; u <= n; ++u) {
      an[u][i] = an[an[u][i - 1]][i - 1];
    }
  }
}
int LCA(int u, int v) {
  if (level[u] < level[v]) swap(u, v);
  int k = level[u] - level[v];
  for (int i = 0; (1 << i) <= k; ++i) {
    if (k & (1 << i)) u = an[u][i];
  }
  if (u == v) return u;
  for (int i = MAXL - 1; ~i; --i) {
    if (an[u][i] != an[v][i]) {
      u = an[u][i];
      v = an[v][i];
    }
  }
  return an[u][0];
}
long long dis[40 + 5][MAXN + 5];
struct Node {
  int u;
  long long w;
  Node() {}
  Node(int _u, int _w) : u(_u), w(_w) {}
  bool operator<(const Node &rhs) const { return w > rhs.w; }
};
priority_queue<Node> Q;
void dijkstra(const int id, const int s) {
  for (int i = 1; i <= n; ++i) {
    dis[id][i] = INF;
    vis[i] = false;
  }
  dis[id][s] = 0;
  Q.push(Node(s, 0));
  while (!Q.empty()) {
    int u = Q.top().u;
    Q.pop();
    if (vis[u]) continue;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
      int v = edge[i].to, w = edge[i].w;
      if (dis[id][u] + w < dis[id][v]) {
        dis[id][v] = dis[id][u] + w;
        Q.push(Node(v, dis[id][v]));
      }
    }
    vis[u] = true;
  }
}
int main() {
  init();
  sort(un + 1, un + 1 + cnt);
  cnt = unique(un + 1, un + 1 + cnt) - (un + 1);
  for (int i = 1; i <= cnt; ++i) dijkstra(i, un[i]);
  q = read();
  while (q--) {
    int u = read(), v = read();
    long long ans = depth[u] + depth[v] - 2 * depth[LCA(u, v)];
    for (int i = 1; i <= cnt; ++i) ans = min(ans, dis[i][u] + dis[i][v]);
    printf("%I64d\n", ans);
  }
  return 0;
}
