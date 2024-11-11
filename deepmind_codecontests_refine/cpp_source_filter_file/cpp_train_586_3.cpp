#include <bits/stdc++.h>
using namespace std;
long long read() {
  char x = getchar();
  long long ans = 0, flag = 1;
  while (!isdigit(x))
    if (x == '-')
      flag = -1, x = getchar();
    else
      x = getchar();
  while (isdigit(x)) ans = ans * 10 + x - '0', x = getchar();
  return ans * flag;
}
const long long p = 233, mod = 1e9 + 7;
char s[1000005];
long long n, sum[1000005], cf[1000005], dp[1000005];
signed main() {
  memset(dp, -1, sizeof(dp));
  scanf("%lld%s", &n, s + 1);
  cf[0] = 1;
  for (long long i = 1; i <= n; i++) cf[i] = cf[i - 1] * p % mod;
  for (long long i = 1; i <= n; i++)
    sum[i] = (sum[i - 1] * p % mod + s[i]) % mod;
  for (long long i = 1; i <= (n + 1) / 2; i++) {
    long long l = 0, r = i - 1, mid, ans = -1;
    if (i == (n + 1) / 2 && (n & 1)) r--;
    while (l <= r) {
      mid = (l + r) >> 1;
      long long tmp1 =
          (sum[i] - sum[i - mid - 1] * cf[mid + 1] % mod + mod) % mod;
      long long tmp2 =
          (sum[i + mid] - sum[i - 1] * cf[mid + 1] % mod + mod) % mod;
      long long tmpp1 =
          (sum[n - i + 1] - sum[n - i - mid] * cf[mid + 1] % mod + mod) % mod;
      long long tmpp2 =
          (sum[n - i + 1 + mid] - sum[n - i] * cf[mid + 1] % mod + mod) % mod;
      if (tmp1 == tmpp1 && tmp2 == tmpp2) {
        ans = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }
    dp[i - ans] = max(dp[i - ans], ans * 2 + 1);
  }
  for (long long i = 1; i <= (n + 1) / 2; i++) {
    dp[i] = max(dp[i], dp[i - 1] - 2);
    if (dp[i] <= 0)
      cout << -1 << ' ';
    else
      cout << dp[i] << ' ';
  }
  return 0;
}
