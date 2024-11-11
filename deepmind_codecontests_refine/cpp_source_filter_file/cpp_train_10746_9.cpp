#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using i64 = long long;
using i32 = int;
using f64 = long double;
template <class T>
using vec = vector<T>;
template <class T>
using hash_set = unordered_set<T>;
template <class T, class U>
using hash_map = unordered_map<T, U>;
using str = string;
template <size_t Size1>
using a64 = array<i64, Size1>;
template <size_t Size1, size_t Size2>
using aa64 = array<a64<Size2>, Size1>;
using p64 = pair<i64, i64>;
using v64 = vec<i64>;
using vv64 = vec<v64>;
using s64 = set<i64>;
using m64 = map<i64, i64>;
mt19937 gen(998244353);
const i64 inf = numeric_limits<i64>::max() / 2;
template <class T>
inline i64 len(const T& a) {
  return (i64)(a.size());
}
inline void fast() { ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); }
template <class T, class S>
inline bool check_min(T& a, S b) {
  if (a > b) return a = b, 1;
  return 0;
}
template <class T, class S>
inline bool check_max(T& a, S b) {
  if (a < b) return a = b, 1;
  return 0;
}
void read() {}
template <class T, class... U>
void read(T& a, U&... b) {
  cin >> a;
  read(b...);
}
void print() {}
template <class T, class... U>
void print(const T& a, const U&... b) {
  cout << a << " ";
  print(b...);
}
void println() { cout << "\n"; }
template <class T, class... U>
void println(const T& a, const U&... b) {
  cout << a << " ";
  println(b...);
}
struct Problem {
  void files(str in, str out) {
    freopen(in.c_str(), "r", stdin), freopen(out.c_str(), "w", stdout);
  }
  void solve(), input();
  void many() {
    i64 t;
    read(t);
    while (t--) input(), solve();
  }
  void make(bool mt = 0) {
    if (mt)
      many();
    else
      input(), solve();
  }
} problem;
signed main() {
  fast();
  problem.make();
  return 0;
}
struct Fenwick {
  i32 n;
  v64 t;
  i32 logn;
  Fenwick() {}
  Fenwick(i32 n_) {
    n = n_;
    t.resize(n);
    logn = log2(n) + 1;
  }
  inline i32 f(i32 i) { return i & (i + 1); }
  inline i32 h(i32 i) { return i | (i + 1); }
  void upd(i32 j, i64 x) {
    for (i32 i = j; i < n; i = h(i)) {
      t[i] += x;
    }
  }
  i64 get(i32 j) {
    check_min(j, n - 1);
    i64 ans = 0;
    for (i32 i = j; i >= 0; i = f(i) - 1) {
      ans += t[i];
    }
    return ans;
  }
  i64 get(i32 l, i32 r) {
    if (l > r) return 0;
    return get(r) - get(l - 1);
  }
  i32 descend(i32 x) {
    i32 v = 0;
    for (i32 i = logn - 1; i >= 0; i--) {
      i32 u = v + (1ll << i) - 1;
      if (u < n && t[u] < x) {
        x -= t[u];
        v = u + 1;
      }
    }
    return v;
  }
};
const i64 MAXN = 1e7 + 1;
const i64 LOG = 24;
i64 n;
v64 a;
Fenwick f(MAXN);
void Problem::solve() {
  i64 ans = 0;
  for (int(j) = 0; (j) < (LOG); (j)++) {
    i64 m = 1ll << j;
    i64 m1 = 2 * m;
    i64 m2 = 2 * m1;
    i64 total = 0;
    for (int(i) = 0; (i) < (n); (i)++) {
      i64 x = a[i] % m1;
      i64 a = m - x;
      i64 b = m1 - 1 - x;
      i64 c = m1 + m - x;
      i64 d = m2 - 2 - x;
      total += f.get(a, b);
      total += f.get(c, d);
      f.upd(x, 1);
    }
    for (int(i) = 0; (i) < (n); (i)++) {
      i64 x = a[i] % m1;
      f.upd(x, -1);
    }
    if (total % 2 == 1) {
      ans += m;
    }
  }
  println(ans);
}
void Problem::input() {
  read(n);
  a.resize(n);
  for (int(i) = 0; (i) < (n); (i)++) {
    read(a[i]);
  }
}
