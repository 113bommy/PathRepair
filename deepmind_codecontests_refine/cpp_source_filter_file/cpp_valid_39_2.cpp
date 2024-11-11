#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int W, H;
    cin >> W >> H;
    long long int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long long int w, h;
    cin >> w >> h;
    long long int ans = INT_MAX;
    if (x2 - x1 + w <= W)
      ans = min(ans, (max(0ll, w - x1), max(0ll, x2 - W + w)));
    if (y2 - y1 + h <= H)
      ans = min(ans, (max(0ll, h - y1), max(0ll, y2 - H + h)));
    if (ans == INT_MAX)
      cout << "-1\n";
    else
      cout << ans << "\n";
  }
}
