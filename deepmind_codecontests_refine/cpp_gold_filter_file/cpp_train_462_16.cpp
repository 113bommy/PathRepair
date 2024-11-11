#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  double di, r, x, y, x1, y1, a, b, d;
  int ans = 0;
  cin >> r >> x >> y >> x1 >> y1;
  a = abs(x1 - x);
  b = abs(y1 - y);
  di = 2 * r;
  d = sqrt((a * a) + (b * b));
  while (d >= di) {
    ans++;
    d = d - di;
  }
  if (d != 0) ans++;
  cout << ans;
  return 0;
}
