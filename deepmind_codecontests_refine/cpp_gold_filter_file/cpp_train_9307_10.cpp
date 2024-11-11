#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
constexpr T sgn(T a) {
  return a == 0 ? 0 : (a < 0 ? -1 : 1);
}
struct Point {
  long long x, y;
};
struct Line {
  long long A, B, C;
  Line(long long a = 0, long long b = 1, long long c = 0) : A(a), B(b), C(c) {
    long long g = gcd(gcd(abs(A), abs(B)), abs(C));
    A /= g;
    B /= g;
    C /= g;
    if (A < 0 || (A == 0 || B < 0)) {
      A = -A;
      B = -B;
      C = -C;
    }
  }
};
Line getLine(const Point &a, const Point &b) {
  long long dx = b.x - a.x;
  long long dy = -(b.y - a.y);
  return Line(dy, dx, dy * a.x + dx * a.y);
}
Line perpLine(const Line &li, const Point &p) {
  long long a = -li.B, b = li.A;
  return Line(a, b, p.x * a + p.y * b);
}
bool operator<(const Line &g, const Line &h) {
  if (g.A != h.A) return g.A < h.A;
  if (g.B != h.B) return g.B < h.B;
  if (g.C != h.C) return g.C < h.C;
  return false;
}
const int maxN = 1024;
int N, K;
map<long long, vector<Point>> circ;
map<Line, map<long long, int>> segs;
int main() {
  cin >> N >> K;
  for (int i = (0); i < (N); i++) {
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Point a{x1 * 2, y1 * 2};
    Point b{x2 * 2, y2 * 2};
    Line li = getLine(a, b);
    {
      if (0) fprintf(stderr, "li: a %lld, b %lld, c %lld\n", li.A, li.B, li.C);
    };
    long long pa = a.x * li.B - a.y * li.A;
    long long push_back = b.x * li.B - b.y * li.A;
    if (pa > push_back) swap(pa, push_back);
    segs[li][pa + 0]++;
    segs[li][push_back + 1]--;
  }
  for (int i = (0); i < (K); i++) {
    long long x, y, r;
    cin >> x >> y >> r;
    circ[r * 2].push_back(Point{x * 2, y * 2});
  }
  for (auto &s : segs) {
    s.second[LLONG_MIN / 2] = 0;
    s.second[LLONG_MAX / 2] = 0;
    {
      if (0) fprintf(stderr, "seg\n");
    };
    int prev = 0;
    for (auto &e : s.second) {
      {
        if (0) fprintf(stderr, "%lld: %d\n", e.first, e.second);
      };
      e.second = (prev += e.second);
      {
        if (0) fprintf(stderr, "    %d\n", prev);
      };
    }
  }
  int res = 0;
  for (const auto &ci : circ) {
    for (int ia = (0); ia < (int((ci.second).size())); ia++) {
      for (int ib = (ia + 1); ib < (int((ci.second).size())); ib++) {
        Point a = ci.second[ia];
        Point b = ci.second[ib];
        Point d{b.x - a.x, b.y - a.y};
        if (d.x * d.x + d.y * d.y <= ci.first * ci.first * 4) continue;
        Point m{a.x + d.x / 2, a.y + d.y / 2};
        {
          if (0) fprintf(stderr, "M: %lld %lld\n", m.x, m.y);
        };
        Line li = perpLine(getLine(a, b), m);
        {
          if (0)
            fprintf(stderr, "li: a %lld, b %lld, c %lld\n", li.A, li.B, li.C);
        };
        if (!((segs).find(li) != (segs).end())) continue;
        long long pp = m.x * li.B - m.y * li.A;
        {
          if (0) cerr << "DBGDO: " << ("pp") << " = " << (pp) << endl;
        };
        auto it = segs[li].upper_bound(pp);
        assert(it != segs[li].begin());
        it--;
        res += it->second;
      }
    }
  }
  cout << res << endl;
}
