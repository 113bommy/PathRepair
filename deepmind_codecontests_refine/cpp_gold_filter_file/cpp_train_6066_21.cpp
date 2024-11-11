#include <bits/stdc++.h>
struct Point {
  long long x, y;
  Point& operator-=(Point const& p) {
    x -= p.x;
    y -= p.y;
    return *this;
  }
};
bool operator==(Point const& a, Point const& b) {
  return a.x == b.x && a.y == b.y;
}
bool operator!=(Point const& a, Point const& b) {
  return a.x != b.x || a.y != b.y;
}
Point operator-(Point a, Point const& b) { return a -= b; }
long long operator*(Point const& a, Point const& b) {
  return a.x * b.y - a.y * b.x;
}
long long operator%(Point const& a, Point const& b) {
  return a.x * b.x + a.y * b.y;
}
long long dist2(Point const& a, Point const& b) { return (a - b) % (a - b); }
struct Segment {
  Point A, B;
};
bool isOn(Point const& p, Segment const& a) {
  return (p - a.A) * (p - a.B) == 0 && (a.A - p) % (a.B - p) <= 0;
}
bool isGood(Point const& p, Segment const& a) {
  long long d1 = dist2(p, a.A);
  long long d2 = dist2(p, a.B);
  if (d1 < d2) std::swap(d1, d2);
  return 16 * d2 >= d1;
}
bool check(Segment a, Segment b, Segment const& c) {
  if (a.A == b.B) std::swap(b.A, b.B);
  if (a.B == b.A) std::swap(a.B, a.A);
  if (a.B == b.B) {
    std::swap(b.A, b.B);
    std::swap(a.A, a.B);
  }
  if (a.A != b.A) return false;
  Point O = a.A;
  Point A = a.B;
  Point B = b.B;
  if ((A - O) * (B - O) == 0) return false;
  if ((A - O) % (B - O) < 0) return false;
  Point P = c.A;
  Point Q = c.B;
  if (!isOn(P, a)) std::swap(P, Q);
  if (!isOn(P, a) || !isOn(Q, b)) return false;
  return isGood(P, a) && isGood(Q, b);
}
bool solve() {
  Segment s[3];
  for (int i = 0; i < 3; ++i) {
    scanf("%I64d%I64d%I64d%I64d", &s[i].A.x, &s[i].A.y, &s[i].B.x, &s[i].B.y);
  }
  for (int i = 0; i < 3; ++i) {
    if (check(s[0], s[1], s[2])) {
      return true;
    }
    std::rotate(s, s + 2, s + 3);
  }
  return false;
}
int main() {
  int tests;
  scanf("%d", &tests);
  while (tests--) puts(solve() ? "YES" : "NO");
}
