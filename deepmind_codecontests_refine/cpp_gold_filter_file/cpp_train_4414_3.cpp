#include <bits/stdc++.h>
using namespace std;
const double PI = 4.0 * atan(1.0);
const double EPS = 1e-8;
const double delta = 0.5;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
bool flag;
struct point {
  double x, y;
  point(double _x = 0, double _y = 0) {
    x = _x;
    y = _y;
  }
};
struct circle {
  point c;
  double r;
  circle(point _c = point(0, 0), double _r = 0) {
    c = _c;
    r = _r;
  }
  point getpoint(double rad) {
    return point(c.x + cos(rad) * r, c.y + sin(rad) * r);
  }
};
double rad_change(double x) { return x / PI * 180; }
double angle_change(double x) { return x * PI / 180; }
int dcmp(double x) { return x < -EPS ? -1 : (x > EPS ? 1 : 0); }
bool operator<(const point& a, const point& b) {
  if (a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}
bool operator==(const point& a, const point& b) {
  return !dcmp(a.x - b.x) && !dcmp(a.y - b.y);
}
bool operator!=(const point& a, const point& b) {
  return dcmp(a.x - b.x) || dcmp(a.y - b.y);
}
point operator+(point a, point b) { return point(a.x + b.x, a.y + b.y); }
point operator-(point a, point b) { return point(a.x - b.x, a.y - b.y); }
point operator*(point a, double b) { return point(a.x * b, a.y * b); }
point operator/(point a, double b) { return point(a.x / b, a.y / b); }
double dot(point a, point b) { return a.x * b.x + a.y * b.y; }
double cross(point a, point b) { return a.x * b.y - b.x * a.y; }
double vect_len(point a) { return sqrt(dot(a, a)); }
point vect_rotate(point a, double rad) {
  return point(a.x * cos(rad) - a.y * sin(rad),
               a.x * sin(rad) + a.y * cos(rad));
}
point vect_normal(point a) {
  double L = vect_len(a);
  return point(-a.y / L, a.x / L);
}
point get_line_intersection(point p1, point p2, point p3, point p4) {
  point v = p2 - p1;
  point w = p4 - p3;
  point u = p1 - p3;
  double t = cross(w, u) / cross(v, w);
  return p1 + v * t;
}
double distance_point_line(point p, point p1, point p2) {
  point v1 = p2 - p1;
  point v2 = p - p1;
  return fabs(cross(v1, v2)) / vect_len(v1);
}
double distance_point_segment(point p, point p1, point p2) {
  if (p1 == p2) return vect_len(p - p1);
  point v1 = p2 - p1;
  point v2 = p - p1;
  point v3 = p - p2;
  if (dcmp(dot(v1, v2)) < 0)
    return vect_len(v2);
  else if (dcmp(dot(v1, v3) > 0))
    return vect_len(v3);
  else
    return fabs(cross(v1, v2)) / vect_len(v1);
}
double distance_point_circle(point p, circle A) {
  return fabs(vect_len(A.c - p) - A.r);
}
bool point_in_line(point p, point p1, point p2) {
  return dcmp(cross(p2 - p1, p - p1)) == 0;
}
double polygon_area(point p[], int n) {
  double ans = 0;
  for (int i = 2; i < n; ++i) {
    ans += cross(p[i] - p[1], p[i + 1] - p[1]);
  }
  ans /= 2;
  ans = abs(ans);
  return ans;
}
double convex_hull_perimeter(point p[], int n, point stk[]) {
  sort(p + 1, p + 1 + n);
  double ans = 0;
  int top = 0;
  for (int i = 1; i <= n; ++i) {
    while (top > 1 && cross(stk[top] - stk[top - 1], p[i] - stk[top - 1]) <= 0)
      --top;
    stk[++top] = p[i];
  }
  int m = top;
  for (int i = n - 1; i; --i) {
    while (top > m && cross(stk[top] - stk[top - 1], p[i] - stk[top - 1]) <= 0)
      --top;
    stk[++top] = p[i];
  }
  while (top > 1) {
    ans += vect_len(stk[top] - stk[top - 1]);
    --top;
  }
  return ans;
}
int convex_hull_points(point p[], int n, point stk[]) {
  sort(p + 1, p + 1 + n);
  int top = 0;
  for (int i = 1; i <= n; ++i) {
    while (top > 1 && cross(stk[top] - stk[top - 1], p[i] - stk[top - 1]) <= 0)
      --top;
    stk[++top] = p[i];
  }
  int m = top;
  for (int i = n - 1; i; --i) {
    while (top > m && cross(stk[top] - stk[top - 1], p[i] - stk[top - 1]) <= 0)
      --top;
    stk[++top] = p[i];
  }
  if (n > 1) top--;
  return top;
}
double vect_rad(point v) { return atan2(v.y, v.x); }
bool operator==(const circle& a, const circle& b) {
  return a.c == b.c && !dcmp(a.r - b.r);
}
circle circle_circumscribed(point p1, point p2, point p3) {
  double Bx = p2.x - p1.x;
  double By = p2.y - p1.y;
  double Cx = p3.x - p1.x;
  double Cy = p3.y - p1.y;
  double D = 2 * (Bx * Cy - By * Cx);
  double cx = (Cy * (Bx * Bx + By * By) - By * (Cx * Cx + Cy * Cy)) / D + p1.x;
  double cy = (Bx * (Cx * Cx + Cy * Cy) - Cx * (Bx * Bx + By * By)) / D + p1.y;
  point _c = point(cx, cy);
  double _r = vect_len(p1 - _c);
  return circle(_c, _r);
}
circle circle_inscribed(point p1, point p2, point p3) {
  double a = vect_len(p2 - p3);
  double b = vect_len(p3 - p1);
  double c = vect_len(p1 - p2);
  point p = (p1 * a + p2 * b + p3 * c) / (a + b + c);
  return circle(p, distance_point_line(p, p1, p2));
}
int get_circle_circle_intersection(circle c1, circle c2, point p[]) {
  int cnt = 0;
  if (dcmp(c1.r - c2.r) < 0) swap(c1, c2);
  double d = vect_len(c1.c - c2.c);
  if (!dcmp(d)) {
    if (c1 == c2) return -1;
    return 0;
  }
  double rdiff = c1.r - c2.r;
  double rsum = c1.r + c2.r;
  if (dcmp(rsum - d) < 0) return 0;
  if (dcmp(rdiff - d) > 0) return 0;
  double a = vect_rad(c2.c - c1.c);
  if (!dcmp(rdiff - d) || !dcmp(rsum - d)) {
    point p1 = c1.getpoint(a);
    p[cnt] = p1;
    ++cnt;
    return cnt;
  }
  double da = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (c1.r * d * 2));
  point p1 = c1.getpoint(a - da);
  point p2 = c1.getpoint(a + da);
  p[cnt] = p1;
  ++cnt;
  p[cnt] = p2;
  ++cnt;
  return cnt;
}
int get_circle_tangents(circle A, circle B, point a[], point b[]) {
  int cnt = 0;
  if (dcmp(A.r - B.r) < 0) {
    swap(A, B);
    swap(a, b);
  }
  double d2 = sqrt((A.c.x - B.c.x) * (A.c.x - B.c.x) +
                   (A.c.y - B.c.y) * (A.c.y - B.c.y));
  double rdiff = A.r - B.r;
  double rsum = A.r + B.r;
  if (dcmp(d2 - rdiff) < 0) return 0;
  double base = atan2(B.c.y - A.c.y, B.c.x - A.c.x);
  if (A == B) return -1;
  if (!dcmp(d2 - rdiff)) {
    a[cnt] = A.getpoint(base);
    b[cnt] = B.getpoint(base);
    ++cnt;
    return 1;
  }
  double ang = acos((A.r - B.r) / d2);
  a[cnt] = A.getpoint(base + ang);
  b[cnt] = B.getpoint(base + ang);
  ++cnt;
  a[cnt] = A.getpoint(base - ang);
  b[cnt] = B.getpoint(base - ang);
  ++cnt;
  if (!dcmp(d2 - rsum)) {
    a[cnt] = A.getpoint(base);
    b[cnt] = B.getpoint(base);
    ++cnt;
  } else if (dcmp(d2 - rsum) > 0) {
    ang = acos((A.r + B.r) / d2);
    a[cnt] = A.getpoint(base + ang);
    b[cnt] = B.getpoint(PI + base + ang);
    ++cnt;
    a[cnt] = A.getpoint(base - ang);
    b[cnt] = B.getpoint(PI + base - ang);
    ++cnt;
  }
  return cnt;
}
int point_in_cicle(point x, circle y) {
  double d2 = vect_len(x - y.c);
  if (dcmp(d2 - y.r) > 0)
    return 0;
  else if (!dcmp(d2 - y.r))
    return -1;
  return 1;
}
circle C[3];
point P;
double f(point p) {
  double ans = 0;
  double an[3];
  for (int i = 0; i < 3; ++i) {
    an[i] = vect_len(C[i].c - p) / C[i].r;
  }
  for (int i = 0; i < 3; ++i) {
    ans += (an[i] - an[(i + 1) % 3]) * (an[i] - an[(i + 1) % 3]);
  }
  return ans;
}
double T = 1;
int main() {
  scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf", &C[0].c.x, &C[0].c.y, &C[0].r,
        &C[1].c.x, &C[1].c.y, &C[1].r, &C[2].c.x, &C[2].c.y, &C[2].r);
  P.x = (C[0].c.x + C[1].c.x + C[2].c.x) / 3;
  P.y = (C[0].c.y + C[1].c.y + C[2].c.y) / 3;
  while (T > EPS) {
    double temp = f(P);
    flag = false;
    for (int i = 0; i < 4; ++i) {
      point new_p = P;
      new_p.x += dx[i] * T;
      new_p.y += dy[i] * T;
      double new_temp = f(new_p);
      if (dcmp(new_temp - temp) < 0) {
        P = new_p;
        temp = new_temp;
        flag = true;
        break;
      }
    }
    if (!flag) {
      T *= delta;
    }
  }
  if (f(P) < 1e-5) {
    printf("%.5lf %.5lf\n", P.x, P.y);
  }
  return 0;
}
