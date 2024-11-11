#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 * 100 + 7, lg = 29;
int n, q, par[maxn][lg], child[maxn], d[maxn];
vector<int> adj[maxn];
void dfs(int u, int p) {
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (p == v) continue;
    par[v][0] = u;
    for (int j = 1; j < lg; j++) {
      par[v][j] = par[par[v][j - 1]][j - 1];
    }
    d[v] = d[u] + 1;
    dfs(v, u);
    child[u] = child[u] + child[v] + 1;
  }
}
int dad(int u, int k) {
  for (int i = lg - 1; i >= 0; i--)
    if ((k & (1 << i)) == (1 << i)) {
      u = par[u][i];
    }
  return u;
}
int LCA(int a, int b) {
  if (d[a] < d[b]) swap(a, b);
  a = dad(a, d[a] - d[b]);
  if (a == b) return b;
  for (int i = lg - 1; i >= 0; i--)
    if (par[a][i] != par[b][i]) {
      a = par[a][i];
      b = par[b][i];
    }
  return par[a][0];
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, -1);
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    int lca = LCA(a, b);
    int D1 = d[a] - d[lca], D2 = d[b] - d[lca];
    int dis = D1 + D2;
    if (a == b)
      cout << n << endl;
    else if (dis % 2)
      cout << 0 << endl;
    else if (D1 == D2) {
      int pa = dad(a, D1 - 1), pbb = dad(b, D2 - 1);
      cout << n - (child[pa] + child[pbb] + 2) << endl;
    } else {
      if (D1 < D2) swap(a, b);
      int pa = dad(a, (dis / 2) - 1), paa = par[pa][0];
      cout << child[paa] - child[pa] << endl;
    }
  }
  return 0;
}
