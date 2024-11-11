#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x1, y1, r1, x2, y2, r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  if (r2 < r1) swap(x1, x2), swap(y1, y2), swap(r1, r2);
  double ans;
  double dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  if (dist >= r1 + r2) {
    ans = (dist - r1 - r2) / 2.0;
  } else if (dist >= r2) {
    ans = 0.0;
  } else {
    ans = (r2 - dist - r1) / 2.0;
  }
  cout << fixed << setprecision(12) << ans;
  return 0;
}
