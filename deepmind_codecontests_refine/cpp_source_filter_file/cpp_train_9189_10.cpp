#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long long int x = abs(x1 - x2), y = abs(y1 - y2);
    long long int ans = x;
    if (y and ans)
      ans = y + 2;
    else if (y)
      ans = y;
    cout << ans << endl;
  }
}
