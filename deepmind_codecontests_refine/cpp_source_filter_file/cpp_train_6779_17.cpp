#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
long long dp[300000 + 10][4];
vector<int> edge[300000 + 10];
long long g[4];
void dfs(int rt, int first) {
  dp[rt][0] = 1;
  for (auto i : edge[rt]) {
    if (i == first) continue;
    dfs(i, rt);
    g[0] = dp[rt][0] * (dp[i][0] + dp[i][2]) % mod;
    g[1] = (dp[rt][1] * (dp[rt][0] + 2 * dp[i][2]) % mod +
            dp[rt][0] * dp[i][2] % mod) %
           mod;
    g[2] = (dp[rt][0] * (dp[i][0] + dp[i][1]) % mod +
            dp[rt][1] * (dp[i][0] + dp[i][1]) % mod +
            dp[rt][2] * (dp[i][0] + 2 * dp[i][2])) %
           mod;
    swap(g, dp[rt]);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = (1); i < (n); i++) {
    int u, v;
    cin >> u >> v;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dfs(1, 0);
  cout << (dp[1][0] + dp[1][2]) % mod;
  return 0;
}
