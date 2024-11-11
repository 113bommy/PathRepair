#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int p = 1; p <= t; p++) {
    int x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    int ans = 0;
    int t = min(z1, y2);
    ans = t * 2;
    z1 -= t, y2 -= t;
    int rem1 = x1 + y1 + z1;
    if (y1 + z2 > rem1) ans -= (y1 + z2 - rem1) * 2;
    cout << ans << endl;
  }
  return 0;
}
