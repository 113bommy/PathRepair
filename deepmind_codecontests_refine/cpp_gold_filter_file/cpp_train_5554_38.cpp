#include <bits/stdc++.h>
using namespace std;
namespace geometry {
const long double eps = 1e-12L, pi = acos(-1.0L), inf = 1e10000L;
inline int fcmp(long double x, long double y) {
  return fabs(x - y) < eps ? 0 : x < y ? -1 : 1;
}
inline long double sqr(long double x) { return x * x; }
struct vec {
  long double x, y;
  vec(void) {}
  vec(long double angle) : x(cos(angle)), y(sin(angle)) {}
  vec(long double x, long double y) : x(x), y(y) {}
  bool operator<(const vec &b) const {
    return fcmp(x, b.x) * 2 + fcmp(y, b.y) < 0;
  }
  bool operator>(const vec &b) const {
    return fcmp(x, b.x) * 2 + fcmp(y, b.y) > 0;
  }
  bool operator<=(const vec &b) const {
    return fcmp(x, b.x) * 2 + fcmp(y, b.y) <= 0;
  }
  bool operator>=(const vec &b) const {
    return fcmp(x, b.x) * 2 + fcmp(y, b.y) >= 0;
  }
  bool operator==(const vec &b) const { return !fcmp(x, b.x) && !fcmp(y, b.y); }
  bool operator!=(const vec &b) const { return fcmp(x, b.x) && fcmp(y, b.y); }
  vec operator-(void) const { return vec(-x, -y); }
  vec operator+(const vec &b) const { return vec(x + b.x, y + b.y); }
  vec operator-(const vec &b) const { return vec(x - b.x, y - b.y); }
  vec operator*(long double b) const { return vec(x * b, y * b); }
  vec operator/(long double b) const { return vec(x / b, y / b); }
  long double dot(const vec &b) const { return x * b.x + y * b.y; }
  long double det(const vec &b) const { return x * b.y - y * b.x; }
  long double abs(void) const { return sqrt(x * x + y * y); }
  long double norm(void) const { return x * x + y * y; }
  long double atan(void) const { return atan2(y, x); }
  vec unit(long double len = 1) const { return *this * (len / abs()); }
  vec rot(const vec &b = vec(0, 1)) const {
    return vec(x * b.x - y * b.y, x * b.y + y * b.x);
  }
};
struct Line {
  vec u, v;
  Line(void) {}
  Line(const vec &u, const vec &v) : u(u), v(v.unit()) {}
};
struct Circle {
  vec o;
  long double r;
  Circle(void) {}
  Circle(const vec &o, long double r) : o(o), r(r) {}
};
vec Foot(const Line &l, const vec &p) { return l.u + l.v * l.v.dot(p - l.u); }
Line Bisector(const vec &a, const vec &b) {
  return Line((a + b) / 2, (b - a).rot());
}
Line Bisector(const vec &u, const vec &v1, const vec &v2) {
  vec v = v1.unit() + v2.unit();
  if (fcmp(v.norm(), 0) == 0) {
    v = v1.rot();
  }
  return Line(u, v);
}
vector<vec> Intersection(const Line &l1, const Line &l2) {
  if (fcmp(l1.v.det(l2.v), 0)) {
    return {l1.u + l1.v * ((l2.u - l1.u).det(-l2.v) / l1.v.det(-l2.v))};
  }
  return {};
}
vector<vec> Intersection(const Line &l, const Circle &c) {
  vec foot = Foot(l, c.o);
  long double d2 = (foot - c.o).norm(), r2 = sqr(c.r);
  if (fcmp(d2, r2) == 0) {
    return {foot};
  } else if (d2 > r2) {
    return {};
  } else {
    vec v = l.v.unit(sqrt(r2 - d2));
    return {foot + v, foot - v};
  }
}
vector<vec> Intersection(Circle a, Circle b) {
  if (fcmp(a.r, b.r) > 0) {
    swap(a, b);
  }
  long double d = (b.o - a.o).abs();
  if (fcmp(d, b.r) >= 0) {
    int cmp = fcmp(d, a.r + b.r);
    if (cmp == 0) {
      return {a.o + (b.o - a.o).unit(a.r)};
    } else if (cmp > 0) {
      return {};
    } else {
      long double an0 = (b.o - a.o).atan();
      long double an1 = acos((sqr(d) + sqr(a.r) - sqr(b.r)) / (2 * d * a.r));
      return {a.o + vec(an0 + an1) * a.r, a.o + vec(an0 - an1) * a.r};
    }
  } else {
    int cmp = fcmp(d + a.r, b.r);
    if (cmp == 0) {
      return {b.o + (a.o - b.o).unit(b.r)};
    } else if (cmp < 0) {
      return {};
    } else {
      long double an0 = (a.o - b.o).atan();
      long double an1 = acos((sqr(d) + sqr(b.r) - sqr(a.r)) / (2 * d * b.r));
      return {b.o + vec(an0 + an1) * b.r, b.o + vec(an0 - an1) * b.r};
    }
  }
}
namespace convex {
const int maxn = 1e5;
int n, stk[maxn + 1], top;
vec p[maxn];
void Solve(void) {
  sort(p, p + n);
  top = 0;
  for (int i = 0; i < n; ++i) {
    while (top >= 2 &&
           fcmp((p[stk[top - 1]] - p[stk[top - 2]]).det(p[i] - p[stk[top - 2]]),
                0) <= 0) {
      --top;
    }
    stk[top++] = i;
  }
  for (int i = n - 2, mid = top; i >= 0; --i) {
    while (top > mid &&
           fcmp((p[stk[top - 1]] - p[stk[top - 2]]).det(p[i] - p[stk[top - 2]]),
                0) <= 0) {
      --top;
    }
    stk[top++] = i;
  }
  --top;
}
}  // namespace convex
}  // namespace geometry
namespace geometry {
vector<vec> TangentPoint(const vec &p, const Circle &c) {
  long double d2 = (c.o - p).norm(), len = sqrt(d2 - sqr(c.r));
  return Intersection(c, Circle(p, len));
}
long double GetDist(const Circle &c, const vec &a, const vec &b) {
  vector<vec> res = Intersection(Line(a, b - a), c);
  bool cross = false;
  for (const vec &u : res) {
    long double x = (u - a).dot((b - a).unit());
    if (fcmp(x, 0) > 0 && fcmp(x, (b - a).abs()) < 0) {
      cross = true;
    }
  }
  if (!cross) {
    return (b - a).abs();
  } else {
    vector<vec> res1 = TangentPoint(a, c), res2 = TangentPoint(b, c);
    long double ans = inf;
    for (const vec &u : res1) {
      for (const vec &v : res2) {
        long double d = (a - u).abs() + (b - v).abs();
        long double an = fabs((u - c.o).atan() - (v - c.o).atan());
        while (fcmp(an, 2 * pi) >= 0) {
          an -= 2 * pi;
        }
        if (fcmp(an, pi) > 0) {
          an = 2 * pi - an;
        }
        d += an * c.r;
        ans = min(ans, d);
      }
    }
    return ans;
  }
}
}  // namespace geometry
using namespace geometry;
int main(void) {
  int xp, yp, vp, x, y, v, r;
  scanf("%d%d%d%d%d%d%d", &xp, &yp, &vp, &x, &y, &v, &r);
  vec planet(xp, yp), ship(x, y);
  Circle sun(vec(0, 0), r);
  long double low = 0, high = 1e9, ans;
  for (int i = 0; i < 100; ++i) {
    long double mid = (low + high) * 0.5;
    long double planet_arrive_time = mid * planet.abs() / vp;
    vec target = vec(planet.atan() + mid) * planet.abs();
    long double ship_arrive_time = GetDist(sun, ship, target) / v;
    ans = ship_arrive_time;
    if (ship_arrive_time < planet_arrive_time) {
      high = mid;
    } else {
      low = mid;
    }
  }
  printf("%.10lf\n", (double)ans);
  return 0;
}
