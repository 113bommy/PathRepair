#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
  point() {}
  point(int _x, int _y) : x(_x), y(_y) {}
  bool operator==(const point &a) const { return x == a.x && y == a.y; }
};
bool prod(point a, point b, point c) {
  return 1LL * (b.x - a.x) * (c.y - b.y) - 1LL * (b.y - a.y) * (c.x - b.x) == 0;
}
bool ok1(point a, point b, point c) {
  long long ac =
      1LL * (a.x - c.x) * (a.x - c.x) + 1LL * (a.y - c.y) * (a.y - c.y);
  long long bc =
      1LL * (b.x - c.x) * (b.x - c.x) + 1LL * (b.y - c.y) * (b.y - c.y);
  int x1 = a.x, y1 = a.y, x2 = b.x, y2 = b.y;
  if (x1 > x2) swap(x1, x2);
  if (y1 > y2) swap(y1, y2);
  return (x1 <= c.x && c.x <= x2 && y1 <= c.y && c.y <= y2) &&
         (16 * ac >= bc) && (16 * bc >= ac);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    pair<point, point> a[3];
    for (int i = 0; i < 3; i++)
      cin >> a[i].first.x >> a[i].first.y >> a[i].second.x >> a[i].second.y;
    if (a[0].first == a[0].second || a[1].first == a[1].second ||
        a[2].first == a[2].second) {
      cout << "NO\n";
      continue;
    }
    bool ok = (a[0].first == a[1].first || a[0].first == a[1].second ||
               a[0].second == a[1].first || a[0].second == a[1].second);
    if (!ok) {
      swap(a[1], a[2]);
      ok = (a[0].first == a[1].first || a[0].first == a[1].second ||
            a[0].second == a[1].first || a[0].second == a[1].second);
    }
    if (!ok) {
      swap(a[0], a[2]);
      ok = (a[0].first == a[1].first || a[0].first == a[1].second ||
            a[0].second == a[1].first || a[0].second == a[1].second);
    }
    if (!ok) {
      swap(a[1], a[2]);
      ok = (a[0].first == a[1].first || a[0].first == a[1].second ||
            a[0].second == a[1].first || a[0].second == a[1].second);
    }
    if (!ok) {
      swap(a[0], a[2]);
      ok = (a[0].first == a[1].first || a[0].first == a[1].second ||
            a[0].second == a[1].first || a[0].second == a[1].second);
    }
    if (!ok) {
      swap(a[1], a[2]);
      ok = (a[0].first == a[1].first || a[0].first == a[1].second ||
            a[0].second == a[1].first || a[0].second == a[1].second);
    }
    if (!ok) {
      cout << "NO\n";
      continue;
    }
    if (a[0].first == a[1].second)
      swap(a[1].first, a[1].second);
    else if (a[0].second == a[1].first)
      swap(a[0].first, a[0].second);
    else if (a[0].second == a[1].second) {
      swap(a[0].first, a[0].second);
      swap(a[1].first, a[1].second);
    }
    if (prod(a[0].first, a[0].second, a[1].second)) {
      cout << "NO\n";
      continue;
    }
    if (!(prod(a[0].first, a[0].second, a[2].first) &&
          prod(a[1].first, a[1].second, a[2].second)) &&
        !(prod(a[0].first, a[0].second, a[2].second) &&
          prod(a[1].first, a[1].second, a[2].first))) {
      cout << "NO\n";
      continue;
    }
    if (1LL * (a[0].first.x - a[0].second.x) * (a[0].first.x - a[0].second.x) +
            1LL * (a[0].first.y - a[0].second.y) *
                (a[0].first.y - a[0].second.y) +
            1LL * (a[1].first.x - a[1].second.x) *
                (a[1].first.x - a[1].second.x) +
            1LL * (a[1].first.y - a[1].second.y) *
                (a[1].first.y - a[1].second.y) <
        1LL * (a[0].second.x - a[1].second.x) *
                (a[0].second.x - a[1].second.x) +
            1LL * (a[0].second.y - a[1].second.y) *
                (a[0].second.y - a[1].second.y)) {
      cout << "NO\n";
      continue;
    }
    if (prod(a[0].first, a[0].second, a[2].second) &&
        prod(a[1].first, a[1].second, a[2].first))
      swap(a[2].first, a[2].second);
    if (!ok1(a[0].first, a[0].second, a[2].first) ||
        !ok1(a[1].first, a[1].second, a[2].second)) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
  }
}
