#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using i64 = long long;
using i32 = int;
using f64 = long double;
template <class Key>
using vec = vector<Key>;
template <class Key>
using heap = priority_queue<Key>;
template <class Key>
using hash_set = unordered_set<Key>;
template <class Key, class Value>
using hash_map = unordered_map<Key, Value>;
using str = string;
using p64 = pair<i64, i64>;
using v64 = vec<i64>;
using vv64 = vec<v64>;
using s64 = set<i64>;
using m64 = map<i64, i64>;
const i64 inf = numeric_limits<i64>::max() / 2;
template <typename T>
inline i64 sz(const T& a) {
  return (i64)(a.size());
}
inline void fast() { ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); }
template <typename T>
inline bool check_min(T& a, T b) {
  if (a > b) return a = b, 1;
  return 0;
}
template <typename T>
inline bool check_max(T& a, T b) {
  if (a < b) return a = b, 1;
  return 0;
}
struct Problem {
  Problem(bool multitest = 0) {
    read();
    if (!multitest) solve();
  }
  void solve(), read();
};
signed main() {
  fast();
  Problem();
  return 0;
}
i64 n, a, r, m;
v64 h;
i64 check2(i64 x, i64 ip, i64 im) {
  i64 d = min({x, ip, im});
  i64 ip_ = ip - d;
  i64 im_ = im - d;
  i64 cur = ip_ * r + im_ * a + d * m;
  return cur;
}
i64 ternary2(i64 l, i64 r, i64 ip, i64 im) {
  while (r - l > 2) {
    i64 d = (r - l) / 3;
    i64 m1 = l + d;
    i64 m2 = r - d;
    if (check2(m1, ip, im) > check2(m2, ip, im)) {
      l = m1;
    } else {
      r = m2;
    }
  }
  i64 a1 = check2(l, ip, im);
  i64 a2 = check2(l + 1, ip, im);
  i64 a3 = check2(r, ip, im);
  return min({a1, a2, a3});
}
i64 check(i64 x) {
  i64 ip = 0, im = 0;
  for (i64 i = 0; i < n; i++) {
    if (h[i] > x) {
      ip += abs(h[i] - x);
    } else {
      im += abs(h[i] - x);
    }
  }
  i64 d = ternary2(0, min(ip, im), ip, im);
  return d;
}
i64 ternary(i64 l, i64 r) {
  while (r - l > 2) {
    i64 d = (r - l) / 3;
    i64 m1 = l + d, m2 = r - d;
    if (check(m1) > check(m2)) {
      l = m1;
    } else {
      r = m2;
    }
  }
  i64 m1 = check(l), m2 = check(l + 1), m3 = check(r);
  return min({m1, m2, m3});
}
void Problem::solve() {
  i64 ans = ternary(0, 1e14 + 1);
  cout << ans << "\n";
}
void Problem::read() {
  cin >> n >> a >> r >> m;
  h.resize(n);
  for (i64 i = 0; i < n; i++) {
    cin >> h[i];
  }
}
