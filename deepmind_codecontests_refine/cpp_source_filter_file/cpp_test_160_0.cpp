#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, m, x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    int ans = 110;
    if (x2 >= x1)
      ans = min(x2 - x1, ans);
    else
      ans = min(ans, n - x2 + n - x1);
    if (y2 >= y1)
      ans = min(y2 - y1, ans);
    else
      ans = min(ans, m - y2 + m - y1);
    cout << ans << "\n";
  }
}
