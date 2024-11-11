#include <bits/stdc++.h>
using namespace std;
void solve() {
  int x, y, z;
  cin >> x >> y >> z;
  int x1, y1, z1;
  cin >> x1 >> y1 >> z1;
  vector<int> a(6);
  for (__typeof((6)) i = (0); i < (6); i += 1) cin >> a[i];
  int ans = 0;
  if (x > x1) ans += a[5];
  if (y > y1) ans += a[1];
  if (z > z1) ans += a[3];
  if (x < 0) ans += a[4];
  if (y < 0) ans += a[2];
  if (z < 0) ans += a[0];
  if (ans)
    cout << ans;
  else if (x < x1 && x > 0 && y < y1 && y > 0 && z < z1 && z > 0) {
    cout << accumulate((a).begin(), (a).end(), 0LL);
  } else {
    ans = accumulate((a).begin(), (a).end(), 0LL);
    if (x == x1) ans -= a[5];
    if (y == y1) ans -= a[1];
    if (z == z1) ans -= a[3];
    if (x == 0) ans -= a[4];
    if (y == 0) ans -= a[2];
    if (z == 0) ans -= a[0];
    cout << ans;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
