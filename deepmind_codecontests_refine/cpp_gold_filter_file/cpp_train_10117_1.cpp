#include <bits/stdc++.h>
using namespace std;
int sum[705][705], a[500100];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q, t, x, y;
  memset(sum, 0, sizeof(sum));
  cin >> q;
  while (q--) {
    cin >> t >> x >> y;
    if (t == 1) {
      a[x] += y;
      for (int i = 1; i < 705; ++i) {
        sum[i][x % i] += y;
      }
    } else {
      if (x < 705) {
        cout << sum[x][y] << endl;
      } else {
        int ans = 0;
        for (int i = y; i < 500100; i += x) ans += a[i];
        cout << ans << endl;
      }
    }
  }
  return 0;
}
