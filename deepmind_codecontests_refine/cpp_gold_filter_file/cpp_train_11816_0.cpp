#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2000 + 23, D = 1000 * 1000 * 1000 + 7,
                MAXX = 200 * 1000 + 123;
long long n, h, w, r[MAXN], c[MAXN], a[MAXN], dp[MAXN], f[MAXX], ivf[MAXX];
inline long long np(long long x, long long y) {
  return f[x + y] * ivf[x] % D * ivf[y] % D;
}
int32_t main() {
  f[0] = 1;
  for (long long i = 1; i < MAXX; i++) f[i] = f[i - 1] * i % D;
  long long tmp = f[MAXX - 1];
  ivf[MAXX - 1] = 1;
  for (long long i = D - 2; i; tmp = tmp * tmp % D, i >>= 1)
    if (i & 1) ivf[MAXX - 1] = ivf[MAXX - 1] * tmp % D;
  for (long long i = MAXX - 2; ~i; i--) ivf[i] = ivf[i + 1] * (i + 1) % D;
  cin >> h >> w >> n;
  for (long long i = 0; i < n; i++) cin >> r[i] >> c[i];
  iota(a, a + n + 1, 0);
  sort(a, a + n, [](long long x, long long y) {
    return (r[x] < r[y] || (r[x] == r[y] && c[x] < c[y]));
  });
  r[n] = h, c[n] = w;
  for (long long i = 0; i <= n; i++) {
    for (long long j = 0; j < i; j++)
      if (r[a[i]] >= r[a[j]] && c[a[i]] >= c[a[j]])
        dp[i] =
            (dp[j] * np(r[a[i]] - r[a[j]], c[a[i]] - c[a[j]]) % D + dp[i]) % D;
    dp[i] = ((np(r[a[i]] - 1, c[a[i]] - 1) - dp[i]) % D + D) % D;
  }
  cout << dp[n];
  return 0;
}
