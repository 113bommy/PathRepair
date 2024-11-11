#include <bits/stdc++.h>
const int INF = 2147483647;
const int INF2 = 0x3f3f3f3f;
const long long INF64 = (long long)2e18;
const double INFD = 1e30;
const double EPS = 1e-9;
const double PI = std::acos(-1);
const int MOD = 1e9 + 7;
template <typename T>
inline T read() {
  T X = 0, w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  return w ? -X : X;
}
const int MAXN = 400005;
const int MAXV = 1 << 20;
int n, m, k;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {-1, 0, 1, 0};
int dr2[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dc2[8] = {1, 0, -1, 1, 0, -1, 1, -1};
int CASE = 1;
char S[MAXN];
struct Edge {
  int u, v;
  long long x;
};
std::vector<int> G[MAXN];
std::vector<Edge> edges;
int upEdge[MAXN];
int dep[MAXN];
int parent[MAXN][20];
int LOG2[MAXN];
struct UnionFind {
  int find(int u) { return fa[u] == u ? u : (fa[u] = find(fa[u])); }
  void join(int x, int y) {
    int a = find(x), b = find(y);
    if (a == b) return;
    fa[a] = b;
  }
  void clear(int n) {
    for (int i = 0; i < n; i++) fa[i] = i, up[i] = i;
  }
  int fa[MAXN];
  int up[MAXN];
};
UnionFind uf;
void dfs(int u, int p) {
  parent[u][0] = p;
  for (int i = 1; i < 20; i++) parent[u][i] = parent[parent[u][i - 1]][i - 1];
  for (auto i : G[u]) {
    Edge& e = edges[i];
    if (e.v == p) continue;
    upEdge[e.v] = i ^ 1;
    dep[e.v] = dep[u] + 1;
    dfs(e.v, u);
  }
}
int findLCA(int u, int v) {
  if (dep[u] < dep[v]) std::swap(u, v);
  while (dep[u] != dep[v]) {
    u = parent[u][LOG2[dep[u] - dep[v]]];
  }
  if (u == v) return u;
  for (int i = LOG2[dep[u]]; i >= 0; i--) {
    if (parent[u][i] != parent[v][i]) {
      u = parent[u][i];
      v = parent[v][i];
    }
  }
  return parent[u][0];
}
long long solve(int x, int y, long long v) {
  int lca = findLCA(x, y);
  while (dep[x] > dep[lca]) {
    int t = uf.find(x);
    x = uf.up[t];
    if (dep[x] <= dep[lca]) break;
    v /= edges[upEdge[x]].x;
    if (!v) return 0;
    x = parent[x][0];
  }
  while (dep[y] > dep[lca]) {
    int t = uf.find(y);
    y = uf.up[t];
    if (dep[y] <= dep[lca]) break;
    v /= edges[upEdge[y]].x;
    if (!v) return 0;
    y = parent[y][0];
  }
  return v;
}
int main() {
  scanf("%d%d", &n, &m);
  uf.clear(n * 2);
  for (int i = 2; i <= n; i <<= 1) LOG2[i]++;
  for (int i = 1; i <= n; i++) LOG2[i] += LOG2[i - 1];
  for (int i = 0; i < n - 1; i++) {
    int u = read<int>(), v = read<int>();
    long long x = read<long long>();
    edges.push_back({u, v, x});
    G[u].push_back(edges.size() - 1);
    edges.push_back({v, u, x});
    G[v].push_back(edges.size() - 1);
  }
  dep[1] = 1;
  dfs(1, 0);
  for (int i = 2; i <= n; i++) {
    Edge& e = edges[upEdge[i]];
    if (e.x == 1) {
      uf.join(e.u, e.v);
    }
  }
  for (int i = 0; i < m; i++) {
    int op;
    scanf("%d", &op);
    long long x, y;
    if (op == 1) {
      x = read<int>();
      y = read<int>();
      long long v = read<long long>();
      printf("%lld\n", solve(x, y, v));
    } else {
      x = read<int>();
      y = read<long long>();
      int id = x * 2 - 1;
      Edge e = edges[id];
      if (dep[e.v] > dep[e.u]) id--;
      edges[id].x = y;
      if (y == 1) {
        uf.join(edges[id].u, edges[id].v);
      }
    }
  }
  return 0;
}
