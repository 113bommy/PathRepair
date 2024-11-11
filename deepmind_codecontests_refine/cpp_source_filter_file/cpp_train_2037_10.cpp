#include <bits/stdc++.h>
using namespace std;
const int N = 105, K = 100;
long long dp[N][K];
long long old[K];
int n, k;
vector<int> G[N];
const long long MOD = 1e9 + 7;
bool vis[N];
void dfs(int v, int fa) {
  if (G[v].size() == 1 && fa != -1) {
    dp[v][0] = 1;
    dp[v][k + 1] = 1;
    return;
  }
  int flag = 0;
  for (int i = 0; i < G[v].size(); i++) {
    int t = G[v][i];
    if (t == fa) continue;
    dfs(t, v);
    if (flag == 0) {
      for (int i = 0; i <= 2 * k + 1; i++) {
        dp[v][i + 1] = dp[t][i];
      }
      flag = 1;
    } else {
      for (int i = 0; i <= 2 * k + 1; i++) {
        old[i] = dp[v][i];
        dp[v][i] = 0;
      }
      for (int i = 0; i <= 2 * k; i++) {
        for (int j = 1; j <= 2 * k + 1; j++) {
          if (i + j < 2 * k) {
            dp[v][min(j, i + 1)] += old[j] * dp[t][i];
            dp[v][min(j, i + 1)] %= MOD;
          } else {
            dp[v][max(j, i + 1)] += old[j] * dp[t][i];
            dp[v][max(j, i + 1)] %= MOD;
          }
        }
      }
    }
  }
  for (int i = 1; i <= 2 * k + 1; i++) {
    dp[v][0] += dp[v][i];
    dp[v][0] %= MOD;
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  memset(dp, 0, sizeof(dp));
  dfs(1, -1);
  long long ans = 0;
  for (int i = 0; i <= k + 1; i++) {
    ans += dp[1][i];
    ans %= MOD;
  }
  if (ans == 0) ans = 1;
  cout << ans << endl;
  return 0;
}
