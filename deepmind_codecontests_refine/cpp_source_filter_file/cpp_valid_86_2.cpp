#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string f, s;
  cin >> f >> s;
  int one = 0, zero = 0, st = 0, ans = 0;
  for (int i = 0; i < n; ++i) {
    if (f[i] == '1')
      ++one;
    else
      ++zero;
    if (s[i] == '1')
      ++one;
    else
      ++zero;
    ++st;
    if (zero > 0) {
      if (zero > 1 && st > 1 && one > 0) {
        ans += 1;
        zero -= 2;
      }
      if (one > 0) {
        ans += 2, st = 0, one = 0, zero = 0;
      } else if (st > 1) {
        st = 1, ans += 1, zero -= 2;
      }
    }
  }
  if (zero > 0) {
    if (one > 0) {
      ans += 2, st = 0, one = 0, zero = 0;
    } else {
      ans += 1;
    }
  }
  cout << ans << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
