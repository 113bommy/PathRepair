#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
const long long MOD = 998244353;
const double EPS = 1e-8;
const double PI = acos(-1.0);
const int N = 2e5 + 5;
vector<vector<int>> adj(N);
vector<int> dp(N), subs(N);
void dfs(int u, int p = -1) {
  for (int v : adj[u]) {
    if (p != v) {
      dp[v] = dp[u] + 1;
      dfs(v, u);
      subs[u] += subs[v];
    }
  }
  subs[u]++;
}
void solve() {
  int n, k;
  cin >> n >> k;
  for (long long i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1);
  int64_t ans = 0;
  vector<int64_t> vals;
  for (int i = 1; i <= n; ++i) {
    vals.push_back(dp[i] - (subs[i] - 1));
  }
  sort(vals.rbegin(), vals.rend());
  for (int i = 0; i < k; ++i) ans += vals[i];
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
