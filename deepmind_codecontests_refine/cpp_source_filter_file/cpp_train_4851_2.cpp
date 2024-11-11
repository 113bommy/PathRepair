#include <bits/stdc++.h>
using namespace std;
int n, m, k;
bool debug = false;
struct Point {
  long long x, y;
  Point() {}
  Point(long long x, long long y) : x(x), y(y) {}
} p[4];
int T, t[4];
long long dis(Point a, Point b) { return abs(a.x - b.x) + abs(a.y - b.y); }
long long cal(Point a, Point p) {
  long long mid = (a.x > p.x ? a.x - p.x : 0) + (a.y > p.y ? a.y - p.y : 0);
  long long ds = dis(a, p), de = dis(p, Point(n, n));
  return (mid + ds) * (ds - mid + 1) / 2 + (mid + de) * (de - mid + 1) / 2 -
         mid;
}
bool ck(long long x, long long y) {
  for (int i = 0; i < 4; i++) {
    if (cal(Point(x, y), p[i]) > t[i]) {
      return false;
    }
  }
  return true;
}
void pp() {
  Point ps = Point(1, 1);
  string s;
  while (ps.x < n || ps.y < n) {
    if (ps.x < n && ck(ps.x + 1, ps.y)) {
      s += 'R';
      ps.x++;
    } else {
      s += 'U';
      ps.y++;
    }
    for (int i = 0; i < 4; i++) t[i] -= dis(ps, p[i]);
  }
  puts(s.c_str());
}
int main() {
  int a, b, c;
  cin >> n >> T >> a >> b >> c;
  for (int i = 0; i < 4; i++) t[i] = T;
  p[0] = Point(a, b);
  p[1] = Point(a + c - 1, b);
  p[2] = Point(a, b + c - 1);
  p[3] = Point(a + c - 1, b + c - 1);
  if (ck(1, 2) || ck(2, 1)) {
    pp();
  } else {
    puts("Impossible");
  }
  return 0;
}
