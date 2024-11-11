#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int dp[1005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int W, H;
    cin >> W >> H;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int w, h;
    cin >> w >> h;
    int res = INT_MAX;
    if (x1 >= w) {
      res = 0;
    } else if (x2 - x1 + w <= W && h <= H) {
      res = min(res, w + (x2 - x1) - x2);
    }
    if (W - x2 >= w) {
      res = 0;
    } else if (x2 - x1 + w <= W) {
      res = min(res, w + (x2 - x1) - (W - x1));
    }
    if (y1 >= h) {
      res = 0;
    } else if (y2 - y1 + h <= H) {
      res = min(res, h + (y2 - y1) - y2);
    }
    if (H - y2 >= h) {
      res = 0;
    } else if (y2 - y1 + h <= H) {
      res = min(res, h + (y2 - y1) - (H - y1));
    }
    if (h > H || w > W) res = -1;
    if (res == INT_MAX) res = -1;
    cout << res << '\n';
  }
}
