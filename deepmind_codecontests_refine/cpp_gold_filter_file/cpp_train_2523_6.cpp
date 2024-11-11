#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long x, y, a, b, ans = 0;
    cin >> x >> y >> a >> b;
    if (x > y) {
      ans = (x - y) * a + y * min(2 * a, b);
      cout << ans << endl;
    } else if (x < y) {
      ans = (y - x) * a + x * min(2 * a, b);
      cout << ans << endl;
    } else {
      ans = y * min(2 * a, b);
      cout << ans << endl;
    }
  }
}
