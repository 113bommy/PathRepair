#include <bits/stdc++.h>
const double pi = acos(-1);
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int MAXN = 1e5 + 5;
const double eps = 1e-9;
using namespace std;
int main() {
  int x, y, z;
  scanf("%d", &(x)), scanf("%d", &(y)), scanf("%d", &(z));
  if (z > 90) z = 180 - z;
  if (z == 0) return !printf("%I64d\n", ((long long)x * (long long)y));
  if (x < y) swap(x, y);
  if (z == 90) return !printf("%I64d\n", ((long long)y * (long long)y));
  double w = x, h = y, a = z * pi / 180.;
  double ans = w * h;
  double x1 = (-cos(a) * w - sin(a) * h) * 0.5;
  double y1 = (-sin(a) * w + cos(a) * h) * 0.5;
  double x2 = (cos(a) * w - sin(a) * h) * 0.5;
  double y2 = (sin(a) * w + cos(a) * h) * 0.5;
  double x3 = (-cos(a) * w + sin(a) * h) * 0.5;
  double y3 = (-sin(a) * w - cos(a) * h) * 0.5;
  if (a <= atan2(h, w) * 2) {
    double x4 = ((y2 - h / 2.) * x1 + (h / 2. - y1) * x2) / (y2 - y1) + w / 2.;
    double y4 = h / 2. - ((x2 + w / 2.) * y1 - (w / 2. + x1) * y2) / (x2 - x1);
    double x5 = ((y3 + h / 2.) * x1 - (h / 2. + y1) * x3) / (y3 - y1) + w / 2.;
    double y5 = ((x3 + w / 2.) * y1 - (w / 2. + x1) * y3) / (x3 - x1) + h / 2.;
    ans -= x4 * y4 + x5 * y5;
  } else {
    double x4 = ((y2 - h / 2.) * x1 + (h / 2. - y1) * x2) / (y2 - y1) + w / 2.;
    double x5 = ((y2 + h / 2.) * x1 - (h / 2. + y1) * x2) / (y2 - y1) + w / 2.;
    ans -= h * (x4 + x5);
  }
  printf("%.15f\n", ans);
  return 0;
}
