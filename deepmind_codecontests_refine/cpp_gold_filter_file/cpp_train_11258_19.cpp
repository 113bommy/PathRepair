#include <bits/stdc++.h>
using namespace std;
long long W, sum, ans, cnt[10], dp[400100];
inline void Max(long long &u, long long v) {
  if (v > u) u = v;
}
int main() {
  memset(dp, -1, sizeof(dp));
  long long i, j, t;
  cin >> W;
  for (i = 1; i <= 8; i++) {
    scanf("%lld", &cnt[i]);
    sum += cnt[i] * i;
  }
  if (sum <= W) {
    cout << sum;
    return 0;
  }
  sum = 0;
  for (i = 1; i <= 8; i++) {
    t = min(cnt[i] - 1000, (W - sum - 300000 + 100) / i);
    if (t <= 0) continue;
    cnt[i] -= t;
    sum += t * i;
  }
  dp[0] = 0;
  for (i = 1; i <= 8; i++) {
    for (j = 0; j <= 300000; j++)
      if (dp[j] >= 0) dp[j] = cnt[i];
    for (j = 0; j + i <= 300000; j++) {
      if (dp[j] > 0) Max(dp[j + i], dp[j] - 1);
    }
  }
  for (i = 0; i + sum <= W; i++) {
    if (dp[i] >= 0) ans = max(ans, i + sum);
  }
  cout << ans;
}
