#include <bits/stdc++.h>
using namespace std;
const int MN = 10, M = 840;
long long cnt[MN], dp[MN][M + 5];
long long sum;
int main() {
  long long w;
  scanf("%lld", &w);
  for (int i = 1; i <= 8; ++i) {
    scanf("%d", &cnt[i]);
    sum += 1LL * i * cnt[i];
  }
  if (sum <= w) {
    printf("%lld\n", sum);
    return 0;
  }
  memset(dp, 0xff, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= 8; ++i)
    for (int j = 0; j < M; ++j) {
      long long val = dp[i - 1][j];
      if (val == -1) continue;
      for (int k = min(cnt[i], 1LL * M / i); ~k; --k) {
        int t = (j + k * i) / M, v = (j + k * i) % M;
        dp[i][v] = max(dp[i][v], val + t + (cnt[i] - k) / (M / i));
      }
    }
  long long ans = 0, val;
  for (int i = 0; i < M; ++i)
    if (~(val = dp[8][i]) && i <= w)
      ans = max(ans, i + min(val, (w - i) / M) * M);
  printf("%lld\n", ans);
  return 0;
}
