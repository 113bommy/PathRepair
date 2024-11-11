#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) cin >> a[i];
    map<int, int> mark;
    mark[0] = 2 * n;
    {
      int straw, blue;
      straw = blue = 0;
      for (int i = 2 * n - 1; i >= n; i--) {
        if (a[i] == 1)
          straw++;
        else
          blue++;
        mark[straw - blue] = i;
      }
    }
    int straw, blue;
    straw = blue = 0;
    int ans = 2 * n;
    for (int i = 0; i < n; i++) {
      if (a[i] == 1)
        straw++;
      else
        blue++;
      int pos = mark[blue - straw];
      if (pos == 0) continue;
      ans = min(ans, (pos - i - 1));
    }
    cout << ans << "\n";
  }
  return 0;
}
