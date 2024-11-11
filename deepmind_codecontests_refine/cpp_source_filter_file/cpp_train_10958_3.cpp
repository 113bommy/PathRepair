#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, l = 1;
  cin >> t;
  while (t--) {
    int x, y, z, x1, y1, z1, ans = 0;
    cin >> x >> y >> z >> x1 >> y1 >> z1;
    ans += min(z, y1) * 2;
    z -= min(z, y1);
    if (z1 > x + z) ans -= (z1 - x - z);
    cout << ans << endl;
  }
  return 0;
}
