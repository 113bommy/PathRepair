#include <bits/stdc++.h>
template <class T>
class SegmentTree {
  using ABO = std::function<T(T, T)>;
  const int size;
  const int treeWidth;
  std::vector<T> nodes;
  ABO abo;
  static int npo2(int v) {
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
  }
  T query(int l, int r, int index, int cl, int cr) {
    if (cl >= l && cr <= r) {
      return nodes[index];
    }
    int mid = (cl + cr) / 2;
    if (r < mid + 1) {
      return query(l, r, index * 2, cl, mid);
    }
    if (l > mid) {
      return query(l, r, index * 2 + 1, mid + 1, cr);
    }
    return abo(query(l, r, index * 2, cl, mid),
               query(l, r, index * 2 + 1, mid + 1, cr));
  }

 public:
  static T aboAdd(T a, T b) { return a + b; }
  static T aboMultiply(T a, T b) { return a * b; }
  static T aboMin(T a, T b) { return a < b ? a : b; }
  static T aboMax(T a, T b) { return a < b ? b : a; }
  static T aboXor(T a, T b) { return a ^ b; }
  static T aboOr(T a, T b) { return a | b; }
  static T aboAnd(T a, T b) { return a & b; }
  SegmentTree(int size, ABO abo, T defaultValue = T())
      : size(size), treeWidth(npo2(size)), abo(abo) {
    nodes.resize(treeWidth * 2, defaultValue);
  }
  void update(int pos, std::function<void(T &)> updateValueFunc) {
    assert(pos >= 1);
    assert(pos <= treeWidth);
    int index = treeWidth + pos - 1;
    updateValueFunc(nodes[index]);
    while ((index >>= 1) > 0) {
      nodes[index] = abo(nodes[index * 2], nodes[index * 2 + 1]);
    }
  }
  T query(int l, int r) {
    assert(l <= r);
    assert(l >= 1);
    assert(r <= treeWidth);
    return query(l, r, 1, 1, treeWidth);
  }
};
template <int mod = (int)1e9 + 7>
struct ModInt {
  long long v;
  ModInt() : v(0) {}
  template <typename T>
  ModInt(T v) : v(v % mod) {}
  ModInt operator+(const ModInt &rhs) const { return (v + rhs.v) % mod; }
  template <typename T>
  ModInt operator+(const T &rhs) const {
    return (v + rhs) % mod;
  }
  template <typename T>
  void operator+=(const T &rhs) {
    *this = *this + rhs;
  }
  ModInt operator-(const ModInt &rhs) const { return (v - rhs.v) % mod; }
  template <typename T>
  ModInt operator-(const T &rhs) const {
    return (v - rhs) % mod;
  }
  template <typename T>
  void operator-=(const T &rhs) {
    *this = *this - rhs;
  }
  ModInt operator*(const ModInt &rhs) const { return (v * rhs.v) % mod; }
  template <typename T>
  ModInt operator*(const T &rhs) const {
    return (v * rhs) % mod;
  }
  template <typename T>
  void operator*=(const T &rhs) {
    *this = *this * rhs;
  }
  template <typename T>
  ModInt operator/(const T &rhs) const {
    return (*this) * static_cast<ModInt>(rhs).pow(mod - 2);
  }
  template <typename T>
  void operator/=(const T &rhs) {
    *this = *this / rhs;
  }
  template <typename T>
  ModInt pow(T rhs) const {
    long long mul = v;
    ModInt res = 1;
    while (rhs) {
      if (rhs & 1) {
        res.v *= mul;
        res.v %= mod;
      }
      mul *= mul;
      mul %= mod;
      rhs /= 2;
    }
    return res;
  }
  ModInt inverse() const {
    int v = (this->v + mod) % mod;
    int y = 0, x = 1;
    int m = mod;
    while (v > 1) {
      int q = v / m;
      int t = m;
      m = v % m;
      v = t;
      t = y;
      y = x - q * y;
      x = t;
    }
    if (x < 0) {
      x += mod;
    }
    return x;
  }
  template <typename T>
  operator T() {
    return (v + mod) % mod;
  }
};
const int MOD = 998244353;
using MI = ModInt<MOD>;
struct State {
  MI ways, prefix, suffix, mid;
  int first, last, len;
  State() : len(0) {}
  void setValue(int v) {
    first = v;
    last = v;
    len = 1;
    ways = v + 1;
    prefix = 1;
    suffix = 1;
    mid = 1;
  }
};
using ST = SegmentTree<State>;
const int MAXN = 500005;
int n, m;
char str[MAXN];
int getVal(int index) { return str[index] - '0'; }
int main() {
  scanf("%d %d", &n, &m);
  scanf("%s", str);
  ST st(n, [](State s1, State s2) {
    if (s1.len == 0) return s2;
    if (s2.len == 0) return s1;
    State res;
    res.first = s1.first;
    res.last = s2.last;
    res.prefix = s1.ways * s2.prefix;
    res.suffix = s1.suffix * s2.ways;
    res.mid = s1.suffix * s2.prefix;
    res.ways = s1.ways * s2.ways;
    res.len = s1.len + s2.len;
    int dv = s1.last * 10 + s2.first;
    if (dv >= 10 && dv <= 18) {
      if (s2.len > 1) {
        res.prefix += s1.prefix * s2.mid * (19 - dv);
      }
      if (s1.len > 1) {
        res.suffix += s1.mid * s2.suffix * (19 - dv);
      }
      if (s1.len > 1 && s2.len > 1) {
        res.mid += s1.mid * s2.mid * (19 - dv);
      }
      res.ways += s1.prefix * s2.suffix * (19 - dv);
    }
    return res;
  });
  for (int i = 1; i <= n; i++) {
    st.update(i, [&](State &s) { s.setValue(getVal(i - 1)); });
  }
  for (int i = 0; i < m; i++) {
    int x, d;
    scanf("%d %d", &x, &d);
    st.update(x, [&](State &s) { s.setValue(d); });
    auto state = st.query(1, n);
    printf("%d\n", (int)state.ways);
  }
  return 0;
}
