#include <bits/stdc++.h>
using namespace std;
using DO = long double;
const DO pi = acosl(-1);
const DO eps = 1e-9;
int sgn(const DO& a) {
  if (a < -eps) return -1;
  return a > eps;
}
struct point {
  DO first, second;
  point(DO first = 0, DO second = 0) : first(first), second(second) {}
  point operator+(const point& a) const {
    return {first + a.first, second + a.second};
  }
  point operator-(const point& a) const {
    return {first - a.first, second - a.second};
  }
  point operator&(const point& a) const {
    return {first * a.first - second * a.second,
            first * a.second + second * a.first};
  }
  point operator*(const DO& a) const { return {first * a, second * a}; }
  point operator/(const DO& a) const { return {first / a, second / a}; }
  DO operator*(const point& a) const {
    return first * a.first + second * a.second;
  }
  DO operator^(const point& a) const {
    return first * a.second - second * a.first;
  }
  bool operator<(const point& a) const {
    int t;
    t = sgn(first - a.first);
    if (t) return t < 0;
    return second < a.second;
  }
  bool operator>(const point& a) const {
    int t;
    t = sgn(first - a.first);
    if (t) return t > 0;
    return second > a.second;
  }
  bool operator==(const point& a) const {
    return sgn(first - a.first) == 0 && sgn(second - a.second) == 0;
  }
  bool operator!=(const point& a) const {
    return sgn(first - a.first) || sgn(second - a.second);
  }
  point rotate(DO a) { return *this & point(cosl(a), sinl(a)); }
  point conj() { return {-second, first}; }
  DO len() { return sqrtl(first * first + second * second); }
  point norm() {
    DO l = len();
    if (l < eps) return *this;
    return {first / l, second / l};
  }
  DO alp() { return atan2l(second, first); }
  void eat() { cin >> first >> second; }
  void bat() const { cout << first << ' ' << second << endl; }
};
point get(const DO& alp) { return point(cosl(alp), sinl(alp)); }
const int N = 1e4 + 10;
point p[N * 4], a;
int n;
DO area, dp[N * 4];
int id(const point& b) {
  if (sgn(p[0] - a ^ b) > 0) return 0;
  if (sgn(p[0] - a ^ b) == 0) {
    if (sgn(p[1] - a ^ b) > 0) return 1;
    return n - 1;
  }
  int st = 0, ed = n, i;
  while (true) {
    i = st + ed >> 1;
    int sg = sgn(p[i] - a ^ b);
    if (sg > 0) return i;
    if (sg == 0) {
      if (sgn(p[i - 1] - a ^ b) > 0)
        return i - 1;
      else
        return (i + 1) % n;
    }
    if (sgn(p[0] - a ^ p[i] - a) > 0)
      st = i;
    else
      ed = i;
  }
}
int get(int L, int R, const point& b) {
  if (R < L) R += n;
  while (L + 1 < R) {
    int md = L + R >> 1;
    if (sgn(p[md] - a ^ b) > 0)
      L = md;
    else
      R = md;
  }
  return L % n;
}
point inter(const point& a, const point& b, const point& c, const point& d) {
  return a + b * ((c - a ^ d) / (b ^ d));
}
DO seg(int L, int R) {
  if (L == R) return 0;
  while (L > R) R += n;
  return dp[R] - dp[L];
}
DO calc(const DO& alp) {
  point b = get(alp), c;
  c = b * -1;
  int L = id(b);
  int R = id(c);
  int j = get(L, R, b);
  int i = get(R, L, c);
  point F = inter(p[i], p[i + 1] - p[i], a, c);
  point G = inter(p[j], p[j + 1] - p[j], a, b);
  DO ans = G ^ F;
  ans += F ^ p[i + 1];
  ans += seg((i + 1) % n, j);
  ans += p[j] ^ G;
  return ans;
}
bool ok(const DO& a) { return (fabsl(a - area) / area) < 1e-7; }
DO solve() {
  a.eat();
  DO st = 0, ed = pi, md;
  DO sub = calc(st);
  if (ok(sub)) return 0;
  int t = sgn(area - sub);
  int step = 40;
  while (step--) {
    md = (st + ed) / 2;
    sub = calc(md);
    if (ok(sub)) return md;
    if (sgn(area - sub) == t)
      st = md;
    else
      ed = md;
  }
  return st;
}
int main() {
  int q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++)
    p[i].eat(), p[n + i] = p[n + n + i] = p[n + n + n + i] = p[i];
  reverse(p, p + n * 4);
  for (int i = 0; i < n; i++) area += p[i] ^ p[i + 1];
  area /= 2;
  for (int i = 1; i < n * 4; i++) dp[i] = dp[i - 1] + (p[i - 1] ^ p[i]);
  while (q--) printf("%.12lf\n", (double)solve());
  return 0;
}
