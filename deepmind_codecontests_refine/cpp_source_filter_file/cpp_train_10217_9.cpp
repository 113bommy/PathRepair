#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long dx[4] = {-1, 1, 0, 0};
const long long dy[4] = {0, 0, -1, 1};
const long long MAX = 1e6 + 50;
const long long oo = 1e16;
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
long long n, m, k, Q, a, b, l, x, y, ans, p, T, G;
string second;
long long fact[MAX], inv[MAX];
long long binpow(long long a, long long b) {
  if (b <= 0) b += MOD - 1;
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return ret;
}
long long C(long long n, long long k) {
  long long x = (inv[k] * inv[n - k]) % MOD;
  return (fact[n] * x) % MOD;
}
long long solve(long long cntA, long long cntB) {
  if (cntB > n) return 0;
  return C(n, cntA) * C(n, cntB) % MOD;
}
long long calc1(long long i) {
  long long a = (fact[m - 1] * inv[i]) % MOD;
  long long b = (fact[n - 2] * inv[n - 2 - i]) % MOD;
  return (a * b * inv[m - 1 - i]) % MOD;
}
long long calc2(long long i) {
  return (i + 2) * 1LL * binpow(n, n - i - 3) % MOD * binpow(m, n - i - 2) %
         MOD;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  fact[0] = inv[0] = 1;
  for (long long i = 1; i < MAX; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
    inv[i] = (inv[i - 1] * binpow(i, MOD - 2)) % MOD;
  }
  cin >> n >> m >> a >> b;
  int sz = min(m - 1, n - 2);
  for (long long i = 0; i <= sz; i++)
    ans = (ans + (calc1(i) * calc2(i)) % MOD) % MOD;
  cout << ans << '\n';
  return 0;
}
