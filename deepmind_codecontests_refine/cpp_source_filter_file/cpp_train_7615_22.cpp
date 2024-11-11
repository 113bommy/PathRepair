#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e18;
int32_t main() {
  long long n, i, j, t, ans = 0, c = 0, r, l, mx, k, b;
  cin >> t;
  while (t--) {
    ans = 0;
    cin >> n >> k;
    while (n != 0) {
      if (n % k) {
        ans += n % k;
        n -= n % k;
      } else {
        ans++;
        n /= k;
      }
    }
    cout << ans;
  }
}
