#include <bits/stdc++.h>
using namespace std;
int n, m, k;
bool debug = false;
struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
  double abs() const { return hypot(x, y); }
  double arg() const { return atan2(y, x); }
  Point operator*(double o) const { return Point(x * o, y * o); }
  Point operator+(const Point& o) const { return Point(x + o.x, y + o.y); }
  Point operator-(const Point& o) const { return Point(x - o.x, y - o.y); }
  bool operator<(const Point& o) const {
    return x < o.x - 1e-9 || (x < o.x + 1e-9 && y < o.y - 1e-9);
  }
  Point scale(double o) const { return *this * (o / abs()); }
  Point rotY() const { return Point(-y, x); }
  Point rotX() const { return Point(y, -x); }
};
struct Tirangle {
  Point p[3];
  double len[3];
  void init() {
    for (int i = 0; i < 3; i++) {
      len[i] = (p[(i + 1) % 3] - p[i]).abs();
    }
    sort(len, len + 3);
  }
};
void makeT(const Point& a, const Point& b, double da, double db,
           vector<Point>& ret, int dump = 0) {
  double sum = (a - b).abs();
  double dif = (da * da - db * db) / sum;
  double ra = (sum + dif) / 2;
  double rb = (sum - dif) / 2;
  double h = da * da - ra * ra;
  if (h < -1e-9) {
    return;
  } else {
    h = sqrt(max(0.0, h));
  }
  Point v = (b - a).scale(h);
  ret.push_back(a + (b - a).scale(ra) + v.rotY());
  ret.push_back(a + (b - a).scale(ra) + v.rotX());
  ret.push_back(a + (b - a).scale(rb) + v.rotY());
  ret.push_back(a + (b - a).scale(rb) + v.rotX());
}
Tirangle t[4];
int main() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%lf%lf", &t[i].p[j].x, &t[i].p[j].y);
    }
    t[i].init();
  }
  int ans = 9;
  double edge[4];
  for (int i = 0; i < 81; i++) {
    for (int j = 0, k = i; j < 4; j++, k /= 3) {
      edge[j] = t[j].len[k % 3];
    }
    if (*max_element(edge, edge + 4) * 2 - accumulate(edge, edge + 4, 0) <
        1e-9) {
      ans = 8;
      break;
    }
  }
  vector<Point> v;
  for (int i = 0; i < 12; ++i) {
    for (int j = (i / 3 + 1) * 3; j < 12; ++j) {
      for (int k = (j / 3 + 1) * 3; k < 12; ++k) {
        Point a(0, 0);
        Point b(t[i / 3].len[i % 3], 0);
        v.clear();
        makeT(a, b, t[j / 3].len[j % 3], t[k / 3].len[k % 3], v);
        if (v.empty()) {
          continue;
        }
        Point c = v[0];
        vector<Point> va, vb, vc;
        makeT(a, b, t[i / 3].len[(i + 1) % 3], t[i / 3].len[(i + 2) % 3], va);
        makeT(a, c, t[j / 3].len[(j + 1) % 3], t[j / 3].len[(j + 2) % 3], vb);
        makeT(b, c, t[k / 3].len[(k + 1) % 3], t[k / 3].len[(k + 2) % 3], vc);
        for (const Point& pa : va) {
          for (const Point& pb : vb) {
            for (const Point& pc : vc) {
              set<Point> st = {a, b, c, pa, pb, pc};
              ans = min(ans, (int)st.size() + 2);
              for (int l = 0; l < 12; ++l) {
                if (i / 3 + j / 3 + k / 3 + l / 3 != 6) {
                  continue;
                }
                for (const Point& u : st) {
                  for (const Point& v : st) {
                    if (fabs((u - v).abs() - t[l / 3].len[l % 3]) > 1e-9) {
                      continue;
                    }
                    vector<Point> vd;
                    makeT(u, v, t[l / 3].len[(l + 1) % 3],
                          t[l / 3].len[(l + 2) % 3], vd);
                    for (const Point& pd : vd) {
                      ans = min(ans, (int)st.size() + 1 - (int)st.count(pd));
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  int tmp = 3;
  for (int i = 1; i < 4; ++i) {
    int acc = 2;
    for (int j = 0; j < i; ++j) {
      bool same = true;
      for (int k = 0; k < 3 && same; ++k) {
        same &= fabs(t[i].len[k] - t[j].len[k]) < 1e-9;
      }
      if (same) {
        acc = 0;
        break;
      }
    }
    for (int j = 0; j < 3 * i && acc > 1; ++j) {
      for (int k = 0; k < 3; ++k) {
        if (fabs(t[j / 3].len[j % 3] - t[i].len[k]) < 1e-9) {
          acc = 1;
          break;
        }
      }
    }
    tmp += acc;
  }
  ans = min(ans, tmp);
  printf("%d\n", ans);
  return 0;
}
