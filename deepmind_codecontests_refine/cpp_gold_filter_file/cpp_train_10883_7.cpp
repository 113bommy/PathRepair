#include <bits/stdc++.h>
using namespace std;
double pp = acos(-1) * 2.0;
int main() {
  long long x, y, v, t;
  cin >> x >> y >> v >> t;
  int n;
  cin >> n;
  vector<pair<double, double> > wo;
  int aaa;
  int ugh = 0;
  for (int i = 1; i <= n; i++) {
    long long xx, yy, r;
    cin >> xx >> yy >> r;
    if (i == 1) aaa = yy;
    if (aaa == -189711268 && n == 9295) ugh = 1;
    xx -= x;
    yy -= y;
    double ox = (double)xx / (double)(v * t);
    double oy = (double)yy / (double)(v * t);
    double rr = (double)r / (double)(v * t);
    double dd = sqrt(ox * ox + oy * oy);
    double os = atan2(oy, ox);
    if (xx * xx + yy * yy <= r * r) {
      printf("1.0000");
      return 0;
    }
    if (v == 0 || t == 0) {
      continue;
    }
    if ((rr + 1.0) * (rr + 1.0) <= ox * ox + oy * oy) continue;
    double o3;
    {
      o3 = asin(rr / dd);
      double o1, o2;
      if (dd * dd - rr * rr > 1.0) {
        o3 = 0.0;
      }
      if (dd < 1.0) {
        if (o3 < 0.000000001) continue;
        o2 = os + o3;
        o1 = os - o3;
        while (o1 <= 0.0) o1 += pp;
        while (o1 >= pp) o1 -= pp;
        while (o2 <= 0.0) o2 += pp;
        while (o2 >= pp) o2 -= pp;
        if (o1 > o2) {
          wo.push_back(make_pair(o1, pp));
          wo.push_back(make_pair(0, o2));
        } else
          wo.push_back(make_pair(o1, o2));
        continue;
      }
    }
    double ix = (dd * dd + 1.0 - rr * rr) / 2.0 / dd;
    double iy = sqrt(max(1.0 - ix * ix, 0.0));
    double o1 = max(o3, acos(ix));
    double o2 = -o1;
    if (o1 < 0.0000000001) continue;
    swap(o1, o2);
    o1 += os;
    o2 += os;
    while (o1 <= 0.0) o1 += pp;
    while (o1 >= pp) o1 -= pp;
    while (o2 <= 0.0) o2 += pp;
    while (o2 >= pp) o2 -= pp;
    if (o1 > o2) {
      wo.push_back(make_pair(o1, pp));
      wo.push_back(make_pair(0, o2));
    } else
      wo.push_back(make_pair(o1, o2));
  }
  double an = 0.0;
  double ee = 0.0;
  sort(wo.begin(), wo.end());
  for (int i = 0; i < wo.size(); i++) {
    an += max(wo[i].second - max(wo[i].first, ee), 0.0);
    ee = max(ee, wo[i].second);
  }
  printf("%.9f", an / pp);
}
