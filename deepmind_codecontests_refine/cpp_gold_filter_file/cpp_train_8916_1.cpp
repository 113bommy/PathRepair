#include <bits/stdc++.h>
using namespace std;
long double pi = acosl(-1.0);
long double eps = 1e-12;
bool eq(long double a, long double b) { return fabsl(a - b) < eps; }
struct point {
  long double x, y;
  point() {}
  point(long double xx, long double yy) {
    x = xx;
    y = yy;
  }
  point(const point &a) {
    x = a.x;
    y = a.y;
  }
  point operator+(point b) { return point(x + b.x, y + b.y); }
  point operator-(point b) { return point(x - b.x, y - b.y); }
  point operator/(long double s) { return point(x / s, y / s); }
  point operator*(long double b) { return point(x * b, y * b); }
  long double operator*(point b) { return x * b.x + y * b.y; }
  long double operator^(point b) { return x * b.y - y * b.x; }
  bool operator==(const point b) const { return eq(x, b.x) && eq(y, b.y); }
  bool operator<(const point b) const {
    if (x != b.x) return x < b.x;
    return y < b.y;
  }
  long double norm() { return sqrtl(x * x + y * y); }
};
point centroid(vector<point> p) {
  point c(0, 0);
  long double a = 0;
  for (int i = 0; i < p.size(); i++) {
    int j = (i + 1) % p.size();
    c = c + (p[i] + p[j]) * (p[i] ^ p[j]);
    a += p[i] ^ p[j];
  }
  return c / (3.0 * a);
}
int n, q, p1 = 0, p2 = 1;
vector<point> poly;
vector<long double> dist;
vector<long double> ang;
point get(int want, long double angle, point &c) {
  long double totang = angle + ang[want];
  return c + point(cosl(totang), sinl(totang)) * dist[want];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  poly.resize(n);
  dist.resize(n);
  ang.resize(n);
  long double zbx = 0, zby = 0;
  for (int i = 0; i < n; i++) cin >> poly[i].x >> poly[i].y;
  zbx = poly[0].x;
  zby = poly[0].y;
  for (int i = 0; i < n; i++) {
    poly[i].x -= zbx;
    poly[i].y -= zby;
  }
  point c = centroid(poly);
  for (int i = 0; i < n; i++) dist[i] = (poly[i] - c).norm();
  for (int i = 0; i < n; i++) {
    ang[i] = atan2l(poly[i].y - c.y, poly[i].x - c.x);
    while (ang[i] < 0) ang[i] += 2 * pi;
  }
  point top, nex;
  long double angle = 0;
  int i = 0, j = 1;
  cout << fixed << setprecision(12);
  while (q--) {
    int f;
    cin >> f;
    if (f == 1) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      if (u == i) {
        i = v;
        top = get(j, angle, c);
        nex = point(top.x, top.y - dist[j]);
      } else {
        j = v;
        top = get(i, angle, c);
        nex = point(top.x, top.y - dist[i]);
      }
      angle += -pi / 2 - atan2l(c.y - top.y, c.x - top.x);
      while (angle < 0) angle += 2 * pi;
      while (angle > 2 * pi) angle -= 2 * pi;
      c = nex;
    } else {
      int v;
      cin >> v;
      v--;
      point loc = get(v, angle, c);
      cout << loc.x + zbx << " " << loc.y + zby << endl;
    }
  }
  return 0;
}
