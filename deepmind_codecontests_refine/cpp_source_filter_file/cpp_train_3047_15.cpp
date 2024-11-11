#include <bits/stdc++.h>
using namespace std;
long long dp[1000010][4];
int a[1000010];
int n, t1, t2, t3, d;
void mind(long long &a, long long val) { a = min(a, val); }
int main() {
  scanf("%d%d%d%d%d", &n, &t1, &t2, &t3, &d);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  memset(dp, 0x3f, sizeof(dp));
  dp[1][0] = 0;
  for (int i = 1; i < n; ++i) {
    mind(dp[i + 1][1], dp[i][0] + 1ll * t1 * (a[i] + 1) + d);
    mind(dp[i + 1][1], dp[i][0] + t2 + d);
    mind(dp[i + 1][0], dp[i][0] + 1ll * t1 * a[i] + t3 + d);
    mind(dp[i + 1][0], dp[i][1] + 1ll * t1 * (a[i] + 1) + d + t1 + d + t1 + d);
    mind(dp[i + 1][0], dp[i][1] + t2 + d + t1 + d + t1 + d);
    mind(dp[i + 1][0], dp[i][1] + 1ll * t1 * a[i] + t3 + d + t1 + d + d);
  }
  long long ans = 0x3f3f3f3f3f3f3f3f;
  mind(ans, dp[n][0] + 1ll * a[n] * t1 + t3);
  mind(ans, dp[n][0] + t2 + d + d + t1);
  mind(ans, dp[n][0] + 1ll * a[n] * t1 + d + d + t1);
  mind(ans, dp[n][1] + 1ll * a[n] * t1 + t1 + d + t1 + d + t1);
  mind(ans, dp[n][1] + 1ll * a[n] * t1 + t3 + d + t1);
  mind(ans, dp[n][1] + t2 + d + t1 + d + t1);
  cout << ans;
  return 0;
}
