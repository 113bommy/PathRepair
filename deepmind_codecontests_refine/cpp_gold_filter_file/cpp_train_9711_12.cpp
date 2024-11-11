#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a > b) {
    return a;
  }
  return b;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long k;
  cin >> k;
  vector<long long> f(6);
  for (long long i = 0; i < 6; i++) {
    cin >> f[i];
  }
  long long q;
  cin >> q;
  long long n;
  cin >> n;
  vector<long long> dp(n + 1, -1e18);
  dp[0] = 0;
  for (long long i = 0; i <= 5; i++) {
    long long s = 3 * (k - 1);
    long long g = 1;
    while (s > 0) {
      g = min(g, s);
      long long val = g * f[i];
      long long w = g * pow(10, i) * 3;
      for (long long j = n; j >= w; j--) {
        dp[j] = max(dp[j], dp[j - w] + val);
      }
      s -= g;
      g *= 2;
    }
  }
  long long ans = 0;
  for (long long i = 0; i <= n; i++) {
    long long sum = 0;
    long long x = i;
    for (long long d = 0; d <= 5; d++) {
      long long ost = x % 10;
      if (ost % 3 == 0) {
        sum += 1LL * (ost / 3) * f[d];
      }
      x /= 10;
    }
    ans = max(ans, sum + dp[n - i]);
  }
  cout << ans;
  return 0;
}
