#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5, inf = 1e9 + 7;
long long n, k, i, j;
long long in[N], f[N], dp[1005][1005];
inline long long expo(long long n, long long k, long long p = inf) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
inline long long inv(long long a, long long p = inf) {
  return expo(a, p - 2, p);
}
inline long long cc(long long a, long long b) {
  if (a < b || b < 0) return 0;
  return f[a] * in[b] % inf * in[a - b] % inf;
}
void fac() {
  long long i;
  f[0] = 1;
  for (i = 1; i < N; i++) f[i] = f[i - 1] * i % inf;
  in[N - 1] = inv(f[N - 1]);
  for (i = N - 1; i > 0; i--) in[i - 1] = i * in[i] % inf;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long i, j, a, b, ans = 0, m;
  fac();
  cin >> n >> m >> k;
  if (m == 1) return cout << expo(k, n), 0;
  dp[0][0] = 1;
  for (i = 1; i < n + 1; i++)
    for (j = 1; j < i + 1; j++)
      dp[i][j] = (dp[i - 1][j] * j + dp[i - 1][j - 1]) % inf;
  for (i = 1; i < n + 1; i++)
    for (j = 1; j < i + 1; j++) dp[i][j] = dp[i][j] * f[j] % inf;
  for (i = 1; i < min(n, k) + 1; i++)
    for (j = 0; j < i + 1; j++)
      if (k >= 2 * i - j)
        ans += cc(k, 2 * i - j) * cc(2 * i - j, i - j) % inf * cc(i, i - j) %
               inf * expo(j, n * (m - 2)) % inf * dp[n][i] % inf * dp[n][i] %
               inf;
  cout << ans % inf;
}
