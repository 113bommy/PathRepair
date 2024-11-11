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
inline double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
const int N = 100004;
const double EPS = 1e-9;
const double PI = acos(-1.0);
int n, q;
double area[N];
Point center, p[N];
inline double getArea(Point a, Point b) {
  return (b.x - a.x) * (a.y + b.y) / 2;
}
inline double getAreaRange(int l, int r) {
  if (l == r) return 0.0;
  if (l > r) r += n;
  if (l == 0) return area[r - 1];
  return area[r - 1] - area[l - 1];
}
inline bool getIntersection(Point a, Point b, Point dir, double &s, double &t) {
  double a11 = b.x - a.x;
  double a21 = b.y - a.y;
  double a12 = -dir.x;
  double a22 = -dir.y;
  double det = a11 * a22 - a12 * a21;
  if (abs(det) < EPS) return false;
  s = ((center.x - a.x) * a22 - (center.y - a.y) * a12) / det;
  t = ((center.y - a.y) * a11 - (center.x - a.x) * a21) / det;
  return true;
}
inline void getPolygonRayIntersection(Point dir, int &ind, Point &u) {
  double s, t, ss, tt;
  bool flg = getIntersection(p[0], p[1], dir, s, t);
  int lo = 0, hi = n - 1;
  if (flg) {
    if (s < 0 && t > 0) {
      while (lo < hi) {
        int mi = (lo + hi + 1) / 2;
        bool tmp = getIntersection(p[mi], p[(mi + 1) % n], dir, ss, tt);
        if (tmp) {
          if (ss > 0 && tt < 0) {
            lo = mi;
          } else if (ss < 0 && tt < 0) {
            lo = mi;
          } else if (ss > 0 && tt > 0) {
            lo = mi;
          } else {
            if (t < tt) {
              lo = mi;
            } else {
              hi = mi - 1;
            }
          }
        } else {
          lo = mi;
        }
      }
    } else if (s > 0 && t < 0) {
      while (lo < hi) {
        int mi = (lo + hi + 1) / 2;
        bool tmp = getIntersection(p[mi], p[(mi + 1) % n], dir, ss, tt);
        if (tmp) {
          if (ss < 0 && tt < 0) {
            lo = mi;
          } else if (ss > 0 && tt > 0) {
            lo = mi;
          } else if (ss < 0 && tt > 0) {
            hi = mi - 1;
          } else {
            if (t < tt) {
              lo = mi;
            } else {
              hi = mi - 1;
            }
          }
        } else {
          if (dot(p[(mi + 1) % n] - p[mi], dir) > 0) {
            lo = mi;
          } else {
            hi = mi - 1;
          }
        }
      }
    } else if (s < 0 && t < 0) {
      while (lo < hi) {
        int mi = (lo + hi + 1) / 2;
        bool tmp = getIntersection(p[mi], p[(mi + 1) % n], dir, ss, tt);
        if (tmp) {
          if (ss > 0 && tt > 0) {
            lo = mi;
          } else if (ss < 0 && tt > 0) {
            hi = mi - 1;
          } else if (ss > 0 && tt < 0) {
            hi = mi - 1;
          } else {
            if (t < tt) {
              hi = mi - 1;
            } else {
              lo = mi;
            }
          }
        } else {
          if (dot(p[(mi + 1) % n] - p[mi], dir) > 0) {
            lo = mi;
          } else {
            hi = mi - 1;
          }
        }
      }
    } else {
      while (lo < hi) {
        int mi = (lo + hi + 1) / 2;
        bool tmp = getIntersection(p[mi], p[(mi + 1) % n], dir, ss, tt);
        if (tmp) {
          if (ss < 0 && tt > 0) {
            hi = mi - 1;
          } else if (ss > 0 && tt < 0) {
            hi = mi - 1;
          } else if (ss < 0 && tt < 0) {
            hi = mi - 1;
          } else {
            if (t < tt) {
              hi = mi - 1;
            } else {
              lo = mi;
            }
          }
        } else {
          hi = mi - 1;
        }
      }
    }
  } else if (dot(p[1] - p[0], dir) > 0) {
    while (lo < hi) {
      int mi = (lo + hi + 1) / 2;
      bool tmp = getIntersection(p[mi], p[(mi + 1) % n], dir, ss, tt);
      if (tmp) {
        if (ss > 0 && tt > 0) {
          lo = mi;
        } else {
          hi = mi - 1;
        }
      } else {
        hi = mi - 1;
      }
    }
  } else {
    while (lo < hi) {
      int mi = (lo + hi + 1) / 2;
      bool tmp = getIntersection(p[mi], p[(mi + 1) % n], dir, ss, tt);
      if (tmp) {
        if (ss < 0 && tt > 0) {
          hi = mi - 1;
        } else {
          lo = mi;
        }
      } else {
        lo = mi;
      }
    }
  }
  ind = lo;
  getIntersection(p[lo], p[(lo + 1) % n], dir, s, t);
  u.x = center.x + dir.x * t;
  u.y = center.y + dir.y * t;
}
inline double getAreaDiff(double ang) {
  Point u, v;
  int up, dw;
  double cosang = cos(ang);
  double sinang = sin(ang);
  Point dir(cosang, sinang);
  getPolygonRayIntersection(dir, up, u);
  dir.x = -cosang;
  dir.y = -sinang;
  getPolygonRayIntersection(dir, dw, v);
  double ret = getAreaRange((up + 1) % n, dw) + getArea(p[dw], v) +
               getArea(v, u) + getArea(u, p[(up + 1) % n]);
  ret = ret * 2 - area[n - 1];
  return ret;
}
inline double query(double x, double y) {
  double lo = 0, hi = PI;
  center.x = x;
  center.y = y;
  double areadiffref = getAreaDiff(lo);
  if (abs(areadiffref) < EPS) return lo;
  for (int it = 0; it < 40; it++) {
    double mi = (lo + hi) / 2;
    double areadiffmi = getAreaDiff(mi);
    if (abs(areadiffmi) < EPS) return mi;
    if (areadiffref > 0) {
      if (areadiffmi > 0) {
        lo = mi;
      } else {
        hi = mi;
      }
    } else {
      if (areadiffmi < 0) {
        lo = mi;
      } else {
        hi = mi;
      }
    }
  }
  return lo;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  reverse(p, p + n);
  for (int i = 0; i < 2 * n; i++) {
    area[i] = getArea(p[i % n], p[(i + 1) % n]);
    if (i) area[i] += area[i - 1];
  }
  cout << setprecision(30);
  while (q--) {
    double x, y;
    cin >> x >> y;
    cout << query(x, y) << '\n';
  }
  return 0;
}
