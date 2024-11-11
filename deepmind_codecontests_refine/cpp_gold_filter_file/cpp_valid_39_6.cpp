#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int W, H, w, h;
    int x1, y1, x2, y2;
    cin >> W >> H;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> w >> h;
    int ans = INT_MAX;
    if (x2 + (w - x1) <= W) {
      ans = min(ans, (w - x1));
    }
    if (x1 - (w - (W - x2)) >= 0) {
      ans = min(ans, (w - (W - x2)));
    }
    if (y2 + (h - y1) <= H) {
      ans = min(ans, (h - y1));
    }
    if (y1 - (h - (H - y2)) >= 0) {
      ans = min(ans, (h - (H - y2)));
    }
    if (ans == INT_MAX) {
      cout << -1 << endl;
    } else {
      cout << max(0, ans) << endl;
    }
  }
  return 0;
}
