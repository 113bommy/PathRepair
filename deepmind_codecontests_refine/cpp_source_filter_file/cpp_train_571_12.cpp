#include <bits/stdc++.h>
using namespace std;
namespace Geometry {
struct vec {
  double x, y;
  vec(double a = 0, double b = 0) : x(a), y(b) {}
};
vec operator+(vec a, vec b) { return vec(a.x + b.x, a.y + b.y); }
vec operator-(vec a, vec b) { return vec(a.x - b.x, a.y - b.y); }
vec operator*(vec a, double b) { return vec(a.x * b, a.y * b); }
vec operator*(double a, vec b) { return vec(a * b.x, a * b.y); }
vec operator/(vec a, double b) { return vec(a.x / b, a.y / b); }
const double eps = 0.000001;
int dcmp(double d) {
  if (d > eps) return 1;
  if (d < -eps) return -1;
  return 0;
}
bool operator<(vec a, vec b) {
  return dcmp(a.x - b.x) < 0 || (dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) < 0);
}
bool operator>(vec a, vec b) { return b < a; }
bool operator!=(vec a, vec b) { return a < b || b < a; }
bool operator==(vec a, vec b) { return !(a != b); }
double sqr(double a) { return a * a; }
double abs(vec a) { return sqrt(sqr(a.x) + sqr(a.y)); }
double dist(vec a, vec b) { return abs(a - b); }
vec normal(vec a) { return a / abs(a); }
double dot(vec a, vec b) { return a.x * b.x + a.y * b.y; }
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
double cross(vec a, vec b, vec c) { return cross(b - a, c - a); }
double angle(vec a, vec b) { return acos(dot(a, b) / abs(a) / abs(b)); }
vec rotate(vec a, double t) {
  return vec(a.x * cos(t) - a.y * sin(t), a.x * sin(t) + a.y * cos(t));
}
vec rotate(vec a, vec b, double t) { return a + rotate(b - a, t); }
bool judge(vec a, vec b, vec c, vec d) {
  double x = cross(a, b, c), y = cross(a, b, d);
  double z = cross(c, d, a), w = cross(c, d, b);
  return dcmp(x) * dcmp(y) < 0 && dcmp(z) * dcmp(w) < 0;
}
vec IofL(vec a, vec b, vec c, vec d) {
  double x = cross(a, b, c);
  double y = -cross(a, b, d);
  vec ans = (d * x + c * y) / (x + y);
  return ans;
}
double DtoL(vec a, vec b, vec c) { return cross(a, b, c) / dist(a, b); }
double DtoS(vec a, vec b, vec c) {
  if (dot(b - a, c - b) > 0) return dist(b, c);
  if (dot(a - b, c - a) > 0) return dist(a, c);
  return DtoL(a, b, c);
}
vec shade(vec a, vec b, vec c) {
  return a + normal(b - a) * dot(normal(b - a), (c - a));
}
}  // namespace Geometry
using namespace Geometry;
const int N = 100100;
vec val[N], p;
int main() {
  int n;
  scanf("%d%lf%lf", &n, &p.x, &p.y);
  for (int i = 1; i <= n; i++) scanf("%lf%lf", &val[i].x, &val[i].y);
  double Max = 0, Min = 1e100;
  for (int i = 1; i <= n; i++) Max = max(Max, dist(p, val[i]));
  for (int i = 2; i <= n; i++) Min = min(Min, DtoS(val[i], val[i - 1], p));
  Min = min(Min, DtoS(val[1], val[n], p));
  printf("%.20lf\n", (Max * Max - Min * Min) * acos(-1));
  return 0;
}
