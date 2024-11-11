#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 2;
int n, cnt, vis[N << 2];
bool a[2][N][N], r[N];
vector<int> adj[N << 2], rev_adj[N << 2], ord, comp;
vector<pair<string, int>> ans;
string s;
void add_edge(int u, int v) {
  adj[u].push_back(v);
  rev_adj[v].push_back(u);
}
void add_clause(int x, int y) {
  add_edge(x ^ 1, y);
  add_edge(y ^ 1, x);
}
void dfs(int u, vector<int> *g, vector<int> &vec, int x = 1) {
  vis[u] = x;
  for (int v : g[u])
    if (vis[v] == 0) dfs(v, g, vec, x);
  vec.push_back(u);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int k : {0, 1})
    for (int i = 0; i < n; i++) {
      cin >> s;
      for (int j = 0; j < n; j++) a[k][i][j] = s[j] - '0';
    }
  cin >> s;
  for (int i = 0; i < n; i++) r[i] = s[i] - '0';
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if ((a[0][i][j] ^ r[j] ^ r[i]) != a[1][i][j])
        add_clause(i << 1 | 1, j + n << 1 | 1);
      if ((a[0][i][j] ^ r[j]) != a[1][i][j]) add_clause(i << 1 | 1, j + n << 1);
      if ((a[0][i][j] ^ r[i]) != a[1][i][j]) add_clause(n + j << 1 | 1, i << 1);
      if (a[0][i][j] != a[1][i][j]) add_clause(i << 1, j + n << 1);
    }
  for (int u = 0; u < n << 2; u++)
    if (vis[u] == 0) dfs(u, adj, ord);
  memset(vis, 0, sizeof vis);
  reverse(ord.begin(), ord.end());
  for (int u : ord)
    if (vis[u] == 0) dfs(u, rev_adj, comp, ++cnt);
  for (int u = 0; u < n << 1; u++)
    if (vis[u << 1] == vis[u << 1 | 1]) return cout << -1 << endl, 0;
  for (int u = 0; u < n << 1; u++)
    if (vis[u << 1] > vis[u << 1 | 1])
      ans.push_back({u < n ? "row" : "col", u < n ? u : u - n});
  cout << ans.size() << endl;
  for (auto [str, ind] : ans) cout << str << ' ' << ind << endl;
}
