#include <bits/stdc++.h>
using namespace std;
struct point {
  double x, y;
};
double sq(double x) { return x * x; }
double dist(point a, point b) { sqrt(sq(a.x - b.x) + sq(a.y - b.y)); }
double solve(point a, point b, point c) {
  double lnth = dist(a, b);
  double num = (b.x - a.x) * (c.x - a.x) + (b.y - a.y) * (c.y - a.y);
  double tmp = num / lnth;
  if (tmp < 0 || tmp > lnth)
    return -1;
  else
    return fabs(((c.y - a.y) * (b.x - a.x) - (b.y - a.y) * (c.x - a.x)) / lnth);
}
int main() {
  long long n;
  cin >> n;
  point p;
  cin >> p.x >> p.y;
  point q, r, second;
  cin >> q.x >> q.y;
  second.x = r.x = q.x;
  second.y = r.y = q.y;
  double mn, mx, tmp;
  mx = mn = dist(p, q);
  while (--n) {
    cin >> q.x >> q.y;
    tmp = dist(p, q);
    mx = max(mx, tmp);
    mn = min(mn, tmp);
    tmp = solve(q, r, p);
    if (tmp > 0 && tmp < mn) mn = tmp;
    r.x = q.x;
    r.y = q.y;
  }
  tmp = solve(second, r, p);
  if (tmp > 0 && tmp < mn) mn = tmp;
  cout << setprecision(14) << 3.14159265358979323 * (sq(mx) - sq(mn));
}
