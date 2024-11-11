#include <bits/stdc++.h>
const double pi = acos(-1.0);
const double eps = 1e-12;
using namespace std;
struct pt {
  double x, y;
  pt() : x(0), y(0) {}
  pt(double x, double y) : x(x), y(y) {}
  void scan() { cin >> x >> y; }
  void print() const { cout << x << " " << y << endl; }
  pt operator+(const pt &p) const { return pt(x + p.x, y + p.y); }
  pt operator-(const pt &p) const { return pt(x - p.x, y - p.y); }
  pt operator*(double k) const { return pt(x * k, y * k); }
  pt operator/(double k) const { return pt(x / k, y / k); }
};
double sqr(double a) { return a * a; }
double distPt(pt a, pt b) { return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y)); }
double triangle_area_2(pt a, pt b, pt c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
void solve() {
  int n;
  cin >> n;
  vector<pt> p(n);
  for (int i = 0; i < n; i++) {
    p[i].scan();
  }
  double mn = 1e20;
  for (int i = 0; i < n; i++) {
    int last = (i - 1 + n) % n;
    int nxt = (i + 1) % n;
    double s = triangle_area_2(p[last], p[i], p[nxt]);
    s = abs(s);
    mn = min(mn, s / distPt(p[last], p[nxt]));
  }
  cout << mn * 0.5 << endl;
}
int main() {
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed), cout.precision(8);
  int step;
  step = 1;
  for (int i = 1; i <= step; i++) {
    solve();
  }
}
