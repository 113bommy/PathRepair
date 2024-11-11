#include <bits/stdc++.h>
using namespace std;
int sgn(double x) {
  if (fabs(x) < 1e-5)
    return 0;
  else
    return ((x < 0) ? -1 : 1);
}
struct Point {
  double x, y;
  Point() { x = y = 0.; }
  Point(double xx, double yy) { x = xx, y = yy; }
  void print() { printf("(%.3f,%.3f)", x, y); }
} p[5007];
bool operator<(const Point &a, const Point &b) {
  if (sgn(a.x - b.x) == 0)
    return sgn(a.y - b.y) < 0;
  else
    return sgn(a.x - b.x) < 0;
}
struct Vector {
  double x, y;
  Vector(const Point &s, const Point &t) {
    x = t.x - s.x;
    y = t.y - s.y;
  }
  double tan() { return atan2(y, x); }
  double length() { return sqrt(x * x + y * y); }
};
double cross(const Vector &a, const Vector &b) { return a.x * b.y - a.y * b.x; }
bool cmp(const Point &a, const Point &b) {
  return sgn(Vector(p[0], a).tan() - Vector(p[0], b).tan()) < 0;
}
double TriangleSpace(const Point &a, const Point &b, const Point &c) {
  double la = Vector(c, a).length();
  double lb = Vector(c, b).length();
  double lc = Vector(a, b).length();
  double p = (la + lb + lc) / 2;
  return sqrt(p * (p - la) * (p - lb) * (p - lc));
}
double Line2PointDist(const Point &x, const Point &la, const Point &lb) {
  double s = TriangleSpace(x, la, lb);
  return s * 2 / Vector(la, lb).length();
}
Point st[5007];
int top;
int main() {
  int n;
  double s;
  scanf("%d%lf", &n, &s);
  for (int i = 0; i < n; i++) {
    scanf("%lf%lf", &(p[i].x), &(p[i].y));
    if (p[i] < p[0]) swap(p[0], p[i]);
  }
  sort(p + 1, p + n, cmp);
  p[n] = p[0];
  top = 0;
  st[top++] = p[0];
  st[top++] = p[1];
  for (int i = 2; i <= n; i++) {
    while (top > 1) {
      if (sgn(cross(Vector(st[top - 2], st[top - 1]),
                    Vector(st[top - 1], p[i]))) > 0) {
        break;
      }
      top--;
    }
    st[top++] = p[i];
  }
  top--;
  int i = 0;
  int j = i + 1;
  int k = j + 1;
  double ansSpace = -1;
  int ansi, ansj, ansk;
  while (true) {
    double MaxSpace = TriangleSpace(st[i], st[j], st[k]);
    while (true) {
      while (true) {
        int nk = (k + 1) % top;
        double nMaxSpace = TriangleSpace(st[i], st[j], st[nk]);
        if (sgn(nMaxSpace - MaxSpace) > 0) {
          k = nk;
          MaxSpace = nMaxSpace;
        } else {
          break;
        }
      }
      int nj = (j + 1) % top;
      double nMaxSpace = TriangleSpace(st[i], st[nj], st[k]);
      if (sgn(nMaxSpace - MaxSpace) > 0) {
        j = nj;
        MaxSpace = nMaxSpace;
      } else {
        break;
      }
    }
    if (sgn(ansSpace - MaxSpace) < 0) {
      ansSpace = MaxSpace;
      ansi = i;
      ansj = j, ansk = k;
    }
    i++;
    if (i == j) {
      j = (j + 1) % top;
    }
    if (j == k) {
      k = (k + 1) % top;
    }
    if (i == n) {
      break;
    }
  }
  Point p1(st[ansi].x + st[ansj].x - st[ansk].x,
           st[ansi].y + st[ansj].y - st[ansk].y);
  Point p2(st[ansj].x + st[ansk].x - st[ansi].x,
           st[ansj].y + st[ansk].y - st[ansi].y);
  Point p3(st[ansk].x + st[ansi].x - st[ansj].x,
           st[ansk].y + st[ansi].y - st[ansj].y);
  printf("%ld %ld\n%ld %ld\n%ld %ld\n", lrint(p1.x), lrint(p1.y), lrint(p2.x),
         lrint(p2.y), lrint(p3.x), lrint(p3.y));
  return 0;
}
