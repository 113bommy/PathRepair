#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,fast-math")
using namespace std;
long long poww(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
const int maxn = 3000 * 100 + 5;
const long long inf = 9223372036854775807;
const long long mod = 998244353;
const int lg = 20;
long long n, dp[3][maxn], par[maxn], pd[3];
vector<int> adj[maxn];
void dfs(int v) {
  dp[0][v] = 1;
  dp[2][v] = 1;
  for (auto u : adj[v]) {
    if (u != par[v]) {
      par[u] = v;
      dfs(u);
      pd[0] = dp[0][v];
      pd[1] = dp[1][v];
      pd[2] = dp[2][v];
      dp[0][v] = pd[0] * (dp[0][u] + dp[1][u]) % mod;
      dp[0][v] %= mod;
      dp[1][v] = pd[1] * (dp[0][u] + dp[1][u]) % mod;
      dp[1][v] %= mod;
      dp[2][v] = pd[2] * (dp[0][u] + dp[1][u]) % mod;
      dp[2][v] %= mod;
      dp[1][v] += pd[2] * dp[2][u] % mod + pd[1] * dp[1][u] % mod;
      dp[1][v] %= mod;
      dp[2][v] += pd[2] * dp[1][u] % mod;
      dp[2][v] %= mod;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  int u, v;
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1);
  cout << (dp[1][1] + dp[0][1]) % mod << endl;
}
