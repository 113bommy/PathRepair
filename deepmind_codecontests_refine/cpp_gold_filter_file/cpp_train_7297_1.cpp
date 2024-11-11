#include <bits/stdc++.h>
using namespace std;
const int inf32 = 1e9 + 9;
const long long inf64 = 1e18 + 18;
const int N = 1e5 + 10, S = 26;
const int D = 1e6 + 6;
const unsigned int seed = 1007;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
map<pair<int, int>, int> st;
const long double EPS = 5E-8;
struct pt {
  long double x, y;
  bool operator<(const pt &p) const {
    return x < p.x - EPS || abs(x - p.x) < EPS && y < p.y - EPS;
  }
  pt() {}
  pt(int _x, int _y) {
    x = _x;
    y = _y;
  }
};
struct line {
  long double a, b, c;
  line() {}
  line(pt p, pt q) {
    a = p.y - q.y;
    b = q.x - p.x;
    c = -a * p.x - b * p.y;
    norm();
  }
  void norm() {
    long double z = sqrt(a * a + b * b);
    if (abs(z) > EPS) a /= z, b /= z, c /= z;
  }
  long double dist(pt p) const { return a * p.x + b * p.y + c; }
};
inline bool betw(long double l, long double r, long double x) {
  return min(l, r) <= x + EPS && x <= max(l, r) + EPS;
}
inline bool intersect_1d(long double a, long double b, long double c,
                         long double d) {
  if (a > b) swap(a, b);
  if (c > d) swap(c, d);
  return max(a, c) <= min(b, d) + EPS;
}
bool intersect(pt a, pt b, pt c, pt d, pt &left, pt &right) {
  if (!intersect_1d(a.x, b.x, c.x, d.x) || !intersect_1d(a.y, b.y, c.y, d.y))
    return false;
  line m(a, b);
  line n(c, d);
  long double zn = (m.a * n.b - m.b * n.a);
  if (abs(zn) < EPS) {
    if (abs(m.dist(c)) > EPS || abs(n.dist(a)) > EPS) return false;
    if (b < a) swap(a, b);
    if (d < c) swap(c, d);
    left = max(a, c);
    right = min(b, d);
    return true;
  } else {
    left.x = right.x = -(m.c * n.b - m.b * n.c) / zn;
    left.y = right.y = -(m.a * n.c - m.c * n.a) / zn;
    return betw(a.x, b.x, left.x) && betw(a.y, b.y, left.y) &&
           betw(c.x, d.x, left.x) && betw(c.y, d.y, left.y);
  }
}
bool eq(pt a, pt b) { return (fabs(a.x - b.x) < EPS && fabs(a.y - b.y) < EPS); }
void solve() {
  vector<pair<pt, pt>> vc;
  int n, x1, y1, x2, y2;
  scanf("%d", &n);
  long long ans = n;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    x1 += D, y1 += D, x2 += D, y2 += D;
    int x = abs(x1 - x2), y = abs(y1 - y2);
    int g = gcd(x, y);
    ans += g;
    pt a(x1, y1);
    pt b(x2, y2);
    for (int j = 0; j < i; ++j) {
      pt l, r;
      if (eq(a, vc[j].first) || eq(a, vc[j].second)) {
        ++st[{x1, y1}];
      } else if (eq(b, vc[j].first) || eq(b, vc[j].second)) {
        ++st[{x2, y2}];
      } else if (intersect(a, b, vc[j].first, vc[j].second, l, r)) {
        int xI = l.x + EPS, yI = l.y + EPS;
        if (!x) {
          if (xI != x1 || yI > max(y1, y2) || yI < min(y1, y2)) continue;
        } else if (!y) {
          if (yI != y1 || xI > max(x1, x2) || xI < min(x1, x2)) continue;
        } else if (abs(x1 - xI) % (x / g) || abs(y1 - yI) % (y / g))
          continue;
        if (fabs(l.x - xI) < EPS && fabs(yI - l.y) < EPS) ++st[{xI, yI}];
      }
    }
    vc.push_back({a, b});
  }
  unordered_map<int, int> cnt;
  for (int i = 2; i <= n; ++i) cnt[i * (i - 1) / 2] = i - 1;
  for (auto &x : st) {
    int d = x.second;
    while (!cnt.count(d)) ++d;
    ans -= cnt[d];
  }
  cout << ans << endl;
}
int main() {
  solve();
  return 0;
}
