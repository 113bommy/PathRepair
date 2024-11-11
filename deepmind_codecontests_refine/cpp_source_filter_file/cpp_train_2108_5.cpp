#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1.0);
const int_fast32_t mod = 1e9 + 7;
struct pr {
  int_fast32_t x;
  int_fast32_t y;
  int_fast32_t dst;
  pr() {}
  pr(int_fast32_t x, int_fast32_t y, int_fast32_t dst) : x(x), y(y), dst(dst) {}
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
  int_fast32_t x;
  int_fast32_t y;
  point() {}
  point(int_fast32_t x, int_fast32_t y) : x(x), y(y) {}
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
class prHash {
 public:
  size_t operator()(const pr& cmp1) const {
    return (hash<int_fast32_t>()(cmp1.x)) ^ (hash<int_fast32_t>()(cmp1.y)) ^
           (hash<int_fast32_t>()(cmp1.dst));
  }
};
class pointHash {
 public:
  size_t operator()(const point& cmp1) const {
    return (hash<int_fast32_t>()(cmp1.x)) ^ (hash<int_fast32_t>()(cmp1.y));
  }
};
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
  int_fast32_t n;
  cin >> n;
  int_fast32_t sum = 0;
  int_fast32_t now = 1;
  vector<int_fast32_t> ans;
  while (1) {
    if (n - sum > now) {
      ans.push_back(now);
      sum += now;
      now *= 2;
    } else {
      ans.push_back(n - sum);
      break;
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (int_fast32_t i = 1; i < (int_fast32_t)ans.size(); ++i) {
    cout << ans[i] - ans[i - 1] << ' ';
  }
  cout << endl;
}
void solve() {
  int_fast32_t t;
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
