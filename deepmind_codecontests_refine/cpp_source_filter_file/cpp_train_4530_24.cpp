#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int main() {
  int n, R, v;
  scanf("%d%d%d", &n, &R, &v);
  double ech = 2 * pi * R;
  while (n--) {
    int s, f;
    scanf("%d%d", &s, &f);
    double len = f - s;
    double cnt = floor(len / ech);
    len -= cnt * ech;
    double l = 0, r = len * 0.5 + R;
    for (int k = 1; k <= 40; k++) {
      double mid = (l + r) / 2;
      if (mid + R * sin(mid / R) >= len * 0.5)
        r = mid;
      else
        l = mid;
    }
    printf("%.12lf\n", (l + r + cnt * 2 * pi * R) / v);
  }
  return 0;
}
