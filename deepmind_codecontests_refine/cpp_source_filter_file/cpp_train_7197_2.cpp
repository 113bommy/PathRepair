#include <bits/stdc++.h>
using namespace std;
int n, m, k, q;
pair<int, int> a[10005];
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
  long long ans = 1;
  int x = 0, y = 0;
  for (int i = 0; i < n; ++i) {
    int dtx = a[i].first - x;
    int dty = a[i].second - y;
    if (x > y) {
      if (dty + y >= x) {
        ans++;
        y += x - y;
        ans += min(dtx, a[i].second - y);
        x += dtx;
        y = a[i].second;
      } else
        x += dtx, y += dty;
    } else if (y > x) {
      if (dtx + x >= y) {
        ans++;
        x += y - x;
        ans += min(dty, a[i].first - x);
        y += dty;
        x += a[i].first;
      } else
        x += dtx, y += dty;
    } else {
      ans += min(dtx, dty);
      x += dtx;
      y += dty;
    }
  }
  cout << ans;
  return 0;
}
