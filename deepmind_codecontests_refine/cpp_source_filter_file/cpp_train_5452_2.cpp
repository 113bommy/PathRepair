#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  cin >> n;
  double ang[n], x1, y1;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    x1 = abs(x);
    y1 = abs(y);
    if (x == 0) {
      if (y >= 0)
        ang[i] = 90;
      else
        ang[i] = 270;
    } else if (y == 0) {
      if (x >= 0)
        ang[i] = 0;
      else
        ang[i] = 180;
    } else if (x >= 0 && y >= 0)
      ang[i] = (atan(y1 / x1) * 180) / acos(-1);
    else if (x < 0 && y >= 0)
      ang[i] = 90 + ((atan(x1 / y1) * 180) / acos(-1));
    else if (x >= 0 && y < 0)
      ang[i] = 180 + ((atan(y1 / x1) * 180) / acos(-1));
    else if (x < 0 && y < 0)
      ang[i] = 360 - ((atan(y1 / x1) * 180) / acos(-1));
  }
  sort(ang, ang + n);
  double ans;
  if (n == 1)
    ans = 0;
  else {
    double ang1;
    int id1, id2;
    ans = 360;
    for (int i = 0; i < n; ++i) {
      if (i == n - 1) {
        id1 = 0;
        id2 = n - 1;
      } else {
        id1 = i;
        id2 = i + 1;
      }
      ang1 = ang[id2] - ang[id1];
      if (i == n - 1) {
        if (ans > ang1) ans = ang1;
      } else {
        ang1 = 360 - ang1;
        if (ans > ang1) ans = ang1;
      }
    }
  }
  cout << fixed << setprecision(9) << ans << '\n';
  return 0;
}
