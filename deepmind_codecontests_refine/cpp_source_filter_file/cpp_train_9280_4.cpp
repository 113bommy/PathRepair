#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10, MOD = 1e9 + 7;
int n, par[MAXN];
long long dp[MAXN][3];
vector<int> adj[MAXN];
void dfs(int u) {
  if (adj[u].size())
    dp[u][0] = 1, dp[u][1] = dp[u][2] = 0;
  else
    dp[u][0] = 0, dp[u][1] = dp[u][2] = 1;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    dfs(v);
    long long x[3] = {dp[u][0], dp[u][1], dp[u][2]};
    dp[u][0] = (dp[v][0] + dp[v][2]) % MOD * x[0] % MOD;
    dp[u][1] = (dp[v][1] * x[0] % MOD +
                x[1] * (dp[v][0] + dp[v][1] + dp[v][2]) % MOD) %
               MOD;
    dp[u][2] =
        (dp[v][1] * x[1] % MOD + (dp[v][0] + dp[v][2]) % MOD * x[2] % MOD) %
        MOD;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> par[i], par[i]--;
    adj[par[i]].push_back(i);
  }
  dfs(0);
  dp[0][0] += dp[0][2], dp[0][0] %= MOD;
  cout << dp[0][0];
  return 0;
}
