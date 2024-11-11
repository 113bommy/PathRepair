#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
  point operator+(const point &p) const { return point(x + p.x, y + p.y); }
  point operator-(const point &p) const { return point(x - p.x, y - p.y); }
  point operator*(const double &k) const { return point(x * k, y * k); }
  point operator/(const double &k) const { return point(x / k, y / k); }
  point operator-() const { return point(-x, -y); }
  void read() { scanf("%lf%lf", &x, &y); }
  void print() { printf("%f %f\n", x, y); }
} p, v;
double dot(point a, point b) { return a.x * b.x + a.y * b.y; }
double len(point a) { return sqrt(dot(a, a)); }
point rot(point a, double ang) {
  return point(a.x * cos(ang) - a.y * sin(ang),
               a.x * sin(ang) + a.y * cos(ang));
}
double a, b, c, d;
int main() {
  p.read();
  v.read();
  cin >> a >> b >> c >> d;
  v = v / len(v);
  (p + v * b).print();
  point l = rot(v, pi / 2);
  (p + l * (a / 2)).print();
  point r = -l;
  (p + l * (a / 2) + r * (a - c) / 2).print();
  point dw = -v;
  (p + l * (a / 2) + r * (a - c) / 2 + dw * d).print();
  (p + l * (a / 2) + r * (a - c) / 2 + dw * d + r * c).print();
  (p + l * (a / 2) + r * (a - c) / 2 + dw * d + r * c + v * d).print();
  (p + r * (a / 2)).print();
}
