#include <bits/stdc++.h>
using namespace std;
struct Point {
  double x, y;
  Point(double ix = 0, double iy = 0) {
    x = ix;
    y = iy;
  }
};
inline Point operator+(Point a, Point b) { return Point(a.x + b.x, a.y + b.y); }
inline Point operator-(Point a, Point b) { return Point(a.x - b.x, a.y - b.y); }
inline double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
const int N = 10004;
const double PI = acos(-1.0);
const double EPS = 1e-9;
Point p[N];
double area[N];
int n, q, nxt[N], prv[N];
inline int func(int i, int j, Point dir) {
  double tmp = (p[j].x - p[i].x) * dir.x + (p[j].y - p[i].y) * dir.y;
  if (abs(tmp) < EPS) return 0;
  if (tmp > 0) return 1;
  return -1;
}
inline bool isExtreme(int i, Point dir) {
  if (func(prv[i], i, dir) >= 0 && func(i, nxt[i], dir) == -1) return true;
  if (func(prv[i], i, dir) == 1 && func(i, nxt[i], dir) <= 0) return true;
  return false;
}
inline int getExtreme(double ang) {
  Point dir(cos(ang), sin(ang));
  if (isExtreme(0, dir)) return 0;
  if (isExtreme(1, dir)) return 1;
  if (func(0, 1, dir) == -1) {
    int lo = 0, hi = n - 1;
    while (lo < hi) {
      int mi = (lo + hi) / 2;
      if (isExtreme(mi, dir)) return mi;
      int tmp = func(mi, nxt[mi], dir);
      if (tmp >= 0) {
        lo = mi + 1;
      } else {
        if (func(0, mi, dir) == -1) {
          lo = mi + 1;
        } else {
          hi = mi;
        }
      }
    }
    return lo;
  } else if (func(0, 1, dir) == 1) {
    int lo = 0, hi = n - 1;
    while (lo < hi) {
      int mi = (lo + hi) / 2;
      if (isExtreme(mi, dir)) return mi;
      int tmp = func(mi, nxt[mi], dir);
      if (tmp <= 0) {
        hi = mi;
      } else {
        if (func(0, mi, dir) == 1) {
          lo = mi + 1;
        } else {
          hi = mi;
        }
      }
    }
    return lo;
  } else {
    int lo = 0, hi = n - 1;
    while (lo < hi) {
      int mi = (lo + hi) / 2;
      if (isExtreme(mi, dir)) return mi;
      int tmp = func(mi, nxt[mi], dir);
      if (tmp == 1) {
        lo = mi + 1;
      } else {
        hi = mi;
      }
    }
    return lo;
  }
}
inline double getArea(Point a, Point b) {
  return (b.x - a.x) * (b.y + a.y) / 2;
}
inline double getAreaRange(int l, int r) {
  if (l == r) return 0.0;
  if (l < r) {
    if (l > 0) {
      return area[r - 1] - area[l - 1];
    } else {
      return area[r - 1];
    }
  }
  if (r == 0) return area[n - 1] - area[l - 1];
  return area[n - 1] - area[l - 1] + area[r - 1];
}
inline bool getIntersection(Point a, Point b, Point c, Point d, Point &p) {
  double a11 = b.x - a.x;
  double a12 = c.x - d.x;
  double a21 = b.y - a.y;
  double a22 = c.y - d.y;
  double det = a11 * a22 - a12 * a21;
  if (abs(det) < EPS) return false;
  double s = ((c.x - a.x) * a22 - (c.y - a.y) * a12) / det;
  double t = ((c.y - a.y) * a11 - (c.x - a.x) * a21) / det;
  p.x = a.x + (b.x - a.x) * s;
  p.y = a.y + (b.y - a.y) * s;
  return true;
}
inline double getAreaDiff(double x, double y, double ang) {
  int a = getExtreme(ang - PI / 2);
  int b = getExtreme(ang + PI / 2);
  Point center(x, y);
  Point u, v;
  int up, dw;
  {
    int lo = a, hi = b;
    Point dir(cos(ang), sin(ang));
    while (lo != hi) {
      int mi;
      if (lo < hi) {
        mi = (lo + hi + 1) / 2;
      } else {
        mi = (lo + hi + n + 1) / 2;
        if (mi >= n) mi -= n;
      }
      double tmp = cross(p[mi] - center, dir);
      if (tmp < 0) {
        hi = prv[mi];
      } else {
        lo = mi;
      }
    }
    up = lo;
    getIntersection(p[up], p[nxt[up]], center, center + dir, u);
  }
  {
    int lo = b, hi = a;
    Point dir(-cos(ang), -sin(ang));
    while (lo != hi) {
      int mi;
      if (lo < hi) {
        mi = (lo + hi + 1) / 2;
      } else {
        mi = (lo + hi + n + 1) / 2;
        if (mi >= n) mi -= n;
      }
      double tmp = cross(p[mi] - center, dir);
      if (tmp < 0) {
        hi = prv[mi];
      } else {
        lo = mi;
      }
    }
    dw = lo;
    getIntersection(p[dw], p[nxt[dw]], center, center + dir, v);
  }
  double tot = 0.0;
  tot += getAreaRange(nxt[up], dw) + getArea(p[dw], v) + getArea(v, u) +
         getArea(u, p[nxt[up]]);
  tot -= getAreaRange(nxt[dw], up) + getArea(p[up], u) + getArea(u, v) +
         getArea(v, p[nxt[dw]]);
  return tot;
}
inline double query(double x, double y) {
  double lo = -PI / 2;
  double hi = +PI / 2;
  double areadifflo = getAreaDiff(x, y, lo);
  for (int it = 0; it < 30; it++) {
    double mi = (lo + hi) / 2;
    double tmp = getAreaDiff(x, y, mi);
    if (abs(tmp) < EPS) {
      if (mi < 0) return mi + PI;
      return mi;
    }
    if (areadifflo > 0) {
      if (tmp < 0) {
        hi = mi;
      } else {
        lo = mi;
        areadifflo = tmp;
      }
    } else {
      if (tmp < 0) {
        lo = mi;
        areadifflo = tmp;
      } else {
        hi = mi;
      }
    }
  }
  if (lo < 0) return lo + PI;
  return lo;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
    nxt[i] = (i + 1 < n) ? (i + 1) : 0;
    prv[nxt[i]] = i;
  }
  reverse(p, p + n);
  for (int i = 0; i < n; i++) {
    area[i] = getArea(p[i], p[nxt[i]]);
    if (i > 0) area[i] += area[i - 1];
  }
  while (q--) {
    double x, y;
    cin >> x >> y;
    cout << setprecision(30) << query(x, y) << '\n';
  }
  return 0;
}
