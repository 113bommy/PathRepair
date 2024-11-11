#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.1415926535897932384626433832795l;
template <typename T>
inline auto sqr(T x) -> decltype(x * x) {
  return x * x;
}
template <typename T1, typename T2>
inline bool umx(T1& a, T2 b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T1, typename T2>
inline bool umn(T1& a, T2 b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
struct Input {
  int64_t s, x;
  bool read() { return !!(cin >> s >> x); }
  void init(const Input& input) { *this = input; }
};
struct Data : Input {
  int64_t ans;
  void write() { cout << ans << endl; }
  virtual void solve() {}
  virtual void clear() { *this = Data(); }
};
struct Solution : Data {
  void solve() {
    int64_t y = s - x;
    if (y & 1) {
      ans = 0;
      return;
    }
    y >>= 1;
    ;
    if (x & y) {
      ans = 0;
      return;
    }
    ans = 1ll << __builtin_popcountll(x);
    if (!y) {
      ans -= 2;
    }
  }
  void clear() { *this = Solution(); }
};
Solution sol;
int main() {
  cout.setf(ios::showpoint | ios::fixed);
  cout.precision(20);
  sol.read();
  sol.solve();
  sol.write();
  return 0;
}
