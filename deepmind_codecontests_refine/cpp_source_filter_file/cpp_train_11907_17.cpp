#include <bits/stdc++.h>
using namespace std;
long long int Pow(long long int a, long long int b, long long int md,
                  long long int ans = 1) {
  for (; b; b >>= 1, a = a * a % md)
    if (b & 1) ans = ans * a % md;
  return ans % md;
}
const long long int MAXN = 3e3 + 10;
const long long int INF = 8e18;
const long long int MOD = 1e9 + 7;
long long int A[MAXN], n, m;
double ans = 0, dp[MAXN][MAXN];
int main() {
  scanf("%lld%lld", &n, &m);
  for (long long int i = 1; i <= n; i++) scanf("%lld", &A[i]);
  for (long long int i = 1; i <= n; i++)
    for (long long int j = 1; j <= n; j++)
      if (A[i] > A[j]) dp[i][j] = 1.0;
  for (long long int i = 1; i <= m; i++) {
    long long int x, y;
    scanf("%lld%lld", &x, &y);
    dp[x][y] = dp[y][x] = (dp[x][y] + dp[y][x]) / 2.0;
    for (long long int j = 1; j <= n; j++)
      if (j != x && j != y) {
        dp[x][j] = dp[y][j] = (dp[x][j] + dp[y][j]) / 2.0;
        dp[j][x] = dp[j][y] = (dp[j][x] + dp[j][y]) / 2.0;
      }
  }
  for (long long int i = 1; i <= n; i++)
    for (long long int j = 1; j < i; j++) ans += dp[i][j];
  printf("%.15f\n", ans);
  return 0;
}
