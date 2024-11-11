#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3e5 + 10;
const long long mod = 998244353;
vector<long long> G[maxn];
long long n, dp[maxn][3], g[3];
void dfs(long long u, long long p) {
  dp[u][0] = 1;
  for (long long v : G[u])
    if (v != p) {
      dfs(v, u);
      g[0] = 1ll * dp[u][0] * (dp[v][0] + dp[v][2]) % mod;
      g[1] =
          (1ll * dp[u][0] * dp[v][2] + (dp[v][0] + 2ll * dp[v][2]) * dp[u][1]) %
          mod;
      g[2] = (1ll * (dp[u][0] + dp[u][1]) * (dp[v][0] + dp[v][1]) +
              (dp[v][0] + 2ll * dp[v][2]) * dp[u][2]) %
             mod;
      memcpy(dp[u], g, sizeof g);
    }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, q, u, v;
  cin >> n;
  q = n;
  while (--q) cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
  dfs(1, 0);
  cout << dp[1][0] + dp[1][2];
  return 0;
}
