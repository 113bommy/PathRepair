#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
const double eps = 1e-12;
using Point = complex<double>;
ostream &operator<<(ostream &os, Point p) {
  return os << real(p) << " " << imag(p);
}
template <class T>
T dist2(T x, T y) {
  return x * x + y * y;
}
Point circumcenter(Point &A, Point &B, Point &C) {
  double x1 = real(B - A), y1 = imag(B - A), d1 = norm(B - A);
  double x2 = real(C - A), y2 = imag(C - A), d2 = norm(C - A);
  double x = (y2 * d1 - y1 * d2) / (y2 * x1 - y1 * x2) / 2;
  double y = (x2 * d1 - x1 * d2) / (x2 * y1 - x1 * y2) / 2;
  return A + Point(x, y);
}
double circumradius(Point &A, Point &B, Point &C) {
  double a = abs(B - C), b = abs(C - A), c = abs(A - B);
  double d = sqrt((a + b + c) * (-a + b + c) * (a - b + c) * (a + b - c));
  return a * b * c / d;
}
int main() {
  cout << fixed << setprecision(12);
  int n;
  cin >> n;
  vector<Point> ps(n);
  vector<int> xs(n), ys(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    ps[i] = {1.0 * x, 1.0 * y};
    xs[i] = x, ys[i] = y;
  }
  vector<vector<double>> ds(n, vector<double>(n));
  vector<vector<int>> d2s(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      ds[i][j] = abs(ps[i] - ps[j]);
      d2s[i][j] = dist2(xs[i] - xs[j], ys[i] - ys[j]);
    }
  auto check = [&](Point &O, double r2) {
    for (auto &p : ps)
      if (norm(p - O) / r2 < 1.0 - eps) return false;
    return true;
  };
  double ans = 0.0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
      for (int k = 0; k < j; k++) {
        int d1 = d2s[i][j], d2 = d2s[j][k], d3 = d2s[k][i];
        if (d1 + d2 > d3 && d2 + d3 > d1 && d3 + d1 > d2) {
          Point O = circumcenter(ps[i], ps[j], ps[k]);
          double R = circumradius(ps[i], ps[j], ps[k]);
          if (check(O, R * R)) chmax(ans, R);
        }
      }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++) {
      [&]() {
        for (int k = 0; k < n; k++)
          for (int l = 0; l < k; l++) {
            if (d2s[i][j] != d2s[k][l]) continue;
            if (d2s[i][k] != d2s[j][l]) continue;
            if (d2s[i][l] != d2s[j][k]) continue;
            if (d2s[i][j] > d2s[i][k] && d2s[i][j] > d2s[i][l]) {
              Point O = (ps[i] + ps[j]) / 2.0;
              double R = ds[i][j] / 2;
              if (check(O, R * R)) {
                chmax(ans, R);
                return;
              }
            }
          }
      }();
    }
  if (ans == 0.0) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
