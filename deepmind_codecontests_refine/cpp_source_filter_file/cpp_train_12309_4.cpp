#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
const long long mod = 998244353;
vector<int> g[maxn];
long long dp[maxn][3], f[maxn];
void dfs(int cur, int fa) {
  dp[cur][0] = dp[cur][1] = f[cur] = 1;
  for (int i = 0; i < g[cur].size(); i++) {
    int v = g[cur][i];
    if (v == fa) continue;
    dfs(v, cur);
    dp[cur][0] =
        dp[cur][0] * ((2 * dp[v][0] + 2 * dp[v][1] - f[v]) % mod) % mod;
    dp[cur][1] = dp[cur][1] * ((2 * dp[v][0] + dp[v][1] - f[v]) % mod) % mod;
    f[cur] = f[cur] * ((dp[v][0] + dp[v][1] - f[v]) % mod) % mod;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  cout << (dp[1][0] + dp[1][1] - f[1] - 1 + mod) % mod;
  return 0;
}
