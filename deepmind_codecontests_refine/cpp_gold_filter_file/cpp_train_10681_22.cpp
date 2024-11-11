#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
inline double ef(double x, double y) { return y - x; }
class Cover {
  vector<pair<double, int> > vec;

 public:
  void clear() { vec.clear(); }
  void add_cover(double l, double r) {
    vec.push_back(make_pair(l, 1));
    vec.push_back(make_pair(r, -1));
  }
  template <class T>
  double cal(double l, double r, T f) {
    int t = 0;
    double ans = 0, ll = -1e100, rr;
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size() && ll < r; ++i) {
      rr = vec[i].first;
      if (t && rr > l) ans += f(max(ll, l), rr);
      t += vec[i].second;
      ll = rr;
    }
    return ans;
  }
};
double h, f, ans;
struct Line {
  double x1, x2;
};
struct Trape {
  Line l, r;
};
bool operator<=(const Line &a, const Line &b) {
  return a.x1 < b.x1 + eps && a.x2 < b.x2 + eps;
}
bool cross(const Line &a, const Line &b) {
  return (a.x1 < b.x1) ^ (a.x2 < b.x2);
}
double crossy(const Line &a, const Line &b) {
  double d1 = b.x1 - a.x1, d2 = b.x2 - a.x2;
  return -h / (d1 - d2) * d2;
}
vector<Trape> vectrape;
Cover upline;
void add_window(double l, double r) {
  double l1 = l / (f - h) * f, r1 = r / (f - h) * f;
  double l2 = l / (f - h) * (f + h), r2 = r / (f - h) * (f + h);
  upline.add_cover(l, r);
  upline.add_cover(l2, r2);
  vectrape.push_back((Trape){l, l1, r, r1});
  vectrape.push_back((Trape){l2, l1, r2, r1});
}
struct AreaCaler {
  const Line &a;
  AreaCaler(const Line &_a) : a(_a) {}
  double operator()(double l, double r) {
    return (l + r) * (r - l) * (a.x1 - a.x2) / (2 * h);
  }
};
double cal_line(const Line &a, bool right, int except) {
  Cover cov;
  for (int i = 0; i < vectrape.size(); ++i)
    if (i != except) {
      const Trape &b = vectrape.at(i);
      if (a <= b.l || b.r <= a) continue;
      if (b.l <= a && a <= b.r) return 0;
      double cl = 0, cr = h, y;
      if (cross(a, b.l)) {
        y = crossy(a, b.l);
        if (a.x1 < b.l.x1)
          cr = min(cr, y);
        else
          cl = max(cl, y);
      }
      if (cross(a, b.r)) {
        y = crossy(a, b.r);
        if (a.x1 < b.r.x1)
          cl = max(cl, y);
        else
          cr = min(cr, y);
      }
      cov.add_cover(cl, cr);
    }
  AreaCaler ac(a);
  double ans = ac(0, h) - cov.cal(0, h, ac);
  return right ? -ans : ans;
}
int main() {
  double l, r;
  int n;
  cin >> n >> h >> f;
  while (n--) {
    cin >> l >> r;
    add_window(l, r);
  }
  ans = upline.cal(-1e100, 1e100, ef) * h;
  for (int i = 0; i < vectrape.size(); ++i)
    ans += cal_line(vectrape[i].l, false, i),
        ans += cal_line(vectrape[i].r, true, i);
  ans *= 2;
  cout.precision(8);
  cout << fixed << ans;
}
