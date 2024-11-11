#include <bits/stdc++.h>
using namespace std;
int t[4001], d[4001];
int dp[4002][4002];
int n, k, res;
void solve() {
  for (int i = 0; i < n; ++i) {
    int next = t[i];
    for (int j = k; j >= 0; --j) {
      res = max(res, next - dp[i][j] - (dp[i][j] == 0));
      dp[i + 1][j] = t[i] >= dp[i][j] ? t[i] + d[i] : dp[i][j] + d[i];
      if (j < k) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
    }
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d%d", &t[i], &d[i]);
  t[n] = 84601;
  d[n] = 0;
  ++n;
  solve();
  printf("%d\n", res);
  return 0;
}
