#include <bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[1010100];
long long dp[3001];
bool check(long long x) {
  memset(dp, 0, sizeof(dp));
  for (long long i = 1; i <= n; i++) {
    dp[i] = 1;
    for (long long j = 1; j < i; j++)
      if (x * (i - j) >= abs(a[j] - a[i])) dp[i] = max(dp[i], dp[j] + 1);
    if (dp[i] >= n - m) return 1;
  }
  return 0;
}
signed main() {
  scanf("%lld %lld", &n, &m);
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
  long long l = -1e9, r = 1e12;
  while (l + 1 < r) {
    long long mid = l + r >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%lld", check(l) ? l : r);
  return 0;
}
