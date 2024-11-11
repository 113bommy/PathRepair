#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int u, v, w, id;
  Edge() {}
  Edge(int U, int V, int W, int ID) : u(U), v(V), w(W), id(ID) {}
  bool operator<(const Edge &e) const { return w < e.w; }
};
class UnionFind {
  vector<int> a;

 public:
  UnionFind() {}
  UnionFind(int n) : a(n, -1) {}
  int find(int x) {
    if (a[x] < 0) return x;
    return a[x] = find(a[x]);
  }
  void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) {
      a[x] += a[y];
      a[y] = x;
    }
  }
  int size(int x) { return -a[find(x)]; }
};
UnionFind uf;
vector<Edge> adj[100000];
int i_now;
int dp[200000], i_dp[200000];
int dfs(int u, int prev, int id) {
  if (i_dp[id] == i_now) return dp[id];
  int res = uf.size(u);
  for (int i = 0; i < (adj[u].size()); i++) {
    int v = adj[u][i].v, id2 = adj[u][i].id;
    if (v != prev) res += dfs(v, u, id2);
  }
  i_dp[id] = i_now;
  return dp[id] = res;
}
int main() {
  int n;
  scanf("%d", &n);
  uf = UnionFind(n);
  static Edge E[100000];
  for (int i = 0; i < (n - 1); i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    u--;
    v--;
    E[i] = Edge(u, v, w, i);
    i_dp[i] = i_dp[i + n] = -1;
  }
  sort(E, E + n - 1);
  static long long res[100000];
  for (int i = 0; i < n - 1;) {
    vector<Edge> E2;
    for (int i0 = i; i < n - 1; i++) {
      if (i == i0 || E[i - 1].w == E[i].w) {
        E2.push_back(E[i]);
        int u = uf.find(E[i].u), v = uf.find(E[i].v), id = E[i].id;
        adj[u].push_back(Edge(u, v, -1, id));
        adj[v].push_back(Edge(v, u, -1, id + n));
      } else
        break;
    }
    i_now = i;
    for (int j = 0; j < (E2.size()); j++) {
      int u = uf.find(E2[j].u), v = uf.find(E2[j].v), id = E2[j].id;
      res[id] = 2LL * dfs(u, v, id) * dfs(v, u, id + n);
    }
    for (int j = 0; j < (E2.size()); j++) {
      uf.unite(E2[j].u, E2[j].v);
      int u = uf.find(E2[j].u), v = uf.find(E2[j].v);
      adj[u].clear();
      adj[v].clear();
    }
  }
  long long ans = *max_element(res, res + n - 1);
  printf("%I64d %d\n", ans, count(res, res + n - 1, ans));
  for (int i = 0; i < (n - 1); i++)
    if (res[i] == ans) printf("%d\n", i + 1);
  return 0;
}
