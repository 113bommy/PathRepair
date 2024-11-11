#include <bits/stdc++.h>
using namespace std;
const int qq = 1e5 + 10;
const long long INF = 1e16;
long long dp[qq][4];
long long num[4][qq];
int n;
inline long long sum(int x, int l, int r) {
  if (l > r) swap(l, r);
  long long res = 0;
  for (int i = l; i <= r; ++i) res += num[i][x];
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 3; ++i)
    for (int j = 1; j <= n; ++j) scanf("%lld", &num[i][j]);
  for (int i(0); i <= n; ++i)
    for (int j(0); j < 4; ++j) dp[i][j] = -INF;
  dp[0][0] = 0;
  for (int i(0); i <= n; ++i)
    for (int j(0); j < 3; ++j) {
      for (int k(0); k < 3; ++k)
        dp[i][j] = max(dp[i][j], dp[i - 1][k] + sum(i, j, k));
      dp[i][0] = max(dp[i][0], dp[i - 1][3] + sum(i, 0, 2));
      dp[i][2] = max(dp[i][2], dp[i - 1][3] + sum(i, 0, 2));
      dp[i][3] = max(dp[i][3], max(dp[i - 1][0], dp[i - 1][2]) + sum(i, 0, 2));
    }
  printf("%lld\n", dp[n][2]);
  return 0;
}
