#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int n, m;
int a[400][400];
pair<double, double> c[400][400][2];
pair<double, double> b[400];
pair<double, double> td[400];
int bi;
double dab[400];
double ccw(pair<double, double> x, pair<double, double> y,
           pair<double, double> z) {
  return (y.first - x.first) * (z.second - x.second) -
         (y.second - x.second) * (z.first - x.first);
}
int cross(pair<double, double> a1, pair<double, double> a2,
          pair<double, double> b1, pair<double, double> b2) {
  if (ccw(a1, a2, b2) * ccw(a1, a2, b1) <= 0 &&
      ccw(b1, b2, a1) * ccw(b1, b2, a2) <= 0)
    return 1;
  return 0;
}
void projection(tuple<double, double, double> &x) {
  if (get<2>(x) != 0) {
    x = tuple<double, double, double>(get<0>(x) / get<2>(x),
                                      get<1>(x) / get<2>(x), 1);
  }
}
pair<double, double> crossjum(pair<double, double> a1, pair<double, double> a2,
                              pair<double, double> b1,
                              pair<double, double> b2) {
  tuple<double, double, double> p1 =
      tuple<double, double, double>(b2.second - b1.second, -1, b1.second);
  tuple<double, double, double> p2 = tuple<double, double, double>(
      a2.second - a1.second, a1.first - a2.first,
      a1.second * a2.first - a1.first * a2.second);
  tuple<double, double, double> p3 = tuple<double, double, double>(
      get<1>(p1) * get<2>(p2) - get<2>(p1) * get<1>(p2),
      get<2>(p1) * get<0>(p2) - get<0>(p1) * get<2>(p2),
      get<0>(p1) * get<1>(p2) - get<1>(p1) * get<0>(p2));
  projection(p3);
  return pair<double, double>(get<0>(p3), get<1>(p3));
}
int isdequal(double x, double y) {
  if (abs(x - y) < 1e-12) return 1;
  return 0;
}
int isequal(pair<double, double> x, pair<double, double> y) {
  if (abs(x.first - y.first) < 1e-12 && abs(x.second - y.second) < 1e-12)
    return 1;
  return 0;
}
int sameline(pair<double, double> a1, pair<double, double> a2,
             pair<double, double> b1, pair<double, double> b2) {
  if (isdequal(ccw(a1, a2, b2) * ccw(a1, a2, b1), 0) &&
      isdequal(ccw(b1, b2, a1) * ccw(b1, b2, a2), 0) &&
      isdequal((a2.second - a1.second) * (b2.first - b1.first),
               (a2.first - a1.first) * (b2.second - b1.second)))
    return 1;
  return 0;
}
int main() {
  int i, j, k;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) {
    for (j = 0; j <= m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      c[i][j][0] = pair<double, double>(0., (double)a[i][j]);
      c[i][j][1] = pair<double, double>(1., (double)a[i][j + 1]);
    }
  }
  for (i = 0; i < m; i++) {
    bi = 4;
    b[0] = pair<double, double>(0., 1001.);
    b[1] = pair<double, double>(0., 0.);
    b[2] = pair<double, double>(1., 0.);
    b[3] = pair<double, double>(1., 1001.);
    for (j = 0; j < n; j++) {
      pair<double, double> d1, d2;
      int di1 = -1, di2 = -1;
      for (k = 0; k < bi - 1; k++) {
        if (sameline(b[k], b[k + 1], c[j][i][0], c[j][i][1])) {
          di1 = -1;
          break;
        }
        if (cross(b[k], b[k + 1], c[j][i][0], c[j][i][1])) {
          if (di1 == -1) {
            d1 = crossjum(b[k], b[k + 1], c[j][i][0], c[j][i][1]);
            di1 = k;
          } else {
            d2 = crossjum(b[k], b[k + 1], c[j][i][0], c[j][i][1]);
            di2 = k;
          }
        }
      }
      if (di1 == -1) continue;
      if (isequal(d1, d2)) continue;
      double area = 0;
      area += d1.first * b[di1 + 1].second - d1.second * b[di1 + 1].first;
      for (k = di1 + 1; k < di2; k++) {
        area += b[k].first * b[k + 1].second - b[k].second * b[k + 1].first;
      }
      area += b[di2].first * d2.second - b[di2].second * d2.first;
      area += d2.first * d1.second - d2.second * d1.first;
      area /= 2;
      area = abs(area);
      dab[j] += area;
      int tdi = 0;
      for (k = 0; k <= di1; k++) td[tdi++] = b[k];
      td[tdi++] = d1;
      td[tdi++] = d2;
      for (k = di2 + 1; k < bi; k++) td[tdi++] = b[k];
      bi = tdi;
      for (k = 0; k < bi; k++) b[k] = td[k];
    }
  }
  for (i = 0; i < n; i++) {
    printf("%lf\n", dab[i]);
  }
  return 0;
}
