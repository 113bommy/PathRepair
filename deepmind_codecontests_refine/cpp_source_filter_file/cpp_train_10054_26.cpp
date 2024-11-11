#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
const long long INF = 1e18;
const double Pi = acos(-1.0);
const int N = 1e6 + 10, M = 2e6 + 10, mod = 1e9 + 7, inf = 2e9;
void update(long long &x, const long long &y) {
  if (x < y) x = y;
}
long long a[3][N], dp[5][N];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 3; ++i)
    for (int j = 1; j <= n; ++j) scanf("%I64d", &a[i][j]);
  for (int i = 0; i < 5; ++i)
    for (int j = 1; j <= n; ++j) dp[i][j] = -INF;
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    update(dp[0][i], dp[0][i - 1] + a[0][i]);
    update(dp[0][i], dp[1][i - 1] + a[0][i] + a[1][i]);
    update(dp[0][i], dp[2][i - 1] + a[0][i] + a[1][i] + a[2][i]);
    update(dp[0][i], dp[4][i - 1] + a[0][i] + a[1][i] + a[2][i]);
    update(dp[1][i], dp[1][i - 1] + a[1][i]);
    update(dp[1][i], dp[0][i - 1] + a[0][i] + a[1][i]);
    update(dp[1][i], dp[2][i - 1] + a[1][i] + a[2][i]);
    update(dp[2][i], dp[2][i - 1] + a[2][i]);
    update(dp[2][i], dp[1][i - 1] + a[2][i] + a[1][i]);
    update(dp[2][i], dp[0][i - 1] + a[0][i] + a[1][i] + a[2][i]);
    update(dp[2][i], dp[3][i - 1] + a[0][i] + a[1][i] + a[2][i]);
    update(dp[3][i], dp[0][i - 1] + a[0][i] + a[1][i] + a[2][i]);
    update(dp[4][i], dp[2][i - 1] + a[0][i] + a[1][i] + a[2][i]);
  }
  printf("%I64d\n", dp[2][n]);
  return 0;
}
