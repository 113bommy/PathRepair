#include <bits/stdc++.h>
using namespace std;
long long int d, n;
const long long int N = 2e3 + 1;
const long long int mod = 1e9 + 7;
vector<long long int> adj[N];
vector<long long int> a;
long long int dfs(long long int i, pair<long long int, long long int> min,
                  pair<long long int, long long int> max,
                  long long int p = -1) {
  long long int ans = 1;
  for (long long int j : adj[i]) {
    if (j == p) {
      continue;
    }
    pair<long long int, long long int> jj = {a[j], j};
    if (jj < min || jj > max) {
      continue;
    }
    long long int k = (dfs(j, min, max, i) + 1) % mod;
    ans = (ans * k) % mod;
  }
  return ans;
}
long long int dfs(long long int i) {
  return dfs(i, {a[i], i}, {a[i] + d + 1, -1});
}
void solve() {
  cin >> d >> n;
  a.resize(n + 1);
  for (long long int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (long long int i = 0; i < n - 1; ++i) {
    long long int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  long long int ans = 0;
  for (long long int i = 1; i <= n; ++i) {
    ans += dfs(i);
    ans %= mod;
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  ;
  return 0;
}
