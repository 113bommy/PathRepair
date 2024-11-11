#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long x, y, n;
    cin >> x >> y >> n;
    long long rem = n % x;
    long long ans = n - rem;
    if (ans + y <= n) {
      cout << ans << "\n";
    } else {
      ans -= (x - y);
      cout << ans << "\n";
    }
  }
  return 0;
}
