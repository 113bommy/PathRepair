#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long l[2000], r[2000], a[2000];
long long dp[2000];
int32_t main() {
  cin >> n >> k;
  for (long long i = 0; i < n; ++i) cin >> l[i] >> r[i] >> a[i];
  for (long long i = 1; i < n; ++i) dp[i] = 1e18;
  long long res = 1e18;
  for (long long i = 0; i < n; ++i) {
    long long t = l[i];
    long long c = k;
    long long cur = dp[i];
    for (long long j = i; j < n; ++j) {
      t = max(t, l[j]);
      if (t > r[j]) break;
      long long rem = a[j];
      if (c > rem) {
        cur += rem;
        c -= rem;
        rem = 0;
      } else {
        cur += c;
        rem -= c;
        c = k;
        t++;
        if ((r[j] - t + 1) * k < rem) break;
        cur += rem;
        if (rem % k == 0)
          t += rem / k;
        else {
          t += rem / k;
          rem %= k;
          c -= rem;
        }
      }
      if (j == n - 1)
        res = min(res, cur);
      else if (t < l[j + 1])
        dp[j + 1] = min(dp[j + 1], cur + c);
    }
  }
  if (res == 1e18)
    cout << "-1\n";
  else
    cout << res << "\n";
}
