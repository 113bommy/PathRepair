#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 10, md = 1e9 + 7;
vector<long long> child[MAXN];
long long dp[2][MAXN], dp1[2][MAXN], dp2[2][2][MAXN];
void dfs(long long v) {
  long long s = child[v].size();
  for (long long i = 0; i < s; ++i) {
    long long now = child[v][i];
    dfs(now);
    if (!i) {
      dp1[0][now] = dp[0][now] + 1;
      dp1[1][now] = dp[1][now];
      dp2[1][0][now] = dp2[0][0][now] = 1;
      dp2[0][0][now] += dp[0][now];
      dp2[1][1][now] = dp[1][now];
      continue;
    }
    long long p = child[v][i - 1];
    dp1[0][now] = (dp1[0][p] * (dp[0][now] + 1) + dp1[1][p] * dp[1][now]) % md;
    dp1[1][now] = (dp1[0][p] * dp[1][now] + dp1[1][p] * (dp[0][now] + 1)) % md;
    dp2[0][0][now] = dp2[0][0][p] * (1 + dp[0][now]) % md;
    dp2[1][0][now] = (dp2[1][1][p] * dp[1][now] + dp2[1][0][p]) % md;
    dp2[1][1][now] = (dp2[1][0][p] * dp[1][now] + dp2[1][1][p]) % md;
  }
  if (child[v].empty()) {
    dp[1][v] = 1;
    return;
  }
  long long k = child[v].back();
  dp[1][v] = 2 * dp1[0][k] - dp2[0][0][k];
  dp[1][v] = (dp[1][v] + md * 10) % md;
  dp[0][v] = 2 * dp1[1][k] - dp2[1][1][k];
  dp[0][v] = (dp[0][v] + md * 10) % md;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long n, a1;
  cin >> n;
  for (long long i = 2; i <= n; ++i) {
    cin >> a1;
    child[a1].push_back(i);
  }
  dfs(1);
  cout << dp[0][1] + dp[1][1];
  return 0;
}
