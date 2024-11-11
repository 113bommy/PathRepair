#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long N = 2e5 + 100;
const long long MOD = 1e9 + 7;
long long f[N + 1];
void precalc() {
  f[0] = 1;
  for (long long i = 1; i <= N; i++) f[i] = f[i - 1] * i % MOD;
}
long long ppow(long long x, long long y) {
  if (y == 0) return 1;
  if (y == 1) return x;
  long long p = ppow(x, y / 2);
  return p * p % MOD * ppow(x, y % 2) % MOD;
}
long long c(long long n, long long k) {
  if (k > n || n < 0) return 0;
  return f[n] * ppow(f[k], MOD - 2) % MOD * ppow(f[n - k], MOD - 2) % MOD;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  precalc();
  long long n, m, g;
  cin >> n >> m >> g;
  if (m == 0) cout << ((n & 1) != g), exit(0);
  long long ans = (m == 1 && ((n & 1) != g));
  for (long long i = 0; i <= n; i++)
    if ((i & 1) == g && !(m == 1 && i == n))
      ans = (ans + c(n + m - i - 1, m - 1)) % MOD;
  cout << ans;
}
