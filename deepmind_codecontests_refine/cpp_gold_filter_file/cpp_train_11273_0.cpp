#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline")
const long long maxn = 1000010;
const long long mod = 998244353;
const long double eps = 1e-9;
const long long inf = ((1ll << 31ll) - 1ll);
const long long INF = 1ll * mod * mod;
const long double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long qpow(long long b, long long e) {
  if (!e) return 1;
  if (e & 1) return qpow(b, e - 1) * b % mod;
  long long pwur = qpow(b, e >> 1);
  return pwur * pwur % mod;
}
long long modinv(long long x) { return qpow(x, mod - 2); }
long long n, a[maxn], ans, fact[maxn];
long long C(long long N, long long K) {
  return fact[N] * modinv(fact[K]) % mod * modinv(fact[N - K]) % mod;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios::fixed);
  cout.precision(0);
  srand(time(NULL));
  fact[0] = 1;
  for (long long i = 1; i < maxn; i++) fact[i] = fact[i - 1] * i % mod;
  cin >> n;
  for (long long i = 1; i <= 2 * n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 2 * n + 1);
  long long s1(0), s2(0);
  for (long long i = 1; i <= 2 * n; i++) {
    if (i <= n) s1 += a[i];
    if (i > n) s2 += a[i];
  }
  cout << (s2 - s1) % mod * C(2 * n, n) % mod;
  return 0;
}
