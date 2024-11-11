#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
const long long inf = 1 << 27;
const long long mod = 1e9 + 7;
int n;
double r, v, s, f;
double PI = acos(-1.0);
int check(double t) {
  double angle = fmod(v * t, 2 * PI * r) / (2 * r);
  return v * t + 2 * r * abs(sin(angle)) >= f - s;
}
int main() {
  scanf("%d%lf%lf", &n, &r, &v);
  while (n--) {
    scanf("%lf%lf", &s, &f);
    double l = 0, r = 1999999999999.0;
    for (int i = 0; i < 100; i++) {
      double mid = (l + r) / 2;
      if (check(mid))
        r = mid;
      else
        l = mid;
    }
    printf("%.15lf\n", l);
  }
  return 0;
}
