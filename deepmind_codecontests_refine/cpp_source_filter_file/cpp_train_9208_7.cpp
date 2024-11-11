#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;
long long n, dp[2][MAXN];
vector<int> adj[MAXN];
void dfs(int v = 0) {
  dp[1][v] = 1;
  long long fard[2] = {1, 0}, zoj = 1;
  for (auto e : adj[v]) {
    dfs(e);
    long long local = dp[0][v];
    dp[0][v] = (dp[0][v] * (dp[0][e] + 1) + dp[1][v] * dp[1][e]) % MOD;
    dp[1][v] = (dp[1][v] * (dp[0][e] + 1) + local * dp[1][e]) % MOD;
    local = fard[1];
    fard[1] = (fard[1] + fard[0] * dp[1][e]) % MOD;
    fard[0] = (fard[0] + local * dp[1][e]) % MOD;
    zoj = (zoj + zoj * dp[0][e]);
  }
  dp[0][v] = (2 * dp[0][v] - fard[1] + MOD) % MOD;
  dp[1][v] = (2 * dp[1][v] - zoj + MOD) % MOD;
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int v;
    cin >> v;
    adj[--v].push_back(i);
  }
  dfs();
  cout << (dp[0][0] + dp[1][0]) % MOD << '\n';
  return 0;
}
