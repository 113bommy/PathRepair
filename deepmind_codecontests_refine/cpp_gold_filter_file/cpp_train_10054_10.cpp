#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const long long INF = 1e16;
int a[3][N], n;
long long dp[N][4];
inline long long sum(int x, int l, int r) {
  long long res = 0;
  if (l > r) swap(l, r);
  for (int i = l; i <= r; ++i) res += a[i][x];
  return res;
}
int main(void) {
  register int i, j, l;
  scanf("%d", &n);
  for (i = 0; i < 3; ++i)
    for (j = 1; j <= n; ++j) scanf("%d", &a[i][j]);
  for (i = 0; i < 4; ++i)
    for (j = 0; j <= n; ++j) dp[j][i] = -INF;
  dp[0][0] = 0;
  for (i = 1; i <= n; ++i) {
    for (j = 0; j < 3; ++j)
      for (l = 0; l < 3; ++l)
        dp[i][j] = max(dp[i][j], dp[i - 1][l] + sum(i, j, l));
    dp[i][0] = max(dp[i][0], dp[i - 1][3] + sum(i, 0, 2));
    dp[i][2] = max(dp[i][2], dp[i - 1][3] + sum(i, 0, 2));
    dp[i][3] = max(dp[i][3], max(dp[i - 1][0], dp[i - 1][2]) + sum(i, 0, 2));
  }
  printf("%lld", dp[n][2]);
  return 0;
}
