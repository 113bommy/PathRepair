#include <bits/stdc++.h>
using namespace std;
const int N = 210;
long long a[N], dp[N][N];
int main() {
  int n, x, ks;
  cin >> n >> ks >> x;
  if (ks * (x + 1) - 1 < n) {
    printf("-1");
    return 0;
  }
  for (int i = 2; i <= n + 1; i++) cin >> a[i];
  memset(dp, -0x3f, sizeof dp);
  dp[1][1] = 0;
  for (int i = 2; i <= n + 1; i++) {
    for (int k = 1; k <= min(i, x + 1); k++)
      for (int j = i - 1; j >= max(1, i - ks); j--)
        dp[i][k] = max(dp[i][k], dp[j][k - 1] + a[i]);
  }
  long long res = 0;
  for (int i = n; i > n - ks; i--) res = max(res, dp[i][x + 1]);
  printf("%lld", res);
  return 0;
}
