#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const double eps = 1e-6;
int n;
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
struct point {
  double x, y, ang;
  point() {}
  point(double _x, double _y) {
    x = _x;
    y = _y;
    ang = 0;
  }
  point operator+(const point &q) const { return point(x + q.x, y + q.y); }
  point operator-(const point &q) const { return point(x - q.x, y - q.y); }
  point operator-() const { return point(-x, -y); }
  double operator*(const point &q) const { return x * q.x + y * q.y; }
  double operator%(const point &q) const { return x * q.y - y * q.x; }
  point operator*(const double &q) const { return point(x * q, y * q); }
  point operator/(const double &q) const { return point(x / q, y / q); }
  double len() { return x * x + y * y; }
  bool operator<(const point &q) const { return ang < q.ang; }
} O, a, b, c;
set<point> S;
set<point>::iterator nxt(set<point>::iterator x) {
  ++x;
  if (x == S.end()) return S.begin();
  return x;
}
set<point>::iterator last(set<point>::iterator x) {
  if (x == S.begin()) x = S.end();
  --x;
  return x;
}
bool check() {
  set<point>::iterator i = S.lower_bound(a), j;
  if (i == S.end()) i = S.begin();
  j = last(i);
  b = *i;
  c = *j;
  return (c - a) % (b - a) > -eps;
}
int main() {
  n = read() - 3;
  read();
  a.x = read();
  a.y = read();
  O = O + a;
  read();
  b.x = read();
  b.y = read();
  O = O + b;
  read();
  c.x = read();
  c.y = read();
  O = O + c;
  O = O / 3;
  a = a - O;
  b = b - O;
  c = c - O;
  a.ang = atan2(a.y, a.x);
  b.ang = atan2(b.y, b.x);
  c.ang = atan2(c.y, c.x);
  S.insert(a);
  S.insert(b);
  S.insert(c);
  while (n--) {
    int opt = read();
    a.x = read();
    a.y = read();
    a = a - O;
    a.ang = atan2(a.y, a.x);
    if (opt == 1) {
      if (check()) continue;
      while (S.size() > 2) {
        set<point>::iterator i = S.lower_bound(a), j;
        if (i == S.end()) i = S.begin();
        b = *i;
        j = nxt(i);
        c = *j;
        if ((c - a) % (b - a) > eps)
          S.erase(i);
        else
          break;
      }
      while (S.size() > 2) {
        set<point>::iterator i = last(S.lower_bound(a)), j;
        b = *i;
        j = last(i);
        c = *j;
        if ((c - a) % (b - a) < -eps)
          S.erase(i);
        else
          break;
      }
      S.insert(a);
    } else {
      if (check())
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
  return 0;
}
