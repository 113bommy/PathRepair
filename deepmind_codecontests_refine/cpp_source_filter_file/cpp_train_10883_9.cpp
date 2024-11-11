#include <bits/stdc++.h>
using namespace std;
int const N = (1e5) + 5;
vector<long long> x, y, r;
vector<pair<double, double>> seg;
int n;
double alpha(double dx, double dy, double dist) {
  double angle = acos(dx / dist);
  if (dy < 0) {
    angle = 2 * acos(-1.) - angle;
  }
  return angle;
}
int main() {
  long long x0, y0, v, T;
  cin >> x0 >> y0 >> v >> T;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int xi, yi, ri;
    scanf("%d %d %d", &xi, &yi, &ri);
    x.push_back(xi), y.push_back(yi), r.push_back(ri);
  }
  double R = min(1. * v * T, 2e9);
  for (int i = 0; i < n; ++i) {
    double dx = x[i] - x0, dy = y[i] - y0;
    double dist = dx * dx + dy * dy;
    if ((x[i] - x0) * (x[i] - x0) + (y[i] - y0) * (y[i] - y0) <= r[i] * r[i]) {
      cout << 1;
      return 0;
    }
    dist = sqrt(dist);
    if (R + r[i] <= dist || r[i] == 0) {
      continue;
    }
    double ang1, ang2;
    double angl = alpha(dx, dy, dist);
    double l = dist * dist - r[i] * r[i];
    double al;
    if ((l <= (R * R)) || (dist <= R)) {
      al = asin(r[i] / dist);
    } else {
      double Cos =
          (R * R + dist * dist - (long long)r[i] * r[i]) / (2. * R * dist);
      al = acos(Cos);
    }
    ang1 = angl - al;
    ang2 = angl + al;
    if (ang1 < 0) {
      seg.push_back(make_pair(0, ang2));
      seg.push_back(make_pair(ang1 + 2. * acos(-1.), 2. * acos(-1.)));
    } else if (ang2 > 2 * acos(-1.)) {
      seg.push_back(make_pair(ang1, 2. * acos(-1.)));
      seg.push_back(make_pair(0, ang2 - 2. * acos(-1.)));
    } else {
      seg.push_back(make_pair(ang1, ang2));
    }
  }
  sort(seg.begin(), seg.end());
  double len = 0, clen = 0;
  double en = 0;
  for (int i = 0; i < seg.size(); ++i) {
    if (en >= seg[i].first) {
      if (en < seg[i].second) {
        clen += (seg[i].second - en);
        en = seg[i].second;
      }
    } else {
      len += clen;
      clen = seg[i].second - seg[i].first;
      en = seg[i].second;
    }
  }
  len += clen;
  double p = len / (2 * acos(-1.));
  cout << setprecision(9) << p << endl;
  return 0;
}
