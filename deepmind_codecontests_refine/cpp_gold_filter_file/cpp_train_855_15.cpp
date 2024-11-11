#include <bits/stdc++.h>
using namespace std;
const long long md = 998244353;
struct modular_num {
  long long d;
  modular_num(long long x = 0) { d = normal(x); }
  long long normal(long long x) {
    x %= md;
    while (x < 0) x += md;
    return x;
  }
  modular_num inverse(modular_num t) { return t ^ (md - 2); }
  friend istream& operator>>(istream& in, modular_num& t) {
    in >> t();
    return in;
  }
  friend ostream& operator<<(ostream& out, modular_num t) {
    out << t();
    return out;
  }
  long long& operator()() { return d; }
  modular_num operator+(modular_num t) { return normal(d + t()); }
  modular_num& operator+=(modular_num t) { return *this = *this + t; }
  modular_num operator-(modular_num t) { return normal(d - t()); }
  modular_num& operator-=(modular_num t) { return *this = *this - t; }
  modular_num operator*(modular_num t) { return 1ll * d * t() % md; }
  modular_num& operator*=(modular_num t) { return *this = *this * t; }
  modular_num operator^(long long power) {
    modular_num base = *this, res = 1;
    while (power > 0) {
      if (power & 1) res *= base;
      base *= base;
      power >>= 1;
    }
    return res;
  }
  modular_num& operator^=(long long power) { return *this = *this ^ power; }
  modular_num operator/(modular_num t) { return 1ll * d * inverse(t)() % md; }
  modular_num& operator/=(modular_num t) { return *this = *this / t; }
  modular_num& operator=(modular_num t) {
    d = t();
    return *this;
  }
  bool operator==(modular_num t) { return d == t(); }
  bool operator!=(modular_num t) { return d != t(); }
};
using mint = modular_num;
const long long N = 2e5 + 5;
mint fac[N], ifac[N];
void precalc() {
  fac[0] = ifac[0] = 1;
  for (long long i = 1; i < N; i++) {
    fac[i] = fac[i - 1] * i;
    ifac[i] = mint(1) / fac[i];
  }
}
mint C(long long n, long long k) {
  assert(k <= n);
  return fac[n] * ifac[k] * ifac[n - k];
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  precalc();
  long long n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << fac[n] << '\n';
    return 0;
  }
  if (k >= n) {
    cout << 0 << '\n';
    return 0;
  }
  mint ans = 0;
  long long r = n - k;
  for (long long i = 0; i <= r; i++) {
    mint val = C(r, i) * (mint(i) ^ n);
    (r - i)& 1 ? ans -= val : ans += val;
  }
  ans *= C(n, k) * 2;
  cout << ans << '\n';
  return 0;
}
