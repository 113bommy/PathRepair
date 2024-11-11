#include <bits/stdc++.h>
using namespace std;
const long long oo = 1e9;
const int N = 2 * 1e5 + 1, MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, n, x, y, d;
  cin >> t;
  int ans1, ans2, ans;
  while (t--) {
    ans1 = oo, ans2 = oo;
    cin >> n >> x >> y >> d;
    if (abs(x - y) % d == 0) {
      cout << abs(x - y) / d << endl;
      break;
    } else {
      ans1 = (x - 1 + d - 1) / d;
      if ((y - 1) % d == 0) {
        ans1 += (y - 1) / d;
      } else
        ans1 = oo;
      ans2 = (n - x + d - 1) / d;
      if ((n - y) % d == 0) {
        ans2 += (n - y) / d;
      } else
        ans2 = oo;
      ans = min(ans1, ans2);
      if (ans == oo)
        cout << -1 << endl;
      else
        cout << ans << endl;
    }
  }
}
