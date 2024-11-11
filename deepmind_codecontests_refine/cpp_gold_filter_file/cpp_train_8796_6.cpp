#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  double R, v;
  scanf("%d%lf%lf", &T, &R, &v);
  while (T--) {
    double s, f;
    scanf("%lf%lf", &s, &f);
    double len = f - s;
    double C = 2 * acos(-1.0) * R;
    double round = floor(len / C);
    len -= round * C;
    double l = 0, r = len * 0.5 + R;
    for (int i = 1; i <= 60; i++) {
      double mid = (l + r) * 0.5;
      if (mid + R * sin(mid / R) >= len * 0.5)
        r = mid;
      else
        l = mid;
    }
    printf("%.15lf\n", ((l + r) + C * round) / v);
  }
  return 0;
}
