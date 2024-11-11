#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const double PI = acos(-1.);
template <class T>
inline T sq(T x) {
  return x * x;
}
template <class T>
inline void upd_min(T &lhs, T rhs) {
  if (lhs > rhs) lhs = rhs;
}
template <class T>
inline void upd_max(T &lhs, T rhs) {
  if (lhs < rhs) lhs = rhs;
}
void solve() {
  int n, k;
  cin >> n >> k;
  string line;
  cin >> line;
  string ans = line;
  for (int pos = 0; pos + 1 < n; ++pos) {
    if (ans[pos] != '4' || ans[pos + 1] != '7') continue;
    if (pos == string::npos) break;
    if (pos & 1) {
      if (pos && ans[pos - 1] == '4') {
        if (k & 1) {
          ans[pos] = ans[pos + 1] = '7';
        }
        break;
      } else {
        ans[pos] = ans[pos + 1] = '7';
        --k;
      }
    } else {
      if (pos + 2 < n && ans[pos + 2] == '7') {
        if (k & 1) {
          ans[pos] = ans[pos + 1] = '4';
        }
        break;
      } else {
        ans[pos] = ans[pos + 1] = '4';
        --k;
      }
    }
  }
  cout << ans << endl;
}
int main() {
  solve();
  return 0;
}
