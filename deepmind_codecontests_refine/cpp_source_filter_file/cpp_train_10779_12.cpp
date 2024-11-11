#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
struct TPoint {
  double x, y;
  explicit TPoint(double x = 0.0, double y = 0.0) : x(x), y(y) {}
  TPoint operator+(const TPoint &p) const { return TPoint(x + p.x, y + p.y); }
  TPoint operator-(const TPoint &p) const { return TPoint(x - p.x, y - p.y); }
  TPoint operator-() const { return TPoint(-x, -y); }
  TPoint operator*(double p) const { return TPoint(p * x, p * y); }
  double operator*(const TPoint &p) const { return x * p.x + y * p.y; }
  double operator%(const TPoint &p) const { return x * p.y - y * p.x; }
  TPoint rotate() const { return TPoint(y, -x); }
  double operator~() const { return sqrt(*this * *this); }
  TPoint norm() const { return *this * (1.0 / ~*this); }
};
const int maxn = 500;
const double eps = 1e-9;
TPoint p[maxn];
TPoint intersect(TPoint n1, double v1, TPoint n2, double v2) {
  assert(fabs(n1 % n2) > eps);
  double D = n1 % n2;
  return TPoint((TPoint(v1, n1.y) % TPoint(v2, n2.y)) / D,
                (TPoint(n1.x, v1) % TPoint(n2.x, v2)) / D);
}
bool halfplanes(vector<pair<TPoint, double> > h, TPoint &res) {
  random_shuffle((h).begin(), (h).end());
  TPoint up = -h[0].first;
  TPoint best;
  for (int i = 0; i < (int)(h.size()); ++i) {
    if (fabs(h[0].first % h[i].first) < eps) continue;
    best = intersect(h[0].first, h[0].second, h[i].first, h[i].second);
    break;
  }
  for (int i = 1; i <= (int)(h.size() - 1); ++i) {
    if (h[i].first * best > h[i].second - eps) continue;
    TPoint any;
    for (int j = 0; j < (int)(i); ++j) {
      if (fabs(h[i].first % h[j].first) < eps) continue;
      any = intersect(h[i].first, h[i].second, h[j].first, h[j].second);
      break;
    }
    TPoint v = h[i].first.rotate();
    TPoint L = any + v * 1e9, R = any - v * 1e9;
    bool g = true;
    for (int j = 0; j < (int)(i); ++j) {
      g &= h[j].first * L - h[j].second > -eps ||
           h[j].first * R - h[j].second > -eps;
      if (!g) break;
      if (fabs(h[i].first % h[j].first) < eps) continue;
      if (h[j].first * L < h[j].second)
        L = intersect(h[i].first, h[i].second, h[j].first, h[j].second);
      if (h[j].first * R < h[j].second)
        R = intersect(h[i].first, h[i].second, h[j].first, h[j].second);
    }
    if (!g) return false;
    bool ok = false;
    if (h[i].first * L - h[i].second > -eps) {
      if (!ok || up * L > up * best) best = L;
      ok = true;
    }
    if (h[i].first * R - h[i].second > -eps) {
      if (!ok || up * R > up * best) best = R;
      ok = true;
    }
    if (!ok) return false;
  }
  res = best;
  return true;
}
pair<TPoint, double> toTheLeft(TPoint a, TPoint b) {
  TPoint n = TPoint(b.y - a.y, a.x - b.x).norm();
  return make_pair(n, n * a);
}
bool inside(TPoint a, const vector<pair<TPoint, double> > &h) {
  for (auto w : h) {
    if (w.first * a - w.second < -eps) return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  int n;
  cin >> n;
  for (int i = 0; i < (int)(n); ++i) cin >> p[i].x >> p[i].y;
  p[n] = p[0];
  double L = 0.0, R = 1e5;
  vector<pair<TPoint, double> > P(n);
  for (int i = 0; i < (int)(n); ++i) {
    P[i] = toTheLeft(p[i + 1], p[i]);
  }
  TPoint A, B;
  cerr.precision(10);
  for (int its = 0; its < (int)(50); ++its) {
    double M = 0.5 * (L + R);
    bool ok = false;
    vector<pair<TPoint, double> > h;
    for (int i = 0; i < (int)(n); ++i) {
      h.push_back(P[i]);
      h.push_back(make_pair(-P[i].first, -P[i].second - M));
    }
    vector<TPoint> cands;
    for (int i = 0; i < (int)(n); ++i) cands.push_back(p[i]);
    for (int i = 0; i < (int)(n); ++i) {
      TPoint n1 = -P[i].first;
      double v1 = -P[i].second - M;
      for (int j = 0; j < (int)(n); ++j) {
        if (fabs(n1 % P[j].first) < eps) continue;
        if ((n1 * p[j] > v1) != (n1 * p[j + 1] > v1))
          cands.push_back(intersect(n1, v1, P[j].first, P[j].second));
      }
    }
    for (TPoint a : cands) {
      if (ok) break;
      if (!inside(a, P)) continue;
      vector<pair<TPoint, double> > H = P;
      for (auto w : h) {
        if (w.first * a - w.second < -eps) H.push_back(w);
      }
      TPoint b;
      if (halfplanes(H, b)) {
        A = a;
        B = b;
        ok = true;
      }
    }
    (ok ? R : L) = M;
  }
  cout << R << '\n';
  cout << A.x << ' ' << A.y << '\n';
  cout << B.x << ' ' << B.y << '\n';
  return 0;
}
