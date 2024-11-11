#include <bits/stdc++.h>
using namespace std;
int main() {
  double x1, y1, r1, x2, y2, r2;
  cin >> x1 >> y1 >> r1;
  cin >> x2 >> y2 >> r2;
  double dist = hypot(x1 - x2, y1 - y2);
  if (dist < r1 + r2)
    printf("%.8lf\n", max(0., (max(r1, r2) - dist - min(r1, r2)) / 2.));
  else
    printf("%.8lf\n", (dist - r1 - r2) / 2.);
  return 0;
}
