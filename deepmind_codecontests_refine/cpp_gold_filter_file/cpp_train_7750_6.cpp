#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, s;
  cin >> n >> s;
  int ans = -1;
  while (n--) {
    int x, y;
    cin >> x >> y;
    if (x > s || (x == s && y > 0)) continue;
    ans = max(ans, (100 - y) % 100);
  }
  cout << ans << endl;
}
