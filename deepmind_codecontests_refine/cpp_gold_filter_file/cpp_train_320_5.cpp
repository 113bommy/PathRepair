#include <bits/stdc++.h>
class mint {
 public:
  unsigned int v;
  static unsigned int _addu(unsigned int a, unsigned int b) {
    return (a + b) % ((int)1e9 + 7);
  }
  static unsigned int _mulu(unsigned int a, unsigned int b) {
    return (unsigned long long int)a * b % ((int)1e9 + 7);
  }
  mint() {}
  mint(unsigned int _v) : v(_v) {}
  mint(int _v) : v((_v % ((int)1e9 + 7) + ((int)1e9 + 7)) % ((int)1e9 + 7)) {}
  mint(unsigned long long int _v) : v(_v % ((int)1e9 + 7)) {}
  mint(long long int _v)
      : v((_v % ((int)1e9 + 7) + ((int)1e9 + 7)) % ((int)1e9 + 7)) {}
  mint &operator+=(const mint &x) {
    v = _addu(v, x.v);
    return *this;
  }
  mint &operator-=(const mint &x) {
    v = _addu(v, ((int)1e9 + 7) - x.v);
    return *this;
  }
  mint &operator*=(const mint &x) {
    v = _mulu(v, x.v);
    return *this;
  }
  mint operator+(const mint &x) { return mint(_addu(v, x.v)); }
  mint operator-(const mint &x) { return mint(_addu(v, ((int)1e9 + 7) - x.v)); }
  mint operator*(const mint &x) { return mint(_mulu(v, x.v)); }
  operator unsigned int() const { return v; }
  operator int() const { return v; }
  operator unsigned long long int() const { return v; }
  operator long long int() const { return v; }
};
template <class T>
class bit {
 public:
  T a[262144];
  void add(int x, T k) {
    while (x < 262144) {
      a[x] += k;
      x |= x + 1;
    }
  }
  T qry(int x) {
    T ans = 0;
    while (x >= 0) {
      ans += a[x];
      x -= x + 1 & ~x;
    }
    return ans;
  }
  int lbd(T k) {
    if (a[262144 - 1] < k) return 262144;
    T ans = -1;
    int x = 262144 >> 1;
    while (x) {
      if (a[ans + x] < k) k -= a[ans += x];
      x >>= 1;
    }
    return ans + 1;
  }
  int ubd(T k) {
    if (a[262144 - 1] <= k) return 262144;
    T ans = -1;
    int x = 262144 >> 1;
    while (x) {
      if (a[ans + x] <= k) k -= a[ans += x];
      x >>= 1;
    }
    return ans + 1;
  }
};
int a[262144], w[262144];
bit<long long int> pw;
bit<mint> pc;
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; ++i) scanf("%d", a + i), a[i] -= i;
  for (int i = 0; i < n; ++i) scanf("%d", w + i);
  for (int i = 0; i < n; ++i) pw.add(i, w[i]);
  for (int i = 0; i < n; ++i) pc.add(i, mint(w[i]) * mint(a[i]));
  while (q--) {
    int ins, ex;
    scanf("%d%d", &ins, &ex);
    if (ins < 0) {
      int id = -ins - 1, d = ex - w[id];
      pw.add(id, d), pc.add(id, mint(d) * mint(a[id])), w[id] += d;
    } else {
      int l = ins - 1, r = ex - 1;
      int x = pw.lbd((pw.qry(l - 1) + pw.qry(r) + 1) / 2);
      0;
      mint tx(a[x]);
      mint cl = (tx * mint(pw.qry(x - 1) - pw.qry(l - 1)) -
                 (pc.qry(x - 1) - pc.qry(l - 1)));
      mint cr = ((pc.qry(r) - pc.qry(x)) - tx * mint(pw.qry(r) - pw.qry(x)));
      printf("%d\n", (int)(cl + cr));
    }
  }
  return 0;
}
