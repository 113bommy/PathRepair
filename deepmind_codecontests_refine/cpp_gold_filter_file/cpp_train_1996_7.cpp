#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma optimize("O3")
using namespace std;
long long N = 1e9 + 7, M = 31;
long long i, j, l, r, n, m, t, k, f, ma = 0, y3, mi = 2e9, y, x, z, x2, y2,
                                     dp[300000], a[300000];
long long ans;
long long voz(long long x, long long y) {
  if (y == 0) return 1ll;
  if (y == 1) return x;
  if (y % 2 == 0) {
    long long t = voz(x, y / 2);
    return (t * t) % N;
  }
  if (y % 2 == 1) {
    long long t = voz(x, y / 2);
    return (t * t % N * x) % N;
  }
}
long long C(long long n, long long lk, long long rk) {
  lk = max(0ll, lk);
  rk = max(0ll, rk);
  long long ans = 0;
  for (long long k = lk; k <= rk; k++) {
    ans = (ans + dp[n] * voz(dp[k], N - 2) % N * voz(dp[n - k], N - 2)) % N;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  dp[1] = 1;
  dp[0] = 1;
  for (i = 2; i <= n; i++) {
    dp[i] = (dp[i - 1] * i) % N;
  }
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) {
    t += a[i];
    if (t > m) break;
    if (i == n) {
      l = 0;
      r = min(i, m - t);
      k = n;
      ans = (ans + voz(voz(2ll, i), N - 2) * C(i, l, r) % N * i) % N;
      continue;
    } else if (t == m) {
      l = 0;
      r = 0;
      k = i;
      ans = (ans + voz(voz(2ll, i), N - 2) * i) % N;
      continue;
    } else {
      if (t + a[i + 1] + i + 1 <= m) continue;
      l = m + 1 - t - a[i + 1];
      r = min(i, m - t);
      k = i + 1;
      ans = (ans + voz(voz(2ll, i + 1), N - 2) * C(i, l - 1, r) % N * i +
             voz(voz(2ll, i + 1), N - 2) * C(i, l, r) % N * i) %
            N;
      continue;
    }
  }
  cout << ans;
}
