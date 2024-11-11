#include <bits/stdc++.h>
using namespace std;
struct point {
  double x, y;
};
double xmult(point p1, point p2, point p0) {
  return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
double dist(point p1, point p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
point intersection(point u1, point u2, point v1, point v2) {
  point ret = u1;
  double t = ((u1.x - v1.x) * (v1.y - v2.y) - (u1.y - v1.y) * (v1.x - v2.x)) /
             ((u1.x - u2.x) * (v1.y - v2.y) - (u1.y - u2.y) * (v1.x - v2.x));
  ret.x += (u2.x - u1.x) * t;
  ret.y += (u2.y - u1.y) * t;
  return ret;
}
const double eps = 1e-8;
point dot_to_circle(point c, double r, point p) {
  point u, v;
  if (dist(p, c) < eps) return p;
  u.x = c.x + r * fabs(c.x - p.x) / dist(c, p);
  u.y = c.y + r * fabs(c.y - p.y) / dist(c, p) *
                  ((c.x - p.x) * (c.y - p.y) < 0 ? -1 : 1);
  v.x = c.x - r * fabs(c.x - p.x) / dist(c, p);
  v.y = c.y - r * fabs(c.y - p.y) / dist(c, p) *
                  ((c.x - p.x) * (c.y - p.y) < 0 ? -1 : 1);
  return dist(u, p) < dist(v, p) ? u : v;
}
void intersection_line_circle(point c, double r, point l1, point l2, point& p1,
                              point& p2) {
  point p = c;
  double t;
  p.x += l1.y - l2.y;
  p.y += l2.x - l1.x;
  p = intersection(p, c, l1, l2);
  t = sqrt(r * r - dist(p, c) * dist(p, c)) / dist(l1, l2);
  p1.x = p.x + (l2.x - l1.x) * t;
  p1.y = p.y + (l2.y - l1.y) * t;
  p2.x = p.x - (l2.x - l1.x) * t;
  p2.y = p.y - (l2.y - l1.y) * t;
}
void intersection_circle_circle(point c1, double r1, point c2, double r2,
                                point& p1, point& p2) {
  point u, v;
  double t;
  t = (1 + (r1 * r1 - r2 * r2) / dist(c1, c2) / dist(c1, c2)) / 2;
  u.x = c1.x + (c2.x - c1.x) * t;
  u.y = c1.y + (c2.y - c1.y) * t;
  v.x = u.x + c1.y - c2.y;
  v.y = u.y - c1.x + c2.x;
  intersection_line_circle(c1, r1, u, v, p1, p2);
}
int n;
int sqr(int x) { return x * x; }
int cross(int a, int b, int c, int d, int e, int f) {
  if (sqr(a - d) + sqr(b - e) >= sqr(c + f)) return 0;
  if (sqr(a - d) + sqr(b - e) <= sqr(c - f)) return 0;
  return 1;
}
int a, b, c, d, e, f, g, h, i;
int ct(int a, int b, int c, int d, int e, int f) {
  if (sqr(a - d) + sqr(b - e) == sqr(c + f)) return 1;
  if (sqr(a - d) + sqr(b - e) == sqr(c - f)) return 2;
  return 0;
}
int main() {
  cin >> n;
  if (n == 1) {
    cin >> a >> b >> c;
    cout << 2;
    return 0;
  }
  if (n == 2) {
    cin >> a >> b >> c >> d >> e >> f;
    cout << 3 + cross(a, b, c, d, e, f);
    return 0;
  }
  cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;
  int ret = 4;
  if (cross(a, b, c, d, e, f) && cross(d, e, f, g, h, i) &&
      cross(g, h, i, a, b, c)) {
    ret = 8;
    double num1, num2, num3, num4, num5, num6;
    double r1, r2, r3;
    num1 = a, num2 = b, r1 = c;
    num3 = d, num4 = e, r2 = f;
    num5 = g, num6 = h, r3 = i;
    point w, ww, p1, p2;
    w.x = a, w.y = b;
    ww.x = d, ww.y = e;
    intersection_circle_circle(w, r1, ww, r2, p1, p2);
    num1 = p1.x, num2 = p1.y, num3 = p2.x, num4 = p2.y;
    if (fabs((num1 - num5) * (num1 - num5) + (num2 - num6) * (num2 - num6) -
             r3 * r3) < eps)
      ret--;
    if (fabs((num3 - num5) * (num3 - num5) + (num4 - num6) * (num4 - num6) -
             r3 * r3) < eps)
      ret--;
    cout << ret << endl;
  } else {
    ret = 4 + cross(a, b, c, d, e, f) + cross(d, e, f, g, h, i) +
          cross(g, h, i, a, b, c);
    if (ret == 6) {
      if ((ct(a, b, c, d, e, f) + 1) / 2 + (ct(d, e, f, g, h, i) + 1) / 2 +
          (ct(g, h, i, a, b, c) + 1) / 2) {
        double num1, num2, num3, num4, num5, num6;
        double r1, r2, r3;
        num1 = a, num2 = b, r1 = c;
        num3 = d, num4 = e, r2 = f;
        if (cross(a, b, c, d, e, f)) {
          point w, ww, p1, p2;
          w.x = a, w.y = b;
          ww.x = d, ww.y = e;
          intersection_circle_circle(w, r1, ww, r2, p1, p2);
          num1 = p1.x, num2 = p1.y, num3 = p2.x, num4 = p2.y;
          num5 = g, num6 = h, r3 = i;
          if (fabs((num1 - num5) * (num1 - num5) +
                   (num2 - num6) * (num2 - num6) - r3 * r3) > eps &&
              fabs((num3 - num5) * (num3 - num5) +
                   (num4 - num6) * (num4 - num6) - r3 * r3) > eps)
            ret++;
        } else if (cross(a, b, c, g, h, i)) {
          point w, ww, p1, p2;
          w.x = a, w.y = b;
          ww.x = g, ww.y = h;
          intersection_circle_circle(w, r1, ww, i, p1, p2);
          num1 = p1.x, num2 = p1.y, num3 = p2.x, num4 = p2.y;
          num5 = d, num6 = e, r3 = f;
          if (fabs((num1 - num5) * (num1 - num5) +
                   (num2 - num6) * (num2 - num6) - r3 * r3) > eps &&
              fabs((num3 - num5) * (num3 - num5) +
                   (num4 - num6) * (num4 - num6) - r3 * r3) > eps)
            ret++;
        }
      }
    } else if (ret == 5) {
      ret += ((ct(a, b, c, d, e, f) + 1) / 2 + (ct(d, e, f, g, h, i) + 1) / 2 +
              (ct(g, h, i, a, b, c) + 1) / 2) /
             2;
    }
    if (ret == 4) {
      if (ct(a, b, c, d, e, f) && ct(d, e, f, g, h, i) &&
          ct(g, h, i, a, b, c)) {
        double num1, num2, num3, num4;
        if (ct(a, b, c, d, e, f) == 1)
          num1 = a + 1.0 * (d - a) * c / (c + f),
          num2 = b + 1.0 * (e - b) * c / (c + f);
        else {
          if (c > f) {
            num1 = a + 1.0 * (d - a) * c / (c - f),
            num2 = b + 1.0 * (e - b) * c / (c - f);
          } else {
            num1 = d + 1.0 * (a - d) * f / (f - c),
            num2 = e + 1.0 * (b - e) * f / (f - c);
          }
        }
        if (ct(g, h, i, a, b, c) == 1)
          num3 = a + 1.0 * (g - a) * c / (c + i),
          num4 = b + 1.0 * (h - b) * c / (c + i);
        else {
          if (c > i) {
            num3 = a + 1.0 * (g - a) * c / (c - i),
            num4 = b + 1.0 * (h - b) * c / (c - i);
          } else {
            num3 = d + 1.0 * (a - g) * i / (i - c),
            num4 = e + 1.0 * (b - h) * i / (i - c);
          }
        }
        if (fabs(num3 - num1) > eps || fabs(num4 - num2) > eps) ret++;
      }
    }
    cout << ret << endl;
  }
  return 0;
}
