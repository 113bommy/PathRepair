#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const double eps = 1e-10;
double add(double a, double b) {
  if (abs(a + b) < eps * (abs(a) + abs(b))) return 0;
  return a + b;
}
struct P {
  double x, y;
  P() {}
  P(double x, double y) : x(x), y(y) {}
  P operator+(const P &p) { return P(add(x, p.x), add(y, p.y)); }
  P operator-(const P &p) { return P(add(x, -p.x), add(y, -p.y)); }
  P operator*(double d) { return P(x * d, y * d); }
  double dot(const P &p) { return add(x * p.x, y * p.y); }
  double det(const P &p) { return add(x * p.y, -y * p.x); }
};
double dist(const P &a, const P &b) {
  double x = a.x - b.x, y = a.y - b.y;
  return sqrt(x * x + y * y);
}
bool on_seg(P p1, P p2, P q) {
  return (p1 - q).det(p2 - q) == 0 && (p1 - q).dot(p2 - q) <= 0;
}
P intersection(P p1, P p2, P q1, P q2) {
  return p1 + (p2 - p1) * ((q2 - q1).det(q1 - p1) / (q2 - q1).det(p2 - p1));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);
  int n;
  cin >> n;
  vector<P> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  int ans = 0;
  for (int i = 1; i + 1 < n; i++) {
    ans += (p[i + 1] - p[i]).det(p[i] - p[i - 1]) < 0;
  }
  cout << ans << '\n';
  return 0;
}
