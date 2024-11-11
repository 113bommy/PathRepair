#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9, PI = acos(-1);
bool ge(long double x, long double y) { return x + EPS > y; }
bool le(long double x, long double y) { return x - EPS < y; }
bool eq(long double x, long double y) { return ge(x, y) && le(x, y); }
struct point {
  long double x, y;
  point(long double x = 0, long double y = 0) : x(x), y(y) {}
  void operator-=(point p) { x -= p.x, y -= p.y; }
  void operator+=(point p) { x += p.x, y += p.y; }
  void operator*=(long double p) { x *= p, y *= p; }
  point operator-() { return point(-x, -y); }
  point operator+(point p) { return point(x + p.x, y + p.y); }
  point operator-(point p) { return point(x - p.x, y - p.y); }
  point operator*(long double p) { return point(x * p, y * p); }
  point operator/(long double p) { return point(x / p, y / p); }
  long double operator*(point p) { return x * p.x + y * p.y; }
  long double operator%(point p) { return x * p.y - y * p.x; }
  long double operator!() { return sqrt(1.0L * x * x + 1.0L * y * y); }
  long double operator+() { return x * x + y * y; }
  point rotate(long double sin, long double cos) {
    return point(cos * x - sin * y, sin * x + cos * y);
  }
  point rotate(long double a) { return rotate(sin(a), cos(a)); }
};
vector<point> circles_intersection(point c1, long double r1, point c2,
                                   long double r2) {
  vector<point> vec;
  long double d = !(c1 - c2);
  if (ge(d, r1 + r2) or le(d + min(r1, r2), max(r1, r2))) return vec;
  long double x = (r1 * r1 - r2 * r2 + d * d) / (2 * d),
              y = sqrt(r1 * r1 - x * x);
  point v = (c2 - c1) / d;
  if (ge(x, 0))
    vec.push_back(c1 + v * x - v.rotate(PI / 2) * y);
  else
    vec.push_back(c1 + v * x + v.rotate(PI / 2) * y);
  if (ge(y, 0) && ge(x, 0))
    vec.push_back(c1 + v * x + v.rotate(PI / 2) * y);
  else if (ge(y, 0))
    vec.push_back(c1 + v * x - v.rotate(PI / 2) * y);
  return vec;
}
vector<point> point_circle_tg(point a, point c, long double r) {
  vector<point> vec;
  long double d = !(c - a), r2 = sqrt(d * d - r * r);
  long double x = (r2 * r2 - r * r + d * d) / (2 * d),
              y = sqrt(r2 * r2 - x * x);
  point v = (c - a) / d;
  vec.push_back(a + v * x - v.rotate(PI / 2) * y),
      vec.push_back(a + v * x + v.rotate(PI / 2) * y);
  return vec;
}
long double xc, yc, v, T, r, ang;
int n, cont;
bool ok1, ok2;
vector<pair<point, long double>> Circle;
vector<pair<long double, long double>> resp;
vector<pair<long double, int>> tetas;
int main() {
  scanf("%Lf%Lf%Lf%Lf%d", &xc, &yc, &v, &T, &n);
  point s(xc, yc);
  long double raio = v * T;
  for (int i = 0; i < n; i++) {
    scanf("%Lf%Lf%Lf", &xc, &yc, &r);
    Circle.push_back({point(xc, yc), r});
  }
  for (int i = 0; i < n; i++) {
    auto vec = circles_intersection(s, raio, Circle[i].first, Circle[i].second);
    auto ret = point_circle_tg(s, Circle[i].first, Circle[i].second);
    pair<long double, long double> aux;
    point p1, p2;
    if (le(+(s - Circle[i].first), Circle[i].second * Circle[i].second)) {
      resp.push_back({0, 2 * PI});
      break;
    }
    if (le(+(s - ret[0]), raio))
      p1 = ret[0], p2 = ret[1];
    else if (vec.size() == 2)
      p1 = vec[0], p2 = vec[1];
    else
      continue;
    if (ge(p1.y, s.y))
      aux.first = acos((p1 - s) * point(1, 0) / (!(p1 - s)));
    else if (le(p1.y, s.y))
      aux.first = 2 * PI - acos((p1 - s) * point(1, 0) / (!(p1 - s)));
    if (ge(p2.y, s.y))
      aux.second = acos((p2 - s) * point(1, 0) / (!(p2 - s)));
    else if (le(p2.y, s.y))
      aux.second = 2 * PI - acos((p2 - s) * point(1, 0) / (!(p2 - s)));
    if (eq(aux.first, aux.second)) continue;
    if (eq(aux.first, 0)) ok1 = true;
    if (eq(aux.second, 0)) ok2 = true, aux.second = 2 * PI;
    resp.push_back({aux});
  }
  for (int i = 0; i < resp.size(); i++)
    if (!ge(resp[i].second, resp[i].first))
      tetas.push_back({0, 0}), tetas.push_back({2 * PI, 1});
  for (int i = 0; i < resp.size(); i++)
    tetas.push_back({resp[i].first, 0}), tetas.push_back({resp[i].second, 1});
  sort(tetas.begin(), tetas.end());
  long double aux;
  for (int i = 0; i < tetas.size(); i++) {
    if (tetas[i].second) {
      cont--;
      if (cont == 0) ang += tetas[i].first - aux;
    } else {
      if (cont == 0) aux = tetas[i].first;
      cont++;
    }
  }
  printf("%Lf\n", ang / (2 * PI));
}
