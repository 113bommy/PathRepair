#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long mod{998244353};
long long fact[1000001];
inline long long add(long long a, long long b) { return (a + b) % mod; }
inline long long mul(long long a, long long b) { return (a * b) % mod; }
inline long long binpow(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = mul(res, a);
    a = mul(a, a);
    n >>= 1;
  }
  return res;
}
inline long long r(long long x) { return binpow(x, mod - 2); }
inline long long divi(long long a, long long b) { return mul(a, r(b)); }
inline long long C(long long n, long long k) {
  return divi(divi(fact[n], fact[k]), fact[n - k]);
}
inline void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}
signed main() {
  fastio();
  long long n, k;
  cin >> n >> k;
  fact[0] = 1;
  for (long long i = 1; i <= n; i++) fact[i] = mul(fact[i - 1], i);
  long long ans = 0;
  for (long long mel = 1; mel <= n; mel++) {
    long long lv = 1, rv = 1000001;
    while (rv - lv > 1) {
      long long mv = (lv + rv) >> 1;
      if (mv * mel <= n)
        lv = mv;
      else
        rv = mv;
    }
    if (lv < k) continue;
    if (lv == 1) {
      ans = add(ans, 1);
      continue;
    }
    ans = add(ans, C(lv - 1, k - 1));
  }
  cout << ans;
  return 0;
}
