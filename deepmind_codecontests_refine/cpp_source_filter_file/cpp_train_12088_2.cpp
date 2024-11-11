#include <bits/stdc++.h>
using namespace std;
const int maxn = 100050;
const int inf = 0x3f3f3f3f;
struct Edge {
  int v, w;
};
vector<Edge> G[maxn];
bool vis[maxn];
vector<int> st;
int dep[maxn], f[maxn][20];
long long dis[maxn];
void dfs(int x, int par, long long sum) {
  f[x][0] = par;
  dep[x] = dep[par] + 1;
  dis[x] = sum;
  vis[x] = true;
  for (int i = 1; f[x][i - 1]; ++i) f[x][i] = f[f[x][i - 1]][i - 1];
  for (auto e : G[x]) {
    int v = e.v;
    if (v != par && vis[v]) {
      st.push_back(v), st.push_back(x);
    }
    if (v != par && !vis[v]) dfs(v, x, sum + e.w);
  }
}
int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  int h = dep[x] - dep[y];
  for (int i = 0; h; ++i) {
    if (h & (1 << i)) {
      x = f[x][i];
      h ^= (1 << i);
    }
  }
  if (x == y) return x;
  for (int i = 17; i >= 0; --i) {
    if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
  }
  return f[x][0];
}
long long Dis(int x, int y) {
  int z = lca(x, y);
  return dis[x] + dis[y] - dis[z] * 2;
}
struct Dijkstra {
  long long d[maxn];
  struct node {
    int x;
    long long d;
    node(int x = 0, int d = 0) : x(x), d(d) {}
    bool operator<(const node& t) const { return d > t.d; }
  };
  void run(int s) {
    memset(d, 0x3f, sizeof d);
    memset(vis, false, sizeof vis);
    priority_queue<node> q;
    q.push(node(s, 0)), d[s] = 0;
    while (!q.empty()) {
      node u = q.top();
      q.pop();
      if (vis[u.x]) continue;
      vis[u.x] = true;
      for (auto e : G[u.x]) {
        int v = e.v;
        if (!vis[v] && d[v] > u.d + e.w) {
          d[v] = u.d + e.w;
          q.push(node(v, d[v]));
        }
      }
    }
  }
} dij[50];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int x, y, w;
    scanf("%d%d%d", &x, &y, &w);
    G[x].push_back({y, w});
    G[y].push_back({x, w});
  }
  dfs(1, 0, 0);
  sort(st.begin(), st.end());
  int sz = unique(st.begin(), st.end()) - st.begin();
  while (st.size() > sz) st.pop_back();
  for (int i = 0; i < sz; ++i) {
    dij[i].run(st[i]);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int u, v;
    scanf("%d%d", &u, &v);
    long long ans = Dis(u, v);
    for (int i = 0; i < sz; ++i) ans = min(ans, dij[i].d[u] + dij[i].d[v]);
    printf("%lld\n", ans);
  }
  return 0;
}
