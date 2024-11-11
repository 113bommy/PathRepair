#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
using ll = long long;
using pii = pair<int, int>;
int pa[maxn];
int sz[maxn];
int d[maxn];
int f[maxn];
vector<ll> pre[maxn];
vector<int> g[maxn], dis[maxn];
map<pii, ll> ans;
int find(int p) { return p == pa[p] ? pa[p] : pa[p] = find(pa[p]); }
void unionPQ(int p, int q) {
  int pp = find(p);
  int pq = find(q);
  if (pp != pq) {
    pa[pp] = pq;
    sz[pq] += sz[pp];
  }
}
int depth, id, root, flag;
void dfs(int node, int fa = -1, int h = 0) {
  if (h > depth) {
    depth = h;
    id = node;
  }
  if (f[node] < h) f[node] = h;
  if (flag) dis[root].push_back(f[node]);
  for (auto v : g[node])
    if (v != fa) dfs(v, node, h + 1);
}
int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < n; ++i) {
    pa[i] = i;
    sz[i] = 1;
  }
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
    unionPQ(a, b);
  }
  for (int i = 0; i < n; ++i)
    if (i == pa[i]) {
      flag = false;
      root = i;
      depth = 0;
      id = i;
      dfs(i);
      depth = 0;
      dfs(id);
      d[i] = depth;
      flag = true;
      dfs(id);
      sort(dis[i].begin(), dis[i].end());
      pre[i].resize(1 + sz[i]);
      pre[i][0] = 0;
      for (int j = 0; j < sz[i]; ++j) pre[i][j + 1] = pre[i][j] + dis[i][j];
    }
  for (int i = 0; i < q; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;
    v--;
    u = find(u);
    v = find(v);
    if (u == v) {
      printf("-1\n");
      continue;
    }
    if (sz[u] > sz[v] || (sz[u] == sz[v] && u > v)) swap(u, v);
    if (ans.count({u, v})) {
      printf("%.10f\n", (double)ans[{u, v}] / sz[u] / sz[v]);
      continue;
    }
    int maxd = max(d[u], d[v]);
    ll t = 0;
    int p = sz[v] - 1;
    for (int x : dis[u]) {
      while (p >= 0 && x + 1 + dis[v][p] > maxd) p--;
      t += (ll)maxd * (p + 1) + (ll)(x + 1) * (sz[v] - p - 1) + pre[v].back() -
           pre[v][p + 1];
    }
    ans[{u, v}] = t;
    printf("%.10f\n", (double)ans[{u, v}] / sz[u] / sz[v]);
  }
  return 0;
}
