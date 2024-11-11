#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
const long double pi = acos(-1.0);
const int_fast64_t mod = 1e9 + 7;
struct pr {
  int_fast64_t x;
  int_fast64_t y;
  int_fast64_t dst;
  pr() {}
  pr(int_fast64_t x, int_fast64_t y, int_fast64_t dst) : x(x), y(y), dst(dst) {}
  inline bool operator<(const pr& cmp2) const {
    if (dst != cmp2.dst) return dst < cmp2.dst;
    if (x != cmp2.x) return x < cmp2.x;
    return y < cmp2.y;
  }
  inline bool operator==(const pr& cmp2) const {
    return (cmp2.dst == dst) && (cmp2.x == x) && (cmp2.y == y);
  }
  inline bool operator>(const pr& cmp2) const {
    if (dst != cmp2.dst) return dst > cmp2.dst;
    if (x != cmp2.x) return x > cmp2.x;
    return y > cmp2.y;
  }
};
struct point {
  int_fast64_t x;
  int_fast64_t y;
  point() {}
  point(int_fast64_t x, int_fast64_t y) : x(x), y(y) {}
  inline bool operator<(const point& cmp2) const {
    if (cmp2.x != x) return cmp2.x < x;
    return cmp2.y < y;
  }
  inline bool operator==(const point& cmp2) const {
    return (cmp2.x == x) && (cmp2.y == y);
  }
  inline bool operator>(const point& cmp2) const {
    if (cmp2.x != x) return cmp2.x > x;
    return cmp2.y > y;
  }
};
namespace std {
template <typename T>
struct hash<vector<T> > {
  size_t operator()(const vector<T>& k) const {
    size_t ret = 0xf3ee477d;
    for (size_t i = 0; i != k.size(); ++i) ret ^= hash(hash(k[i]) + i);
    return ret;
  }
};
template <>
struct hash<pr> {
  size_t operator()(const pr& cmp1) const {
    return (hash<int_fast64_t>()(cmp1.x)) ^ (hash<int_fast64_t>()(cmp1.y)) ^
           (hash<int_fast64_t>()(cmp1.dst));
  }
};
template <>
struct hash<point> {
  size_t operator()(const point& cmp1) const {
    return (hash<int_fast64_t>()(cmp1.x)) ^ (hash<int_fast64_t>()(cmp1.y));
  }
};
}  // namespace std
inline bool spoint(const point& cmp1, const point& cmp2) {
  if (cmp1.x != cmp2.x) return cmp1.x < cmp2.x;
  return cmp1.y < cmp2.y;
}
inline bool spr(const pr& cmp1, const pr& cmp2) {
  if (cmp1.dst != cmp2.dst) return cmp1.dst < cmp2.dst;
  if (cmp1.x != cmp2.x) return cmp1.x < cmp2.x;
  return cmp1.y < cmp2.y;
}
void sub() {
  int_fast64_t n, x;
  cin >> n >> x;
  if (n < x) {
    cout << n * (n - 1) / 2 << endl;
  } else
    cout << x * (x + 1) / 2 << endl;
}
void solve() {
  int_fast64_t t;
  cin >> t;
  while (t--) sub();
}
void init() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  srand(time(0));
}
int main() {
  init();
  solve();
  return 0;
}
