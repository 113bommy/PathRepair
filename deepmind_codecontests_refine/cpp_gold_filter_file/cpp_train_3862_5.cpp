#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int n, q;
int p[200010];
int val[200010];
int pos[200010];
vector<int> G[200010];
int root = 0;
int parent[20][200010];
int depth[200010];
void dfs(int v, int p, int d) {
  parent[0][v] = p;
  depth[v] = d;
  for (int i = 0; i < G[v].size(); i++) {
    if (G[v][i] != p) dfs(G[v][i], v, d + 1);
  }
}
void init(int V) {
  dfs(root, -1, 0);
  for (int k = 0; k + 1 < 20; k++) {
    for (int v = 0; v < V; v++) {
      if (parent[k][v] < 0)
        parent[k + 1][v] = -1;
      else
        parent[k + 1][v] = parent[k][parent[k][v]];
    }
  }
}
int lca(int u, int v) {
  if (depth[u] > depth[v]) swap(u, v);
  for (int k = 0; k < 20; k++) {
    if ((depth[v] - depth[u]) >> k & 1) {
      v = parent[k][v];
    }
  }
  if (u == v) return u;
  for (int k = 19; k >= 0; k--) {
    if (parent[k][u] != parent[k][v]) {
      u = parent[k][u];
      v = parent[k][v];
    }
  }
  return parent[0][u];
}
void rec(int cur, int &lev) {
  val[cur] = lev;
  for (int nxt : G[cur]) {
    if (depth[nxt] < depth[cur]) continue;
    lev++;
    rec(nxt, lev);
  }
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  cin >> n >> q;
  for (int i = 0; i < n - 1; i++) {
    cin >> p[i];
    p[i]--;
    G[p[i]].emplace_back(i + 1);
    G[i + 1].emplace_back(p[i]);
  }
  init(n);
  int lev = 1;
  rec(0, lev);
  for (int i = 0; i < n; i++) {
    pos[val[i]] = i + 1;
  }
  for (int i = 0; i < q; i++) {
    int u, k;
    cin >> u >> k;
    if (u == 1)
      cout << pos[k] << endl;
    else {
      int a = val[u - 1] + k - 1;
      cout << (a > n || lca(u - 1, pos[a] - 1) != u - 1 ? -1 : pos[a]) << endl;
    }
  }
  return 0;
}
