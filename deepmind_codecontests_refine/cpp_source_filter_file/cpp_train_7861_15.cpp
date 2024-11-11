#include <bits/stdc++.h>
using namespace std;
struct point {
  double x, y, vl;
  bool operator<(const point &temp) const { return vl < temp.vl; }
};
point pt[110001];
int n, l[22222], r[22222];
double a, ans;
int main() {
  int i, j, s, p, q;
  double xx, yy, k, b, dis;
  scanf("%d%lf", &n, &a);
  for (i = 0; i < n; i++) scanf("%lf%lf", &pt[i].x, &pt[i].y);
  ans = 4 * a * a;
  for (i = 0; i < n; i++) {
    double A = 0.5 * (pt[i].y * pt[i].y + a * a - pt[i].x * pt[i].x),
           B = -pt[i].x * pt[i].y,
           C = 0.5 * (pt[i].y * pt[i].y + a * a + pt[i].x * pt[i].x);
    pt[i].vl = 4 * (C - sqrt(A * A + B * B));
  }
  sort(pt, pt + n);
  for (i = 0; i < n && i <= 400; i++) {
    if (pt[i].vl >= ans) break;
    for (j = i; j < n; j++) {
      dis = (pt[j].x * pt[i].y - pt[i].x * pt[j].y);
      dis = dis * dis + a * a * (pt[j].x - pt[i].x) * (pt[j].x - pt[i].x);
      dis /= ((pt[i].x - pt[j].x) * (pt[i].x - pt[j].x) +
              (pt[i].y - pt[j].y) * (pt[i].y - pt[j].y));
      if (ans > 4 * dis) ans = 4 * dis;
    }
  }
  printf("%.20f\n", sqrt(ans));
}
