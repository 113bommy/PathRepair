#include <bits/stdc++.h>
using namespace std;
const int md = 1000000007;
const int maxn = 101010;
const long long inf = 2020202020202020202LL;
double xm, ym, px[maxn], py[maxn], ans, tx, ty, n, x, y;
int m;
double sq(double x1, double y1, double x2, double y2) {
  return (x2 - xm) * (y1 - ym) - (x1 - xm) * (y2 - ym);
}
int ch() {
  double d, s1 = 0, s2 = 0;
  for (int i = 0; i < m; i++) {
    d = sq(px[i], py[i], px[(i + 1) % m], py[(i + 1) % m]);
    s1 += d;
    s2 += abs(d);
  }
  s1 = abs(s1);
  if (s1 == s2) return 0;
  return 1;
}
double dst(double x1, double y1, double x2, double y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
double ds(double x1, double y1, double x2, double y2) {
  double a1, b1, c1, a2, b2, c2, xh, yh;
  a1 = y1 - y2;
  b1 = x2 - x1;
  c1 = -a1 * x1 - b1 * y1;
  a2 = b1;
  b2 = -a1;
  c2 = a1 * ym - b1 * xm;
  xh = -(c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1);
  yh = -(a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1);
  double d = min(dst(x1, y1, xm, ym), dst(x2, y2, xm, ym));
  if (x1 > x2) swap(x1, x2);
  if (y1 > y2) swap(y1, y2);
  if ((x1 <= xh) && (xh <= x2) && (y1 <= yh) && (yh <= y2))
    d = min(d, dst(xh, yh, xm, ym));
  return d;
}
int main() {
  cin >> n;
  tx = 0;
  ty = 0;
  ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    tx += x;
    ty += y;
    ans += x * x + y * y;
  }
  xm = tx / n;
  ym = ty / n;
  double d = inf;
  cin >> m;
  ans -= xm * tx + ym * ty;
  for (int i = 0; i < m; i++) cin >> px[i] >> py[i];
  if (ch()) {
    for (int i = 0; i < m; i++)
      d = min(d, ds(px[i], py[i], px[(i + 1) % m], py[(i + 1) % m]));
    d = n * d;
  } else
    d = 0;
  ans += d;
  cout.precision(8);
  cout << fixed << ans;
  return 0;
}
