#include <bits/stdc++.h>
using namespace std;
const int N = 200005, S = 2001;
const long long INF = 2e9, MOD = 1e9 + 7;
long long ans = INF, s, x1, x2, t1, t2, xt, d;
int main() {
  cin >> s >> x1 >> x2;
  cin >> t1 >> t2;
  cin >> xt >> d;
  if (x1 < x2) {
    if (xt > x1) {
      if (d == 1)
        ans = min(ans, (s - xt) * t1 + s * t1 + x2 * t1);
      else
        ans = min(ans, xt * t1 + x2 * t1);
    }
    if (xt <= x1) {
      if (d == 1)
        ans = min(ans, (x2 - xt) * t1);
      else
        ans = min(ans, xt * t1 + x2 * t1);
    }
  }
  if (x1 > x2) {
    if (xt > x1) {
      if (d == 1)
        ans = min(ans, (s - xt) * t1 + (s - x2) * t1);
      else
        ans = min(ans, (xt - x2) * t1);
    }
    if (xt <= x1) {
      if (d == -1)
        ans = min(ans, xt * t1 + s * t1 + (s - x2) * t1);
      else
        ans = min(ans, (s - xt) * t1 + (s - x2) * t1);
    }
  }
  ans = min(ans, abs(x2 - x1) * t2);
  cout << ans;
  return 0;
}
