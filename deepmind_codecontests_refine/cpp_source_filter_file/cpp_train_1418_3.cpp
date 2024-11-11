#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, MOD = 1e9 + 7;
int m, k, x;
vector<int> G[N];
long long dp[N][12][3];
int sz[N];
void dfs(int x, int p = 0) {
  dp[x][0][0] = k - 1;
  dp[x][1][1] = 1;
  dp[x][0][2] = m - k;
  sz[x] = 1;
  for (int u : G[x]) {
    if (p == u) continue;
    dfs(u, x);
    long long tmp[12][3];
    memset(tmp, 0, sizeof(tmp));
    sz[x] += sz[u];
    for (int i = 0; i <= min(x, sz[u]); ++i) {
      for (int j = 0; j + i <= min(x, sz[x]); ++j) {
        (tmp[i + j][0] += (dp[u][i][0] + dp[u][i][1] + dp[u][i][2]) % MOD *
                          dp[x][j][0] % MOD) %= MOD;
        (tmp[i + j][1] += (dp[u][i][0]) % MOD * dp[x][j][1] % MOD) %= MOD;
        (tmp[i + j][2] +=
         (dp[u][i][0] + dp[u][i][2]) % MOD * dp[x][j][2] % MOD) %= MOD;
      }
    }
    for (int i = 0; i <= min(x, sz[x]); ++i) {
      dp[x][i][0] = tmp[i][0];
      dp[x][i][1] = tmp[i][1];
      dp[x][i][2] = tmp[i][2];
    }
  }
}
int main() {
  int n;
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  scanf("%d%d", &k, &x);
  dfs(1);
  long long ans = 0;
  for (int i = 0; i <= x; ++i)
    (ans += (dp[1][i][0] + dp[1][i][1] + dp[1][i][2]) % MOD) %= MOD;
  cout << ans << endl;
}
