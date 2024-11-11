#include <bits/stdc++.h>
using namespace std;
int n, x, y, d;
int t;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> x >> y >> d;
    int ans = 0x7fffffff;
    if (((y - x) % d) && ((y - 1) % d) && ((n - y) % d)) {
      cout << -1 << endl;
      continue;
    }
    if (!((y - x) % d)) ans = min(ans, abs(y - x) / d);
    if (!((y - 1) % d)) ans = min(ans, (y - 1) / d + ((x - 2 + d) / d));
    if (!((n - y) % d)) ans = min(ans, (n - y) / d + (n - x + d - 1) / d);
    cout << ans << endl;
  }
}
