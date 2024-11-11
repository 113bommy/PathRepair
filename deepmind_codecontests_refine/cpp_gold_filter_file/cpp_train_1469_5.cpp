#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct BIT {
  int n;
  vector<T> t;
  BIT(int n) : n(n), t(n + 1, 0) {}
  void modify(int r, T v) {
    for (int i = r; i <= n; i += i & -i) t[i] += v;
  }
  T sum(int r) {
    T s = 0;
    for (int i = r; i >= 1; i -= i & -i) s += t[i];
    return s;
  }
  T sum(int l, int r) { return sum(r) - sum(l - 1); }
  int lower_bound(T v) {
    T sum = 0, pos = 0, k = 31 - __builtin_clz(n);
    for (int i = k; i >= 0; i--) {
      if (pos + (1 << i) <= n && sum + t[pos + (1 << i)] < v) {
        pos += 1 << i;
        sum += t[pos];
      }
    }
    return pos + 1;
  }
};
template <int mod = 1000000007>
struct modint {
  int x;
  modint(long long y = 0) : x((y % mod + mod) % mod) {}
  friend modint operator^(modint a, int64_t b) {
    modint r = 1;
    for (; b; b >>= 1, a *= a)
      if (b & 1) r *= a;
    return r;
  }
  friend modint operator-(modint a) { return modint(0) - a; }
  friend modint operator!(modint a) { return a ^ (mod - 2); }
  modint& operator/=(modint const& b) { return *this *= !b; }
  friend modint operator+(modint a, modint const& b) { return a += b; }
  friend modint operator-(modint a, modint const& b) { return a -= b; }
  friend modint operator*(modint a, modint const& b) { return a *= b; }
  friend modint operator/(modint a, modint const& b) { return a /= b; }
  friend bool operator!=(const modint& a, const modint b) { return a.x != b.x; }
  friend bool operator==(const modint& a, const modint b) { return a.x == b.x; }
  modint& operator*=(modint const& b) {
    x = 1LL * x * b.x % mod;
    return *this;
  }
  friend ostream& operator<<(ostream& os, modint const& a) { return os << a.x; }
  modint& operator+=(modint const& b) {
    x += b.x;
    x = (x >= mod) ? x - mod : x;
    return *this;
  }
  modint& operator-=(modint const& b) {
    x = x >= b.x ? x - b.x : x - b.x + mod;
    return *this;
  }
};
using mint = modint<>;
using LL = long long;
const int N = 2e5 + 10;
int a[N], w[N];
void update(int i, int x, BIT<LL>& bit, BIT<mint>& t) {
  bit.modify(i, x - w[i]);
  t.modify(i, mint(x - w[i]) * mint(a[i] - i));
  w[i] = x;
}
mint cost(int l, int r, int m, BIT<LL>& W, BIT<mint>& WX) {
  return mint(a[m] - m) * mint(W.sum(l, m)) - WX.sum(l, m) + WX.sum(m, r) -
         mint(a[m] - m) * mint(W.sum(m, r));
}
int32_t main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  cin >> n >> q;
  BIT<LL> bit(n);
  BIT<mint> t(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    update(i, x, bit, t);
  }
  for (int i = 1; i <= q; i++) {
    int x, y;
    cin >> x >> y;
    if (x < 0)
      update(-x, y, bit, t);
    else {
      int idx = bit.lower_bound(bit.sum(x - 1) + bit.sum(x, y) / 2 + 1);
      cout << cost(x, y, idx, bit, t) << endl;
    }
  }
}
