#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
struct Point {
  long double x, y;
  Point() {}
  Point(long double a, long double b) { x = a, y = b; }
  bool operator<(const Point &b) const {
    if (x == b.x) return y < b.y;
    return x < b.x;
  }
  Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
  long double operator*(const Point &b) const { return x * b.y - y * b.x; }
};
const int p = 1e6;
set<Point> s;
int q, lastj = 0;
long long m;
bool above(Point a, Point b, Point c) {
  Point t1 = b - a, t2 = c - a;
  return (t1 * t2) <= eps;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> q >> m;
  s.insert(Point(0, 0));
  for (int i = 1; i <= q; ++i) {
    int tp, a, b;
    cin >> tp >> a >> b;
    a = (a + lastj) % p + 1;
    b = (b + lastj) % p + 1;
    if (tp == 1) {
      set<Point>::iterator it = s.lower_bound(Point(a, 0)), last, next, pre;
      if (it != s.end() && it->y <= b) continue;
      last = it;
      last--;
      if (it != s.end() && above(*last, Point(a, b), *it)) continue;
      it = s.insert(Point(a, b)).first;
      next = last = it;
      pre = --last;
      pre--;
      next++;
      while (next != s.end() && next->x == a) s.erase(next++);
      while (last != s.begin() && above(*pre, *last, *it))
        s.erase(last--), pre--;
    } else {
      Point tot = Point(1.0 * b / a, 0);
      set<Point>::iterator it = s.lower_bound(tot), it2;
      bool find = 0;
      if (it != s.end()) {
        if (it->y * a <= m)
          find = 1;
        else {
          it2 = it;
          it2--;
          if (above(Point(it2->x * a, it2->y * a), Point(b, m),
                    Point(it->x * a, it->y * a)))
            find = 1;
        }
      }
      if (find) {
        cout << "YES\n";
        lastj = i;
      } else
        cout << "NO\n";
    }
  }
  return 0;
}
