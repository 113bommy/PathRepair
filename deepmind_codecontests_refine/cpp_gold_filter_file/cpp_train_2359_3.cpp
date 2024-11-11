#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  t = 1;
  while (t--) {
    long long n;
    cin >> n;
    map<long long, long long> dp, sum;
    --n;
    dp[0] = 1;
    for (long long i = 1; i < 60; ++i) dp[i] = (1LL << (i - 1)) + 2 * dp[i - 1];
    sum[-1] = 0;
    for (long long i = 0; i < 60; ++i) sum[i] = dp[i] + sum[i - 1];
    long long ans = 0;
    for (long long i = 59; i >= 0; --i)
      if ((1LL << i) & n) {
        ans += sum[i - 1] + (1LL << i);
      }
    cout << ans << "\n";
  }
}
