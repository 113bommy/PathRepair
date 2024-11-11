#include <bits/stdc++.h>
using namespace std;
const long long N = 200100;
const long long MOD = 998244353;
void solve() {
  long long a, b, c, d, ans = 0, k;
  cin >> a >> b >> c >> d;
  if (a <= b) {
    cout << a << endl;
    return;
  }
  ans += b;
  a -= b;
  if (c <= d) {
    cout << "-1\n";
    return;
  }
  k = c - d;
  a += (k - 1);
  ans += ((a / k) * c);
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
