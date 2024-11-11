#include <bits/stdc++.h>
using namespace std;
using DO = long double;
using LL = long long;
const DO pi = acosl(-1);
const DO eps = 1e-15;
const DO EPS = 1e-7;
int sgn(const DO& a) { return a < -eps ? -1 : a > eps; }
int SGN(const DO& a) { return a < -EPS ? -1 : a > EPS; }
struct point {
  DO x, y;
  point(DO x = 0, DO y = 0) : x(x), y(y) {}
  point operator+(const point& a) const { return {x + a.x, y + a.y}; }
  point operator-(const point& a) const { return {x - a.x, y - a.y}; }
  LL operator&(const point& a) const {
    return (LL)x * (LL)a.y - (LL)y * (LL)a.x;
  }
  point operator*(const DO& a) const { return {x * a, y * a}; }
  DO operator^(const point& a) const { return x * a.y - y * a.x; }
  void eat() { cin >> x >> y; }
};
point get(const DO& alp) { return point(cosl(alp), sinl(alp)); }
const int N = 1e4 + 10;
int n;
DO area;
LL dp[N * 4];
point p[N * 4], a;
int id(const point& b) {
  if (SGN(p[0] - a ^ b) > 0) return 0;
  if (SGN(p[0] - a ^ b) == 0) {
    if (SGN(p[1] - a ^ b) > 0)
      return 1;
    else
      return n - 1;
  }
  int st = 0, ed = n, i;
  while (true) {
    i = st + ed >> 1;
    int sg = SGN(p[i] - a ^ b);
    if (sg > 0) return i;
    if (sg == 0) {
      if (SGN(p[i - 1] - a ^ b) > 0)
        return i - 1;
      else
        return (i + 1) % n;
    }
    if (SGN(p[0] - a ^ p[i] - a) > 0)
      st = i;
    else
      ed = i;
  }
}
int get(int L, int R, const point& b) {
  if (R < L) R += n;
  while (L + 1 < R) {
    int md = L + R >> 1;
    if (SGN(p[md] - a ^ b) > 0)
      L = md;
    else
      R = md;
  }
  return L % n;
}
point inter(const point& a, const point& b, const point& c, const point& d) {
  return a + b * ((c - a ^ d) / (b ^ d));
}
LL seg(int L, int R) {
  while (L > R) R += n;
  return dp[R] - dp[L] + (p[R] & p[L]);
}
DO calc(const DO& alp) {
  point b = get(alp), c;
  c = b * -1;
  int L, R;
  do {
    L = rand() % n;
  } while (SGN(b ^ p[L] - a) >= 0);
  do {
    R = rand() % n;
  } while (SGN(b ^ p[R] - a) <= 0);
  int j = get(L, R, b);
  int i = get(R, L, c);
  point F = inter(a, c, p[i], p[i + 1] - p[i]);
  point G = inter(a, b, p[j], p[j + 1] - p[j]);
  return fabsl(G - F ^ p[j] - F) + fabsl(p[j] - F ^ p[i + 1] - F) +
         seg((i + 1) % n, j);
}
DO solve() {
  a.eat();
  DO st = 0, ed = pi, md;
  DO sub = calc(st);
  int t = SGN((area - sub) / area);
  if (!t) return 0;
  int step = 50;
  while (step--) {
    md = (st + ed) / 2;
    sub = calc(md);
    int f = SGN((area - sub) / area);
    if (!f) return md;
    if (f == t)
      st = md;
    else
      ed = md;
  }
  return st;
}
int main() {
  srand(time(0));
  int q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++)
    p[i].eat(), p[n + i] = p[n + n + i] = p[n + n + n + i] = p[i];
  reverse(p, p + n * 4);
  for (int i = 1; i < n * 4; i++) dp[i] = dp[i - 1] + (p[i - 1] & p[i]);
  area = dp[n];
  area /= 2;
  cout << fixed << setprecision(12);
  while (q--) cout << solve() << endl;
  return 0;
}
