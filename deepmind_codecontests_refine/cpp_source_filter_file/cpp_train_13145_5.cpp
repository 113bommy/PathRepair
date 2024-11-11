#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const long long mod = (long long)1e9 + 7;
const long long MOD = (long long)998244353;
const long long INF = (long long)1e18;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
void solve() {
  long long x, y;
  cin >> x >> y;
  long long c[7];
  for (__typeof(7) i = (1) - ((1) > (7)); i != (7) - ((1) > (7));
       i += 1 - 2 * ((1) > (7)))
    cin >> c[i];
  long long ans = INF;
  if (x <= 0 and y >= 0) {
    ans = min(
        ans, abs(x) * min(c[3], c[2] + c[4]) + abs(y) * min(c[2], c[1] + c[3]));
  }
  if (x >= 0 and y <= 0) {
    ans = min(
        ans, abs(x) * min(c[6], c[5] + c[1]) + abs(y) * min(c[5], c[6] + c[4]));
  }
  if (x >= 0 and y <= x and y >= 0) {
    ans = min(ans, abs(x - y) * min(c[6], c[1] + c[5]) +
                       abs(y) * min(c[1], c[6] + c[2]));
  }
  if (x >= 0 and y >= x and y >= 0) {
    ans = min(ans, abs(x) * min(c[1], c[2] + c[6]) +
                       abs(y - x) * min(c[2], c[1] + c[3]));
  }
  if (x <= 0 and y >= x and y <= 0) {
    ans = min(ans, abs(x - y) * min(c[3], c[2] + c[4]) +
                       abs(y) * min(c[4], c[3] + c[5]));
  }
  if (x <= 0 and y <= x and y <= 0) {
    ans = min(ans, abs(x) * min(c[4], c[5] + c[3]) +
                       abs(y - x) * min(c[5], c[4] + c[6]));
  }
  cout << ans << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
