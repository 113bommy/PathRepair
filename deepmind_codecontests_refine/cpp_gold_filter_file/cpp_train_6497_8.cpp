#include <bits/stdc++.h>
using namespace ::std;
const long long maxn = 2100;
const long long inf = 1e9 + 10;
const long long qqq = inf + 76158;
long long a[maxn];
long long dp[maxn];
bool good(long long x, long long n, long long k) {
  dp[0] = 0;
  for (long long i = 1; i < n; i++) {
    dp[i] = i;
    for (long long j = i - 1; j >= 0; j--) {
      if (abs(a[i] - a[j]) <= x * (i - j)) {
        dp[i] = min(dp[i], dp[j] + (i - j - 1));
      }
    }
  }
  long long ans = dp[n - 1];
  for (long long i = n - 2; i >= 0; i--) {
    ans = min(ans, dp[i] + (n - 1 - i));
  }
  if (ans <= k) {
    return 1;
  }
  return 0;
}
int main() {
  long long n, k;
  cin >> n >> k;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (good(0, n, k)) {
    cout << 0;
    return 0;
  }
  long long b = 0;
  long long e = 2 * inf;
  while (e - b > 1) {
    long long m = (e + b) / 2;
    if (good(m, n, k)) {
      e = m;
    } else {
      b = m;
    }
  }
  cout << e;
}
