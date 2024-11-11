#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int n;
int a[4][MAXN];
long long dp[MAXN][5];
inline long long Max(long long a, long long b, long long c) {
  return max(a, max(b, c));
}
inline long long Max(long long a, long long b, long long c, long long d) {
  return max(max(a, b), max(c, d));
}
inline long long sum(int col, int op, int ed) {
  if (op > ed) swap(op, ed);
  long long res = 0;
  for (int i = op; i <= ed; i++) res += a[i][col];
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
  if (n == 1) {
    printf("%lld\n", sum(1, 1, 3));
    return 0;
  }
  memset(dp, 0xc0, sizeof(dp));
  dp[2][0] = sum(1, 1, 1);
  dp[2][1] = sum(1, 1, 2);
  dp[2][2] = sum(1, 1, 3);
  dp[2][3] = dp[2][4] = sum(1, 1, 3) + sum(2, 1, 3);
  for (int i = 3; i <= n; i++) {
    dp[i][0] =
        Max(dp[i - 1][0] + sum(i - 1, 1, 1), dp[i - 1][4],
            dp[i - 1][1] + sum(i - 1, 1, 2), dp[i - 1][2] + sum(i - 1, 1, 3));
    dp[i][1] =
        Max(dp[i - 1][1] + sum(i - 1, 2, 2), dp[i - 1][0] + sum(i - 1, 1, 2),
            dp[i - 1][2] + sum(i - 1, 2, 3));
    dp[i][2] =
        Max(dp[i - 1][2] + sum(i - 1, 3, 3), dp[i - 1][3],
            dp[i - 1][0] + sum(i - 1, 1, 3), dp[i - 1][1] + sum(i - 1, 2, 3));
    dp[i][3] = dp[i - 1][0] + sum(i, 1, 3) + sum(i - 1, 1, 3);
    dp[i][4] = dp[i - 1][2] + sum(i, 1, 3) + sum(i - 1, 1, 3);
  }
  long long ans = Max(dp[n][0] + sum(n, 1, 3), dp[n][1] + sum(n, 2, 3),
                      dp[n][2] + sum(n, 3, 3), dp[n][3]);
  printf("%lld\n", ans);
  return 0;
}
