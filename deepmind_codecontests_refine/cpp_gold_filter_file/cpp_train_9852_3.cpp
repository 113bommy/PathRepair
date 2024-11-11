#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long infl = 0x3f3f3f3f3f3f3f3fLL;
template <typename T>
inline void umax(T &a, T b) {
  a = max(a, b);
}
template <typename T>
inline void umin(T &a, T b) {
  a = min(a, b);
}
void debug() { cout << endl; }
template <typename T, typename... R>
void debug(T f, R... r) {
  cout << "[" << f << "]";
  debug(r...);
}
bool check(vector<int> &a, int n) {
  if (a[0] == -1) return false;
  for (int i = 1; i < n; ++i) {
    if (a[i] == -1) return false;
    if (a[i - 1] > a[i]) return false;
  }
  return true;
}
int main() {
  int n, m, c, p, pos, lb, ub;
  while (cin >> n >> m >> c) {
    vector<int> a(n, -1);
    lb = 0, ub = n - 1;
    for (int i = 1; i <= m; ++i) {
      if (check(a, n)) break;
      cin >> p;
      pos = -1;
      if (p <= c / 2) {
        for (int k = 0; k < lb; ++k)
          if (a[k] > p) {
            pos = k;
            break;
          }
        if (pos == -1) pos = lb++;
      } else {
        for (int k = n - 1; k > ub; --k)
          if (a[k] < p) {
            pos = k;
            break;
          }
        if (pos == -1) pos = ub--;
      }
      a[pos] = p;
      cout << pos + 1 << endl;
      fflush(stdout);
    }
  }
  return 0;
}
