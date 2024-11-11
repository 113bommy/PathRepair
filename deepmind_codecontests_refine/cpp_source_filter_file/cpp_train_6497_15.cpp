#include <bits/stdc++.h>
using namespace std;
const int M = 2e3 + 10;
long long a[M], n, k, dp[M];
bool Is(long long num) {
  memset(dp, 0X3f3f3f3f, sizeof(dp));
  dp[1] = 0;
  for (int i = 2; i <= n; i++) {
    dp[i] = i - 1;
    for (int j = i - 1; j >= 1; j--) {
      if (a[i] - a[j] <= (i - j) * num) {
        dp[i] = min(dp[i], dp[j] + (long long)(i - j - 1));
      }
    }
    if (dp[i] + n - (long long)i <= k) return true;
  }
  if (dp[n] <= k) return true;
  return false;
}
int main() {
  scanf("%I64d%I64d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
  }
  long long sum = 0;
  for (int i = 2; i <= n; i++) {
    sum = max(sum, abs(a[i] - a[i - 1]));
  }
  long long l = 0, r = sum;
  long long ans = sum;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (Is(mid)) {
      ans = min(ans, mid);
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
