#include <bits/stdc++.h>
using namespace std;
int n;
struct Point {
  double x, y;
  Point(double xx = 0, double yy = 0) : x(xx), y(yy) {}
  void Rotate() {
    *this = Point(x * cos(.1) - y * sin(.1), x * sin(.1) + y * cos(.1));
  }
};
inline int sgn(double a) {
  if (-1e-7 < a && a < 1e-7) return 0;
  return a > 0 ? 1 : -1;
}
inline Point operator-(const Point &a, const Point &b) {
  return Point(a.x - b.x, a.y - b.y);
}
inline Point operator+(const Point &a, const Point &b) {
  return Point(a.x + b.x, a.y + b.y);
}
inline Point operator*(const Point &a, double b) {
  return Point(a.x * b, a.y * b);
}
inline double operator*(const Point &a, const Point &b) {
  return a.x * b.x + a.y * b.y;
}
inline double operator%(const Point &a, const Point &b) {
  return a.x * b.y - a.y * b.x;
}
struct Line {
  Point p, v;
  Line(const Point &a, const Point &b) : p(a), v(b - a) {}
};
inline Point operator*(const Line &a, const Line &b) {
  return a.p + a.v * ((a.p - b.p) % b.v / -(a.v % b.v));
}
inline bool operator<(const Point &a, Line l) {
  return sgn(l.v * (a - l.p)) >= 0 && sgn(l.v * (a - (l.p + l.v))) <= 0;
}
Point rect[522][4], _rect[522][4];
vector<double> xlist;
pair<double, double> Cut(Point *rect, double x) {
  double maxx = -1000000000, minx = 1000000000;
  for (int k = 0; k < 4; k++)
    maxx = max(maxx, rect[k].x), minx = min(minx, rect[k].x);
  if (x > maxx || x < minx) return (make_pair(1000000000, -1000000000));
  pair<double, double> res = make_pair(-1000000000, 1000000000);
  Line cutL(Point(x, 0), Point(x, 1));
  for (int k = 0; k < 4; k++) {
    Line l(rect[k], rect[(k + 1) % 4]);
    if (sgn(cutL.v % l.v) == 0) continue;
    Point a = cutL * l;
    if (l.v.x < 0)
      res.second = min(res.second, a.y);
    else
      res.first = max(res.first, a.y);
  }
  return res;
}
pair<double, double> ranList[522];
double Cut(double x) {
  int ranTail = 0;
  for (int i = 0; i < n; i++) {
    pair<double, double> ran = Cut(rect[i], x);
    if (ran.first < ran.second) ranList[ranTail++] = ran;
  }
  sort(ranList, ranList + ranTail);
  double res = 0;
  double lo = -1000000000, hi = -1000000000;
  for (int i = 0; i < ranTail; i++) {
    if (ranList[i].first < hi)
      hi = max(hi, ranList[i].second);
    else {
      res += hi - lo;
      lo = ranList[i].first;
      hi = ranList[i].second;
    }
  }
  res += hi - lo;
  return res;
}
bool StrictInside(Point *rect, Point p) {
  for (int k = 0; k < 4; k++)
    if ((rect[(k + 1) % 4] - rect[k]) * (p - rect[k]) < 1e-7) return false;
  return true;
}
bool Inside(Point *rect, Point p) {
  for (int k = 0; k < 4; k++)
    if ((rect[(k + 1) % 4] - rect[k]) * (p - rect[k]) < -1e-7) return false;
  return true;
}
int main() {
  double S = 0, SS = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < 4; k++) {
      scanf("%lf%lf", &rect[i][k].x, &rect[i][k].y);
      rect[i][k].Rotate();
      xlist.push_back(rect[i][k].x);
    }
    if (sgn((rect[i][1] - rect[i][0]) % (rect[i][2] - rect[i][1])) < 0)
      reverse(rect[i], rect[i] + 4);
    S += (rect[i][1] - rect[i][0]) % (rect[i][2] - rect[i][0]);
  }
  int nn = 0;
  for (int i = 0; i < n; i++) {
    bool flg = true;
    for (int j = 0; j < n; j++)
      if (i != j && rect[i][0].x == rect[j][0].x &&
          rect[i][1].x == rect[j][1].x && rect[i][2].x == rect[j][2].x &&
          rect[i][3].x == rect[j][3].x && rect[i][0].y == rect[j][0].y &&
          rect[i][1].y == rect[j][1].y && rect[i][2].y == rect[j][2].y &&
          rect[i][3].y == rect[j][3].y)
        flg = false;
    if (flg) memcpy(_rect + (nn++), rect[i], sizeof(Point) * 4);
  };
  n = nn;
  memcpy(rect, _rect, sizeof(rect));
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < 4; k++) {
      Line l1(rect[i][k], rect[i][(k + 1) % 4]);
      for (int j = (i + 1); j < (n); j++) {
        for (int l = 0; l < 4; l++) {
          Line l2(rect[j][l], rect[j][(l + 1) % 4]);
          if (sgn(l1.v % l2.v) == 0) continue;
          Point p = l1 * l2;
          if (p < l1 && p < l2) {
            bool flg = true;
            for (int l = 0; l < n; l++)
              if (StrictInside(rect[l], p)) {
                flg = false;
                break;
              }
            if (flg) xlist.push_back(p.x);
          }
        }
      }
    }
  }
  sort(xlist.begin(), xlist.end());
  xlist.resize(unique(xlist.begin(), xlist.end()) - xlist.begin());
  ;
  double last = Cut(xlist[0]);
  for (int i = (1); i < ((int)xlist.size()); i++) {
    double now = Cut(xlist[i]);
    SS += (last + now) * (xlist[i] - xlist[i - 1]) / 2.;
    last = now;
  }
  printf("%.10lf\n", S / SS);
  return 0;
}
