#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const double PI = acos(-1.0);
const int N = 2010;
struct Point {
  double x, y;
  Point(double x, double y) : x(x), y(y) {}
  Point() {}
  Point operator+(const Point &o) const { return Point(x + o.x, y + o.y); }
  Point operator-(const Point &o) const { return Point(x - o.x, y - o.y); }
  Point operator*(double k) const { return Point(x * k, y * k); }
  Point operator/(double k) const { return Point(x / k, y / k); }
  double len() const { return sqrt(x * x + y * y); }
};
double dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }
int sign(double a) { return a < -eps ? -1 : a > eps; }
Point pts[N], dir[N], foot[N];
int n;
int main() {
  cin >> n;
  int zeros = 0;
  for (int i = 0; i < n; ++i) {
    int a, b, c, d;
    cin >> a >> b >> c;
    if (c == 0) {
      zeros++;
      i--;
      n--;
      continue;
    }
    d = a * a + b * b;
    dir[i] = Point(-b, a) / (double)d;
    pts[i] = Point(-c * a, -c * b) / (double)d;
  }
  int ans = 0;
  if (zeros == 2) {
    ans += n;
  }
  Point origin(0, 0);
  for (int i = 0; i < n; ++i) {
    foot[i] = pts[i] + dir[i] * dot(origin - pts[i], dir[i]);
  }
  for (int i = 0; i < n; ++i) {
    vector<double> v;
    for (int j = i + 1; j < n; ++j) {
      Point delta = foot[j] - foot[i];
      double alpha = atan2(delta.y, delta.x);
      while (alpha < -eps) {
        alpha += PI;
      }
      while (alpha >= PI - eps) {
        alpha -= PI;
      }
      v.push_back(alpha);
    }
    sort(v.begin(), v.end());
    for (int j = 0; j < v.size(); ++j) {
      int k = j + 1;
      while (k < v.size() && sign(v[k] - v[j]) == 0) {
        k++;
      }
      int cnt = k - j;
      ans += cnt * (cnt - 1) / 2;
      j = k - 1;
    }
  }
  cout << ans << endl;
}
