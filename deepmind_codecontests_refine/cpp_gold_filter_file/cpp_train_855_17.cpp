#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
template <typename T>
T power(T a, long long b) {
  T r = 1LL;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) r *= a;
    a *= a;
  }
  return r;
}
long long inverse(long long a, long long m) {
  a %= m;
  if (a < 0) {
    a += m;
  }
  long long b = m, u = 0, v = 1;
  while (a) {
    long long t = b / a;
    b -= a * t;
    swap(a, b);
    u -= v * t;
    swap(u, v);
  }
  if (u < 0) {
    u += m;
  }
  return u;
}
template <int _mod>
struct Mint {
  static constexpr int MOD = _mod;
  long long x;
  Mint() : x(0) {}
  Mint(long long _x) : x((_x % MOD + MOD) % MOD) {}
  explicit operator int() const { return x; }
  Mint &fix() {
    x = (x % MOD + MOD) % MOD;
    return *this;
  }
  Mint &operator+=(const Mint &other) {
    if ((x += other.x) >= MOD) {
      x -= MOD;
    }
    return *this;
  }
  Mint &operator-=(const Mint &other) {
    if ((x += MOD - other.x) >= MOD) {
      x -= MOD;
    }
    return *this;
  }
  Mint &operator*=(const Mint &other) {
    (x *= other.x) %= MOD;
    return *this;
  }
  Mint operator+(const Mint &other) const { return Mint(*this) += other; }
  Mint operator-(const Mint &other) const { return Mint(*this) -= other; }
  Mint operator*(const Mint &other) const { return Mint(*this) *= other; }
  Mint operator-() const { return Mint(0) - *this; }
  Mint &operator++() {
    x++;
    if (x == MOD) {
      x = 0;
    }
    return *this;
  }
  Mint &operator--() {
    if (x == 0) {
      x = MOD;
    }
    x--;
    return *this;
  }
  Mint operator++(int) const {
    Mint result = *this;
    ++*this;
    return result;
  }
  Mint operator--(int) const {
    Mint result = *this;
    --*this;
    return result;
  }
  bool operator<(const Mint &other) const { return x < other.x; }
  bool operator==(const Mint &other) const { return x == other.x; }
  Mint inverse() const { return Mint(::inverse(x, MOD)); }
};
template <int _mod>
ostream &operator<<(ostream &out, const Mint<_mod> &val) {
  return out << val.x;
}
template <int _mod>
istream &operator>>(istream &in, Mint<_mod> &val) {
  in >> val.x;
  return in;
}
using Modular = Mint<998244353>;
const int N = 200100;
Modular fac[N], inv[N];
int n, k;
Modular ans;
int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = fac[i - 1] * Modular(i);
    inv[i] = fac[i].inverse();
  }
  scanf("%d%d", &n, &k);
  if (k > n - 1) return puts("0"), 0;
  k = n - k;
  for (long long i = k; i >= 0; i--) {
    if (i % 2 == k % 2)
      ans += power(Modular(i), n) * fac[n] * inv[i] * inv[k - i] * inv[n - k];
    else
      ans -= power(Modular(i), n) * fac[n] * inv[i] * inv[k - i] * inv[n - k];
  }
  ans *= 2;
  if (k == n) ans = fac[n];
  printf("%lld", ans.x);
}
