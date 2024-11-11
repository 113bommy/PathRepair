#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int W, H, w, h;
    cin >> W >> H;
    long long int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> w >> h;
    long long int disth, distw;
    distw = max(x1, W - x2);
    disth = max(y1, H - y2);
    long long int ans1 = INT_MAX, ans2 = INT_MAX;
    if (h <= disth || w <= distw) {
      cout << 0 << endl;
    } else if (h + abs(y2 - y1) > H && w + abs(x2 - x1) > W) {
      cout << -1 << endl;
    } else {
      if (h + y2 - y1 <= H) {
        ans1 = abs(disth - h);
      }
      if (w + abs(x2 - x1) <= W) {
        ans2 = abs(distw - w);
      }
      cout << min(ans1, ans2) << endl;
    }
  }
}
