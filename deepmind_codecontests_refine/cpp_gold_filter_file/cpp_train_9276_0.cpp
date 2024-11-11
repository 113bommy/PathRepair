#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
const long long N = 2e6 + 9;
const long long M = 1e3 + 9;
const long long INFINT = 1e9 + 9;
const long long INFLL = 1e18 + 9;
const long double EPS = 1e-6;
const double PI = acos(-1);
struct point {
  long double first, second;
  point(long double xx, long double yy) {
    first = xx;
    second = yy;
  }
  point() {}
  long double size() { return sqrt(first * first + second * second); }
};
struct line {
  long double a, b, c;
  line(point p, point q) {
    a = (p.second - q.second);
    b = (q.first - p.first);
    c = (p.first * q.second - p.second * q.first);
  }
};
point operator-(point a, point b) {
  point c;
  c.first = a.first - b.first;
  c.second = a.second - b.second;
  return c;
}
point operator+(point a, point b) {
  point c;
  c.first = a.first + b.first;
  c.second = a.second + b.second;
  return c;
}
point operator/(point a, long double k) {
  point b;
  b.first = a.first / k;
  b.second = a.second / k;
  return b;
}
point operator*(point a, long double k) {
  point b;
  b.first = a.first * k;
  b.second = a.second * k;
  return b;
}
point operator*(line p, line q) {
  point r;
  long double det = p.a * q.b - p.b * q.a;
  r.first = (p.b * q.c - q.b * p.c) / det;
  r.second = (q.a * p.c - p.a * q.c) / det;
  return r;
}
long long check(point a, long double ra, point b, long double rb) {
  long double x1 = a.first, x2 = b.first, y1 = a.second, y2 = b.second, r1 = ra,
              r2 = rb;
  long double r = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
  return (long long)(r1 + r2 >= r + EPS);
}
point get(point a, point b, point c) {
  point ab = b - a;
  ab = ab / ab.size();
  point ac = c - a;
  ac = ac / ac.size();
  point ad = ab + ac;
  ad = a + ad;
  line k1(a, ad);
  point bc = c - b;
  bc = bc / bc.size();
  point ba = a - b;
  ba = ba / ba.size();
  point bd = ba + bc;
  bd = b + bd;
  line k2(b, bd);
  point ez = k1 * k2;
  return ez;
}
long long f(long double r1, long double r2, long double r3, long double r4) {
  point a(0, 0);
  point b(r1 + r2, 0);
  long double p, q, r;
  p = r1 + r2;
  q = r1 + r3;
  r = r2 + r3;
  long double cs = (((p) * (p)) + ((q) * (q)) - ((r) * (r))) / (2 * p * q);
  long double sn = sqrt(1.0 - ((cs) * (cs)));
  point c(q * cs, q * sn);
  cout << fixed << setprecision(10);
  point ac = c - a;
  point i = ac / ac.size();
  i = i * r1;
  i = a + i;
  point ab = b - a;
  point j = ab / ab.size();
  j = j * r1;
  j = a + j;
  point bc = c - b;
  point k = bc / bc.size();
  k = k * r2;
  k = b + k;
  point ez = get(i, j, k);
  point fk = get(a, b, c);
  point t = ez - fk;
  t = t / 2;
  t = fk + t;
  cout << t.first << ' ' << t.second << endl;
  return check(a, r1, t, r4) * check(b, r2, t, r4) * check(c, r3, t, r4);
}
struct max {
  long long value;
  long long i;
};
struct min {
  long long value;
  long long i;
};
long long arr[1000];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  srand(time(0));
  std::stringstream ss;
  std::stringstream cc;
  long long a;
  cin >> a;
  for (long long i = 0; i < a; i++) {
    long long r;
    cin >> r;
    for (long long j = 0; j < r; j++) {
      long long n;
      cin >> n;
      arr[n]++;
    }
  }
  for (long long i = 0; i <= 100; i++) {
    if (arr[i] == a) cout << i << " ";
  }
}
