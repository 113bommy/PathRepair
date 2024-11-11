#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
constexpr int MX = 2e5 + 5;
int t[MX], h[MX], in[MX], out[MX];
ll ans, dp[MX][2];
bitset<MX> vis;
vector<int> G[MX];
void dfs(int u, int p) {
  vis[u] = 1;
  ll sum = 0;
  vector<ll> ch;
  for (int v : G[u])
    if (!vis[v]) {
      dfs(v, u);
      sum += dp[v][1];
      ch.push_back(dp[v][0] - dp[v][1]);
    }
  int l = ch.size();
  sort(begin(ch), end(ch)), reverse(begin(ch), end(ch));
  for (int i = 0; i <= l; ++i) {
    for (int b : {0, 1})
      dp[u][b] = max(
          (ll)min(in[u] + !b * !!p + l - i, out[u] + b * !!p + i) * t[u] + sum,
          dp[u][b]);
    if (i < l) sum += ch[i];
  }
}
int main() {
  if (fopen("in", "r")) freopen("in", "r", stdin), freopen("out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> t[i];
  for (int i = 1; i <= n; ++i) cin >> h[i];
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    ans += t[u] + t[v];
    if (h[u] == h[v])
      G[u].push_back(v), G[v].push_back(u);
    else {
      if (h[u] > h[v]) swap(u, v);
      ++in[u], ++out[v];
    }
  }
  for (int u = 1; u <= n; ++u)
    if (!vis[u]) dfs(u, 0), ans -= max(dp[u][0], dp[u][1]);
  cout << ans;
}
