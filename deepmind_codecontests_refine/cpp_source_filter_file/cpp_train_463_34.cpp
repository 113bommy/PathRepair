#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  double r, x, y, xx, yy;
  cin >> r >> x >> y >> xx >> yy;
  double dist = sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
  if (dist <= r && dist != 0) return cout << 2, 0;
  cout << ceil(dist / (2 * r));
  return 0;
}
