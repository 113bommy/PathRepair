#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long maxn = 3e5 + 10;
const long long mod = 998244353;
long long pw(long long a, long long b, long long md = mod) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = (a * res) % md;
    }
    a = (a * a) % md;
    b >>= 1;
  }
  return (res);
}
long long n;
vector<long long> adj[maxn];
long long dp[maxn][3], mrg[3];
void dfs(long long v = 1, long long par = 0) {
  dp[v][0] = 1;
  for (auto u : adj[v])
    if (u ^ par) {
      dfs(u, v);
      mrg[0] = 1LL * dp[v][0] * ((0LL + dp[u][0] + dp[u][2]) % mod) % mod;
      mrg[1] =
          (1LL * dp[v][0] * dp[u][2] % mod +
           1LL * dp[v][1] * ((dp[u][0] + 2LL * dp[u][2] % mod) % mod) % mod) %
          mod;
      mrg[2] =
          (1LL * dp[v][0] * (dp[u][0] + dp[u][1]) % mod +
           1LL * dp[v][1] * (dp[u][0] + dp[u][1]) % mod +
           1LL * dp[v][2] * ((dp[u][0] + 2LL * dp[u][2] % mod) % mod) % mod) %
          mod;
      swap(dp[v], mrg);
    }
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (long long i = 1; i < n; i++) {
    long long u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs();
  cout << ((dp[1][0] + dp[1][2]) % mod);
  return (0);
}
