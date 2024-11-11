#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T, class U>
void chmin(T& t, const U& u) {
  if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
  if (t < u) t = u;
}
template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "{";
  for (int i = 0; i < (v.size()); i++) {
    if (i) os << ",";
    os << v[i];
  }
  os << "}";
  return os;
}
template <unsigned int MOD>
struct ModInt {
  using uint = unsigned int;
  using ull = unsigned long long;
  using M = ModInt;
  uint v;
  ModInt(ll _v = 0) { set_norm(_v % MOD + MOD); }
  M& set_norm(uint _v) {
    v = (_v < MOD) ? _v : _v - MOD;
    return *this;
  }
  explicit operator bool() const { return v != 0; }
  M operator+(const M& a) const { return M().set_norm(v + a.v); }
  M operator-(const M& a) const { return M().set_norm(v + MOD - a.v); }
  M operator*(const M& a) const { return M().set_norm(ull(v) * a.v % MOD); }
  M operator/(const M& a) const { return *this * a.inv(); }
  M& operator+=(const M& a) { return *this = *this + a; }
  M& operator-=(const M& a) { return *this = *this - a; }
  M& operator*=(const M& a) { return *this = *this * a; }
  M& operator/=(const M& a) { return *this = *this / a; }
  M operator-() const { return M() - *this; }
  M& operator++(int) { return *this = *this + 1; }
  M& operator--(int) { return *this = *this - 1; }
  M pow(ll n) const {
    if (n < 0) return inv().pow(-n);
    M x = *this, res = 1;
    while (n) {
      if (n & 1) res *= x;
      x *= x;
      n >>= 1;
    }
    return res;
  }
  M inv() const {
    ll a = v, b = MOD, p = 1, q = 0, t;
    while (b != 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(p -= t * q, q);
    }
    return M(p);
  }
  bool operator==(const M& a) const { return v == a.v; }
  bool operator!=(const M& a) const { return v != a.v; }
  friend ostream& operator<<(ostream& os, const M& a) { return os << a.v; }
  static int get_mod() { return MOD; }
};
using Mint = ModInt<1000000007>;
const int MX = 1 << 17;
const Mint i2 = Mint(2).inv();
void and_FWT(Mint a[], int n) {
  for (int d = 1; d < n; d <<= 1) {
    for (int m = d << 1, i = 0; i < n; i += m) {
      for (int j = 0; j < d; j++) {
        Mint x = a[i + j], y = a[i + j + d];
        a[i + j] = x + y;
      }
    }
  }
}
void and_UFWT(Mint a[], int n) {
  for (int d = 1; d < n; d <<= 1) {
    for (int m = d << 1, i = 0; i < n; i += m) {
      for (int j = 0; j < d; j++) {
        Mint x = a[i + j], y = a[i + j + d];
        a[i + j] = x - y;
      }
    }
  }
}
void and_solve(Mint a[], Mint b[], int n) {
  and_FWT(a, n);
  and_FWT(b, n);
  for (int i = 0; i < n; ++i) {
    a[i] *= b[i];
  }
  and_UFWT(a, n);
}
void xor_FWT(Mint a[], int n) {
  for (int d = 1; d < n; d <<= 1) {
    for (int m = d << 1, i = 0; i < n; i += m) {
      for (int j = 0; j < d; j++) {
        Mint x = a[i + j], y = a[i + j + d];
        a[i + j] = x + y, a[i + j + d] = x - y;
      }
    }
  }
}
void xor_UFWT(Mint a[], int n) {
  for (int d = 1; d < n; d <<= 1) {
    for (int m = d << 1, i = 0; i < n; i += m) {
      for (int j = 0; j < d; j++) {
        Mint x = a[i + j], y = a[i + j + d];
        a[i + j] = (x + y) * i2, a[i + j + d] = (x - y) * i2;
      }
    }
  }
}
void xor_solve(Mint a[], Mint b[], int n) {
  xor_FWT(a, n);
  xor_FWT(b, n);
  for (int i = 0; i < n; ++i) {
    a[i] *= b[i];
  }
  xor_UFWT(a, n);
}
Mint fib[MX];
Mint cnt[MX];
Mint x1[MX], x2[MX], c[MX], ab[MX];
int main() {
  fib[1] = 1;
  for (int i = 2; i < MX; ++i) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  int n;
  scanf("%d", &n);
  V<int> a(n);
  for (int i = 0; i < (n); i++) {
    int x;
    scanf("%d", &x);
    a[i] = x;
    cnt[x]++;
  }
  for (int i = 0; i < (MX); i++) {
    for (int j = i; j >= 0; j = ((j - 1) & i)) {
      ab[i] += cnt[j] * cnt[i ^ j];
      if (j == 0) break;
    }
  }
  for (int i = 0; i < (MX); i++) {
    x1[i] = x2[i] = c[i] = cnt[i];
  }
  xor_solve(x1, x2, MX);
  for (int i = 0; i < (MX); i++) {
    x1[i] *= fib[i];
    c[i] *= fib[i];
    ab[i] *= fib[i];
  }
  and_solve(ab, c, MX);
  and_solve(ab, x1, MX);
  Mint ans;
  for (int i = 0; i < (17); i++) {
    ans += ab[1 << i];
  }
  cout << ans << endl;
  return 0;
}
