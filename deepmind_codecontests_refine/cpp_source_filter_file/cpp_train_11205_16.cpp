#include <bits/stdc++.h>
using namespace std;
int m, n, j, k, l, i, o, p, __t;
double dis0, dis1, ANS;
struct point {
  double x, y;
  double dis(point a) {
    return sqrt((a.x - x) * (a.x - x) + (a.y - y) * (a.y - y));
  }
  void init() { scanf("%lf%lf", &x, &y); }
  point(double _x, double _y) { x = _x, y = _y; }
  point() { x = 0, y = 0; }
} cinema, house, shop;
double check(point P) {
  double dis = P.dis(cinema);
  double ans = 0;
  int tag = 0;
  if (P.dis(cinema) + P.dis(shop) < dis0 &&
      P.dis(cinema) + P.dis(house) < dis1) {
    ANS = max(ans, min(dis0 - P.dis(shop), dis1 - P.dis(house)));
    return min(dis0 - P.dis(shop), dis1 - P.dis(house));
  }
  for (double l = 0, r = P.dis(cinema);;) {
    double mid = (l + r) / 2;
    tag++;
    point N = point(cinema.x + mid / dis * (P.x - cinema.x),
                    cinema.y + mid / dis * (P.y - cinema.y));
    if (dis0 - N.dis(shop) - mid > 0 && dis1 - N.dis(house) - mid > 0)
      l = mid, ans = l;
    else
      r = mid;
    if (tag == 100) break;
  }
  ANS = max(ans, ANS);
  return ans;
}
int main() {
  scanf("%lf%lf", &dis0, &dis1);
  cinema.init();
  house.init();
  shop.init();
  dis0 += cinema.dis(shop) + shop.dis(house);
  dis1 += cinema.dis(house);
  if (dis0 - (dis1 + house.dis(shop) + shop.dis(house)) > -1e-10) {
    printf("%lf\n", dis1);
    return 0;
  }
  if (dis1 - (cinema.dis(shop) + shop.dis(house)) > -1e-10) {
    printf("%lf\n", min(dis0, dis1));
    return 0;
  }
  dis0 -= shop.dis(house);
  dis0 += 1e-8;
  dis1 += 1e-8;
  double lef = 0, rig = 1;
  for (int i = 1; i <= 300; i++) {
    double l = (lef * 2 + rig) / 3, r = (lef + rig * 2) / 3;
    point p1 = point(shop.x * l + house.x * (1.0 - l),
                     shop.y * l + house.y * (1.0 - l));
    point p2 = point(shop.x * r + house.x * (1.0 - r),
                     shop.y * r + house.y * (1.0 - r));
    if (check(p1) > check(p2))
      rig = r;
    else
      lef = l;
  }
  printf("%.4lf\n", ANS);
}
