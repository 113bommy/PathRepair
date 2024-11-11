#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} debug1;
template <typename T1, typename T2>
inline ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
inline ostream& operator<<(ostream& os, const vector<T>& v) {
  bool first = true;
  os << "[";
  for (typename vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
    if (!first) os << ", ";
    os << *ii;
    first = false;
  }
  return os << "]";
}
int h[2], a[2], d[2];
int c[3];
void solve() {
  for (int i = 0; i < 2; ++i) scanf("%d%d%d", &h[i], &a[i], &d[i]);
  for (int i = 0; i < 3; ++i) scanf("%d", &c[i]);
  int ans = numeric_limits<int>::max();
  for (int x = max(0, d[1] - a[0] + 1); x <= 200; ++x) {
    for (int y = 0; y <= 200; ++y) {
      int cost = x * c[1] + y * c[2];
      int dec1 = a[0] + x - d[1];
      int dec2 = max(0, a[1] - d[0] - y);
      int moves = h[1] / dec1 + (h[1] % dec1 != 0);
      int ex = max(0, moves * dec2 - h[0] + 1);
      cost += ex * c[0];
      ans = min(ans, cost);
    }
  }
  printf("%d\n", ans);
}
int main() {
  solve();
  return 0;
}
