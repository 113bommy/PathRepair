#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> v) {
  os << "(" << v.first << ", " << v.second << ")";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> v) {
  for (int i = 0; i < (int)v.size(); i++) {
    if (i > 0) {
      os << " ";
    }
    os << v[i];
  }
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const vector<vector<T>> v) {
  for (int i = 0; i < (int)v.size(); i++) {
    if (i > 0) {
      os << endl;
    }
    os << v[i];
  }
  return os;
}
string num2bit(long long num, long long len) {
  string bit = "";
  for (int i = 0; i < (int)len; ++i) {
    bit += char('0' + (num >> i & 1));
  }
  return bit;
}
long long n, m;
vector<long long> a(202020);
template <typename Monoid>
struct SegmentTree {
  using F = function<Monoid(Monoid, Monoid)>;
  int sz;
  vector<Monoid> seg;
  const F f;
  const Monoid M1;
  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while (sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }
  void set(int k, const Monoid &x) { seg[k + sz] = x; }
  void build() {
    for (int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }
  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while (k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }
  Monoid query(int a, int b) {
    Monoid L = M1, R = M1;
    for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if (a & 1) L = f(L, seg[a++]);
      if (b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }
  Monoid operator[](const int &k) const { return seg[k + sz]; }
  template <typename C>
  int find_subtree(int a, const C &check, Monoid &M, bool type) {
    while (a < sz) {
      Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
      if (check(nxt))
        a = 2 * a + type;
      else
        M = nxt, a = 2 * a + 1 - type;
    }
    return a - sz;
  }
  template <typename C>
  int find_first(int a, const C &check) {
    Monoid L = M1;
    if (a <= 0) {
      if (check(f(L, seg[1]))) return find_subtree(1, check, L, false);
      return -1;
    }
    int b = sz;
    for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if (a & 1) {
        Monoid nxt = f(L, seg[a]);
        if (check(nxt)) return find_subtree(a, check, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }
  template <typename C>
  int find_last(int b, const C &check) {
    Monoid R = M1;
    if (b >= sz) {
      if (check(f(seg[1], R))) return find_subtree(1, check, R, true);
      return -1;
    }
    int a = sz;
    for (b += sz; a < b; a >>= 1, b >>= 1) {
      if (b & 1) {
        Monoid nxt = f(seg[--b], R);
        if (check(nxt)) return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};
long long f(long long x) {
  vector<long long> b(n);
  for (int i = 0; i < (int)n; ++i) b[i] = (a[i] < x ? -1 : 1);
  vector<long long> S(n + 1, 0);
  for (int i = 0; i < (int)n; ++i) S[i + 1] = S[i] + b[i];
  SegmentTree<long long> seg(
      405020, [](long long a, long long b) { return a + b; }, 0);
  const long long geta = 202020;
  long long res = 0;
  for (int i = n; i >= 0; i--) {
    res += seg.query(S[i] + geta + 1, 405020);
    long long val = seg[S[i] + geta];
    seg.update(S[i] + geta, val + 1);
  }
  return res;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < (int)n; ++i) cin >> a[i];
  cout << f(m) - f(m + 1) << endl;
  return 0;
}
