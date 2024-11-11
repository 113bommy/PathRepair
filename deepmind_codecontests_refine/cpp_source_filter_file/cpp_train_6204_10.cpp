#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
using namespace std;
using lli = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;
const ld pi = acos(-1.0);
const ld eps = 1e-15;
int sgn(ld x) { return x > 0 ? 1 : (x < 0 ? -1 : 0); }
struct Pt {
  ld x, y;
  explicit Pt(ld x = 0, ld y = 0) : x(x), y(y) {}
  Pt operator+(Pt p) const { return Pt(x + p.x, y + p.y); }
  Pt operator-(Pt p) const { return Pt(x - p.x, y - p.y); }
  Pt operator*(ld k) const { return Pt(x * k, y * k); }
  Pt operator/(ld k) const { return Pt(x / k, y / k); }
  ld dot(Pt p) const { return x * p.x + y * p.y; }
  ld cross(Pt p) const { return x * p.y - y * p.x; }
  ld norm() const { return x * x + y * y; }
  ld length() const { return sqrtl(norm()); }
  ld angle() {
    ld ang = atan2(y, x);
    return ang + (ang < 0 ? 2 * pi : 0);
  }
  Pt perp() const { return Pt(-y, x); }
  Pt unit() const { return (*this) / length(); }
  Pt rotate(ld angle) const {
    return Pt(x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle));
  }
  bool operator==(Pt p) const {
    return abs((x) - (p.x)) <= +eps && abs((y) - (p.y)) <= +eps;
  }
  bool operator!=(Pt p) const {
    return !abs((x) - (p.x)) <= +eps || !abs((y) - (p.y)) <= +eps;
  }
  friend ostream &operator<<(ostream &os, const Pt &p) {
    return os << "(" << p.x << ", " << p.y << ")";
  }
  friend istream &operator>>(istream &is, Pt &p) { return cin >> p.x >> p.y; }
  int cuad() const {
    if (x > 0 && y >= 0) return 0;
    if (x <= 0 && y > 0) return 1;
    if (x < 0 && y <= 0) return 2;
    if (x >= 0 && y < 0) return 3;
    assert(x == 0 && y == 0);
    return -1;
  }
};
struct Seg {
  Pt a, b, v;
  Seg(Pt a, Pt b) : a(a), b(b), v(b - a) {}
  bool contains(Pt p) {
    return abs((v.cross(p - a)) - (0)) <= +eps &&
           ((a - p).dot(b - p)) - (0) <= +eps;
  }
  int intersects(Seg second) {
    int t1 = sgn(v.cross(second.a - a)), t2 = sgn(v.cross(second.b - a));
    if (t1 == t2)
      return t1 == 0 && (contains(second.a) || contains(second.b) ||
                         second.contains(a) || second.contains(b))
                 ? -1
                 : 0;
    return sgn(second.v.cross(a - second.a)) !=
           sgn(second.v.cross(b - second.a));
  }
  template <class T>
  Pt intersection(T t) {
    return a + v * ((t.a - a).cross(t.v) / v.cross(t.v));
  }
};
using Poly = vector<Pt>;
const ld inf = 1e18;
const int N = 1e5 + 5;
Poly trap(2);
Pt mouse[N], speed[N];
int n;
bool can(ld k, bool &yes) {
  int cnt = 0;
  bool outside = false;
  for (auto i = (0) - ((0) > (n)); i != n - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    Pt cur = mouse[i] + speed[i] * k;
    if ((cur.x) - (trap[0].x) <= +eps && (speed[i].x) - (0) <= +eps)
      outside = true;
    if ((cur.x) - (trap[1].x) >= -eps && (speed[i].x) - (0) >= -eps)
      outside = true;
    if ((cur.y) - (trap[0].y) <= +eps && (speed[i].y) - (0) <= +eps)
      outside = true;
    if ((cur.y) - (trap[1].y) >= -eps && (speed[i].y) - (0) >= -eps)
      outside = true;
    if ((trap[0].x) - (cur.x) < -eps && (cur.x) - (trap[1].x) < -eps &&
        (trap[0].y) - (cur.y) < -eps && (cur.y) - (trap[1].y) < -eps)
      cnt++;
  }
  if (cnt == n) yes = true;
  ;
  return cnt == n || outside;
}
int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
  while (cin >> n) {
    cin >> trap[0] >> trap[1];
    for (auto i = (0) - ((0) > (n)); i != n - ((0) > (n));
         i += 1 - 2 * ((0) > (n)))
      cin >> mouse[i] >> speed[i];
    ld lo = 0, hi = inf;
    bool yes = false;
    for (auto it = (0) - ((0) > (300)); it != 300 - ((0) > (300));
         it += 1 - 2 * ((0) > (300))) {
      ld mid = (lo + hi) / 2.0;
      ;
      if (can(mid, yes))
        hi = mid - eps;
      else
        lo = mid + eps;
    };
    if (yes)
      cout << fixed << setprecision(15) << lo << '\n';
    else
      cout << "-1\n";
  }
  return 0;
}
