#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  double y1, y2, yw, x, y, r, ans;
  cin >> y1 >> y2 >> yw >> x >> y >> r;
  ans = (x * (yw - r - r - y1) / (yw + yw - r - r - r - y1 - y));
  if (y2 - y1 <
      (r + r * (sqrt((x - ans) * (x - ans) + (yw - y - r) * (yw - y - r))) /
               (x - ans)))
    cout << "-1";
  else
    cout << setprecision(10) << ans;
  return 0;
}
