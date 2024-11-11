#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, r, x, y, ans, t, d, f, xa, ya;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c >> r;
    x = c - r;
    y = c + r;
    d = min(a, b);
    f = max(a, b);
    xa = max(d, x);
    ya = min(f, y);
    ans = (b - a) - max(0, ya - xa);
    cout << ans << "\n";
  }
  return 0;
}
