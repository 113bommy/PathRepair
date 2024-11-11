#include <bits/stdc++.h>
using namespace std;
struct Point {
  double x;
  double y;
  Point() : x(0), y(0) {}
  Point(double gx, double gy) : x(gx), y(gy) {}
};
bool operator<(const Point &p1, const Point &p2) {
  if (p1.x != p2.x) return p1.x < p2.x;
  return p1.y < p2.y;
}
Point tri[110][3];
Point fInter;
bool sInter;
bool chk(double a, double b, double c) {
  double mx = min(b, c);
  double Mx = max(b, c);
  if (a < mx || a > Mx) return false;
  return true;
}
void intersection(Point p1, Point p2, Point p3, Point p4) {
  sInter = true;
  double A1 = p1.y - p2.y;
  double B1 = p2.x - p1.x;
  double C1 = A1 * (p1.x) + B1 * (p1.y);
  double A2 = p3.y - p4.y;
  double B2 = p4.x - p3.x;
  double C2 = A2 * (p3.x) + B2 * (p3.y);
  double D = A1 * B2 - A2 * B1;
  double Dx = C1 * B2 - C2 * B1;
  double Dy = A1 * C2 - A2 * C1;
  if (D == 0) {
    sInter = false;
  } else {
    fInter.x = Dx / D;
    fInter.y = Dy / D;
    if (!chk(fInter.x, p1.x, p2.x) || !chk(fInter.y, p1.y, p2.y) ||
        !chk(fInter.x, p3.x, p4.x) || !chk(fInter.y, p3.y, p4.y))
      sInter = false;
  }
}
Point midPoint;
double cross(Point a, Point b) {
  double take = (a.x * b.y) - (a.y * b.x);
  if (take < 1e-5 && take > -1e-5) take = 0;
  return take;
}
int n;
int I, J;
bool inside() {
  Point AB, AC, AM;
  for (int t = 0; t < n; t++) {
    AB.x = tri[t][1].x - tri[t][0].x;
    AB.y = tri[t][1].y - tri[t][0].y;
    AC.x = tri[t][2].x - tri[t][0].x;
    AC.y = tri[t][2].y - tri[t][0].y;
    AM.x = midPoint.x - tri[t][0].x;
    AM.y = midPoint.y - tri[t][0].y;
    double g1 = cross(AM, AB);
    double g2 = cross(AM, AC);
    if (g1 < 0 && g2 > 0 || g1 > 0 && g2 < 0) {
      AB.x = tri[t][0].x - tri[t][1].x;
      AB.y = tri[t][0].y - tri[t][1].y;
      AC.x = tri[t][2].x - tri[t][1].x;
      AC.y = tri[t][2].y - tri[t][1].y;
      AM.x = midPoint.x - tri[t][1].x;
      AM.y = midPoint.y - tri[t][1].y;
      g1 = cross(AM, AB);
      g2 = cross(AM, AC);
      if (g1 < 0 && g2 > 0 || g1 > 0 && g2 < 0) return true;
    }
  }
  return false;
}
double dist(Point a, Point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lf%lf", &tri[i][0].x, &tri[i][0].y);
    scanf("%lf%lf", &tri[i][1].x, &tri[i][1].y);
    scanf("%lf%lf", &tri[i][2].x, &tri[i][2].y);
  }
  double ret = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      vector<Point> vp;
      for (int t = 0; t < n; t++) {
        for (int p = 0; p < 3; p++) {
          if (i == t && j == p) continue;
          intersection(tri[i][j], tri[i][(j + 1) % 3], tri[t][p],
                       tri[t][(p + 1) % 3]);
          if (sInter) {
            vp.push_back(fInter);
          }
        }
      }
      sort(vp.begin(), vp.end());
      double pret = ret;
      I = i;
      J = j;
      for (int t = 0; t < vp.size() - 1; t++) {
        if (fabs(vp[t].x - vp[(t + 1) % vp.size()].x) <= 1e-9 &&
            fabs(vp[t].y - vp[(t + 1) % vp.size()].y) <= 1e-9)
          continue;
        midPoint.x = (vp[t].x + vp[(t + 1) % vp.size()].x) / 2;
        midPoint.y = (vp[t].y + vp[(t + 1) % vp.size()].y) / 2;
        if (!inside()) ret += dist(vp[t], vp[(t + 1) % vp.size()]);
      }
    }
  }
  printf("%.10lf\n", ret);
  return 0;
}
