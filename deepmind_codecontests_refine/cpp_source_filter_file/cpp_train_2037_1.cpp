#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 5;
const int MOD = (int)1e9 + 7;
int n, K;
long long dp[N][N], tdp[N][N];
vector<int> G[N];
void show(int o) {
  for (int i = 0; i <= 2 * K; i++) {
    printf("dp[%d][%d] = %I64d\n", o, i, dp[o][i]);
  }
}
void dfs(int o, int f) {
  if ((int)G[o].size() == 1 && G[o][0] == f) {
    dp[o][0] = 1;
    dp[o][K + 1] = 1;
    return;
  }
  int flag = 1;
  for (int i = 0; i < (int)G[o].size(); i++) {
    int v = G[o][i];
    if (v == f) continue;
    dfs(v, o);
    if (flag) {
      for (int j = 1; j <= 2 * K + 1; j++) {
        dp[o][j] = dp[v][j - 1];
      }
      flag = 0;
    } else {
      for (int j = 1; j <= 2 * K + 1; j++) {
        tdp[o][j] = dp[o][j];
        dp[o][j] = 0;
      }
      for (int j = 1; j <= 2 * K + 1; j++) {
        for (int k = 0; k <= 2 * K; k++) {
          if (j + k <= 2 * K) {
            dp[o][min(j, k + 1)] += (tdp[o][j] * dp[v][k]) % MOD;
            dp[o][min(j, k + 1)] %= MOD;
          } else {
            dp[o][min(j, k + 1)] += (tdp[o][j] * dp[v][k]) % MOD;
            dp[o][min(j, k + 1)] %= MOD;
          }
        }
      }
    }
  }
  for (int j = 1; j <= 2 * K + 1; j++) {
    dp[o][0] += dp[o][j];
    dp[o][0] %= MOD;
  }
  return;
}
long long solve() {
  if (n == 1) return 1;
  dfs(1, 0);
  long long ans = 0;
  for (int i = 0; i <= K; i++) {
    ans += dp[1][i];
    ans %= MOD;
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &K);
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  printf("%I64d\n", solve());
}
