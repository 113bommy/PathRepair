#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 4, M = N, inf = (long long)1e9;
const long long mod = 1e9 + 7;
long long fastAbs(long long n) { return (n ^ (n >> 31)) - (n >> 31); }
long long multiply(long long a, long long b) {
  return ((a % mod) * (b % mod)) % mod;
}
long long add(long long a, long long b) {
  return ((a % mod) + (b % mod)) % mod;
}
long long sub(long long a, long long b) {
  return ((a % mod) - (b % mod) + mod) % mod;
}
const long long dx[4] = {1, 0, 0, -1};
const long long dy[4] = {0, -1, 1, 0};
const int nmax = 3e5 + 4;
int n;
vector<pair<int, long long> > edge[nmax];
vector<long long> w(nmax);
vector<long long> dp(nmax, -1);
long long ans = 0;
int dfs(int x, int p) {
  if (edge[x].size() == 0) {
    ans = max(ans, w[x]);
    return dp[x] = w[x];
  }
  if (edge[x].size() == 1 and x != 1) {
    ans = max(ans, w[x]);
    return dp[x] = w[x];
  }
  vector<long long> v;
  for (auto child : edge[x]) {
    if (child.first != p) {
      v.push_back(dfs(child.first, x) - child.second);
    }
  }
  sort(v.rbegin(), v.rend());
  if (v.size() >= 2) {
    ans = max(ans, v[0] + v[1] + w[x]);
  }
  dp[x] = max(w[x], v[0] + w[x]);
  ans = max(dp[x], ans);
  return dp[x];
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> w[i];
  for (int i = 0; i < n - 1; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    edge[u].push_back({v, c});
    edge[v].push_back({u, c});
  }
  dfs(1, -1);
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long q = 1;
  while (q--) solve();
}
