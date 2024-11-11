#include <bits/stdc++.h>
const int N = 300;
const int inf = (int)1e9;
inline int min(int x, int y) {
  if (x < y) return x;
  return y;
}
struct NetWork {
  static const int V = N + 2;
  static const int E = N * N + N;
  struct Edge {
    int to, cap, nxt;
    Edge() {}
    Edge(int _to, int _cap, int _nxt) : to(_to), cap(_cap), nxt(_nxt) {}
  } edge[E * 2 + 5];
  int Gsz, head[V + 5];
  inline void add_edge(int u, int v, int cap) {
    edge[Gsz] = Edge(v, cap, head[u]);
    head[u] = Gsz++;
    edge[Gsz] = Edge(u, 0, head[v]);
    head[v] = Gsz++;
  }
  int src, dest, n;
  void init(int _n) {
    n = _n;
    src = n++;
    dest = n++;
    for (int i = 0, i_END_ = n; i < i_END_; ++i) head[i] = -1;
    Gsz = 0;
  }
  int dist[V + 5], que[V + 5];
  bool bfs() {
    for (int i = 0, i_END_ = n; i < i_END_; ++i) dist[i] = -1;
    int L = 0, H = 0;
    que[H++] = src;
    dist[src] = 0;
    while (L < H) {
      int u = que[L++];
      for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (edge[i].cap > 0 && dist[v] == -1) {
          dist[v] = dist[u] + 1;
          que[H++] = v;
        }
      }
    }
    return dist[dest] != -1;
  }
  int work[V + 5];
  int dfs(int u, int aug) {
    if (u == dest || aug == 0) return aug;
    int res = 0;
    for (int &i = work[u]; ~i; i = edge[i].nxt) {
      int v = edge[i].to;
      if (edge[i].cap > 0 && dist[v] == dist[u] + 1) {
        int tmp = dfs(v, min(edge[i].cap, aug));
        edge[i].cap -= tmp;
        edge[i ^ 1].cap += tmp;
        res += tmp;
        aug -= tmp;
        if (aug == 0) break;
      }
    }
    return res;
  }
  int Dinic() {
    int res = 0;
    while (bfs()) {
      for (int i = 0, i_END_ = n; i < i_END_; ++i) work[i] = head[i];
      res += dfs(src, (int)1e9);
    }
    return res;
  }
} nw;
int cost[N + 5];
struct Bipartite_Graph {
  static const int V = N + N;
  bool g[V + 5][V + 5];
  int n;
  void init(int _n) {
    n = _n;
    for (int i = 0, i_END_ = n; i < i_END_; ++i)
      for (int j = 0, j_END_ = n; j < j_END_; ++j) g[i][j] = false;
  }
  int match[V + 5];
  bool visy[V + 5];
  bool find(int x) {
    for (int y = 0, y_END_ = n; y < y_END_; ++y)
      if (g[x][y]) {
        if (visy[y]) continue;
        visy[y] = true;
        if (match[y] == -1 || find(match[y])) {
          match[y] = x;
          return true;
        }
      }
    return false;
  }
  void Hungary() {
    for (int y = 0, y_END_ = n; y < y_END_; ++y) match[y] = -1;
    for (int x = 0, x_END_ = n; x < x_END_; ++x) {
      for (int y = 0, y_END_ = n; y < y_END_; ++y) visy[y] = false;
      assert(find(x));
    }
  }
  void build() {
    nw.init(n);
    for (int y = 0, y_END_ = n; y < y_END_; ++y) {
      int x = match[y];
      if (cost[x] > 0)
        nw.add_edge(nw.src, x, cost[x]);
      else
        nw.add_edge(x, nw.dest, -cost[x]);
      for (int i = 0, i_END_ = n; i < i_END_; ++i)
        if (g[x][i] && i != y) nw.add_edge(y, i, inf);
    }
  }
} bpt;
int n, sum;
void input() {
  scanf("%d", &n);
  bpt.init(n);
  for (int i = 0, i_END_ = n; i < i_END_; ++i) {
    int m;
    scanf("%d", &m);
    for (int j = 0, j_END_ = m; j < j_END_; ++j) {
      int x;
      scanf("%d", &x);
      --x;
      bpt.g[i][x] = true;
    }
  }
  sum = 0;
  for (int i = 0, i_END_ = n; i < i_END_; ++i) {
    scanf("%d", &cost[i]);
    cost[i] = -cost[i];
    if (cost[i] > 0) sum += cost[i];
  }
}
int main() {
  input();
  bpt.Hungary();
  bpt.build();
  printf("%d\n", -(sum - nw.Dinic()));
  return 0;
}
