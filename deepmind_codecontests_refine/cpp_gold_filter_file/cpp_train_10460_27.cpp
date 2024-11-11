#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int MAX = 1e5 + 5;
int n;
vector<int> adj[MAX];
int anc[MAX][20];
int d[MAX], paths[MAX], ans = 0, childs[MAX];
void dfs(int v = 1, int par = 0) {
  childs[par]++;
  anc[v][0] = par;
  for (int i = 1; i < 20; i++) anc[v][i] = anc[anc[v][i - 1]][i - 1];
  for (int u : adj[v]) {
    if (u - par) {
      d[u] = d[v] + 1;
      dfs(u, v);
    }
  }
  childs[par] += childs[v];
}
int lca(int u, int v) {
  if (d[u] < d[v]) swap(u, v);
  for (int i = 19; ~i; i--)
    if (d[u] - (1 << i) >= d[v]) u = anc[u][i];
  if (u == v) return u;
  for (int i = 19; ~i; i--)
    if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
  return anc[u][0];
}
int climb(int u, int d) {
  for (int i = 0; i < 20; i++)
    if (d >> i & 1) u = anc[u][i];
  return u;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  int u, v;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  d[1] = 1;
  dfs(1, 0);
  for (int i = 1; i <= n; i++) ++childs[i];
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> u >> v;
    int w = lca(u, v);
    int dis = d[u] + d[v] - 2 * d[w];
    if (dis % 2) {
      cout << 0 << "\n";
      continue;
    }
    dis >>= 1;
    if (d[u] < d[v]) swap(u, v);
    int x = climb(u, dis);
    if (d[u] == d[v]) {
      u = climb(u, dis - 1);
      v = climb(v, dis - 1);
      cout << abs(n - childs[u] - childs[v]) << "\n";
    } else {
      u = climb(u, dis - 1);
      cout << abs(childs[x] - childs[u]) << "\n";
    }
  }
}
