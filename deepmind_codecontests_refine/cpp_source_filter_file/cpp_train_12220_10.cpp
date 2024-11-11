#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
void solve() {
  int x, y;
  cin >> x >> y;
  if (x == 0 && y == 0) {
    cout << 0 << endl;
    return;
  }
  if (x == 1 && y == 0) {
    cout << 0 << endl;
    return;
  }
  if (x == 1 && y == 1) {
    cout << 1 << endl;
    return;
  }
  if (x > 0) {
    if (y >= -(x - 1) && y <= x) y = 0;
  } else {
    if (y >= x && y <= -x) y = 0;
  }
  if (y > 0) {
    if (x >= -y && x <= y) x = 0;
  } else {
    if (x >= y && x <= abs(y) + 1) x = 0;
  }
  if (x == 0) {
    int ans = max(0, abs(y) - 1) * 4;
    if (y > 0)
      ans += 2;
    else
      ans += 4;
    cout << ans << endl;
    return;
  }
  if (y == 0) {
    int ans = max(0, abs(x) - 1) * 4;
    if (x < 0)
      ans += 3;
    else
      ans++;
    cout << ans << endl;
    return;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) solve();
  return 0;
}
