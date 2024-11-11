#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 6;
int m1, p, M, m2, vis[N << 2], n, cnt, f = -1;
vector<int> adj[N << 2], rev_adj[N << 2], ans, ord, comp;
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
  cin >> m1 >> p >> M >> m2;
  while (m1--) {
    int x, y;
    cin >> x >> y;
    add_clause(--x << 1, --y << 1);
  }
  n = p + M;
  for (int i = p; i < n - 1; i++) add_clause(i << 1, i + 1 << 1 | 1);
  for (int i = 0, l, r; i < p; i++) {
    cin >> l >> r;
    add_clause(i << 1 | 1, --l + p << 1);
    add_clause(i << 1 | 1, r + p << 1 | 1);
  }
  while (m2--) {
    int x, y;
    cin >> x >> y;
    add_clause(--x << 1 | 1, --y << 1 | 1);
  }
  for (int u = 0; u < n << 1; u++)
    if (vis[u] == 0) dfs(u, adj, ord);
  memset(vis, 0, sizeof vis);
  reverse(ord.begin(), ord.end());
  for (int u : ord)
    if (vis[u] == 0) dfs(u, rev_adj, comp, ++cnt);
  for (int u = 0; u < n; u++)
    if (vis[u << 1] == vis[u << 1 | 1]) return cout << -1 << endl, 0;
  for (int i = p; i < n && f == -1; i++)
    if (vis[i << 1] < vis[i << 1 | 1]) f = i - p;
  for (int i = 0; i < p; i++)
    if (vis[i << 1] > vis[i << 1 | 1]) ans.push_back(i);
  cout << ans.size() << ' ' << f << endl;
  for (int x : ans) cout << x + 1 << ' ';
  cout << endl;
}
