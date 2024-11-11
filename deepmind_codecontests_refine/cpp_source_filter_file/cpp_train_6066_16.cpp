#include <bits/stdc++.h>
using namespace std;
struct segment {
  long long x1, y1, x2, y2;
  void read() { scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2); }
  void invert() {
    long long tmp = x1;
    x1 = x2;
    x2 = tmp;
    tmp = y1;
    y1 = y2;
    y2 = tmp;
  }
};
bool belong(long long x, long long y, segment a) {
  long long A = a.y2 - a.y1;
  long long B = a.x1 - a.x2;
  long long C = -A * a.x1 - B * a.y1;
  if (A * x + B * y + C != 0) return false;
  if (x < min(a.x1, a.x2) || x > max(a.x1, a.x2)) return false;
  if (y < min(a.y1, a.y2) || y > max(a.y1, a.y2)) return false;
  return true;
}
long long scalar(segment a, segment b) {
  long long dx1 = a.x1 - b.x1;
  long long dx2 = a.x2 - b.x2;
  long long dy1 = a.y1 - b.y1;
  long long dy2 = a.y2 - b.y2;
  return dx1 * dx2 + dy1 * dy2;
}
bool goodDivision(long long x, long long y, segment a) {
  long long dist1 = (x - a.x1) * (x - a.x1) + (y - a.y1) * (y - a.y1);
  long long dist2 = (x - a.x2) * (x - a.x2) + (y - a.y2) * (y - a.y2);
  if (dist1 > dist2) {
    long long tmp = dist1;
    dist1 = dist2;
    dist2 = tmp;
  }
  return 16LL * dist1 >= dist2;
}
bool ok1(segment a, segment b, segment c) {
  if (a.x1 != b.x1 || a.y1 != b.y1) return false;
  if (!belong(c.x1, c.y1, a) || !belong(c.x2, c.y2, b)) return false;
  if (scalar(a, b) < 0) return false;
  if (!goodDivision(c.x1, c.y1, a) || !goodDivision(c.x2, c.y2, b))
    return false;
  return true;
}
bool ok(segment a, segment b, segment c) {
  bool res = false;
  for (int mask = 0; mask < 8; mask++) {
    if ((mask & 1) != 0) a.invert();
    if ((mask & 2) != 0) b.invert();
    if ((mask & 4) != 0) c.invert();
    res |= ok1(a, b, c);
    if ((mask & 1) != 0) a.invert();
    if ((mask & 2) != 0) b.invert();
    if ((mask & 4) != 0) c.invert();
  }
  return res;
}
int main() {
  int t;
  scanf("%d", &t);
  for (int cas = 0; cas < t; cas++) {
    segment a, b, c;
    a.read();
    b.read();
    c.read();
    puts(ok(a, b, c) || ok(a, c, b) || ok(b, c, a) ? "YES" : "NO");
  }
}
