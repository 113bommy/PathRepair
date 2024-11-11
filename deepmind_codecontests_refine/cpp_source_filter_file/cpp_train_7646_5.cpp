#include <bits/stdc++.h>
using namespace std;
const int N = 2000 + 10;
int h[N], mn[N], cnt[N], dp[N];
vector<int> adj[N], adj_c[N];
bitset<N> mark, B;
void dfs1(int u, int l) {
  mn[u] = h[u] = l, mark[u] = true;
  for (auto v : adj[u]) {
    if (!mark[v]) dfs1(v, l + 1);
    if (h[v] - h[u] + 1) mn[u] = min(mn[u], h[v]);
  }
}
void dfs2(int u, int c) {
  static int col = 0;
  cnt[c]++, mark[u] = true;
  for (auto v : adj[u])
    if (!mark[v])
      if (mn[v] <= h[u])
        dfs2(v, c);
      else
        adj_c[c].push_back(++col), adj_c[col].push_back(c), dfs2(v, col);
}
int dfs3(int u, int par) {
  int ans = dp[u] = 0;
  for (auto v : adj_c[u])
    if (v != par) ans += dfs3(v, u), dp[u] += dp[v];
  ans += (dp[u] += cnt[u]) * cnt[u];
  return ans;
}
int main() {
  ios_base ::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int ans = 0;
  dfs1(0, 0), mark.reset(), dfs2(0, 0);
  for (int u = 0; cnt[u]; u++) {
    int res = dfs3(u, -1);
    B.reset(), B[0] = true;
    for (auto v : adj_c[u]) B |= B << dp[v];
    for (int i = 0; i < n; i++)
      if (B[i]) ans = max(ans, res + i * (n - cnt[u] - i));
  }
  cout << ans << endl;
  return 0;
}
