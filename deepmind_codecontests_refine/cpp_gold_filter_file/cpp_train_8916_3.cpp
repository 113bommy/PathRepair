#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
const long double eps = 1e-8;
struct point {
  long double x, y;
  point() {}
  point(long double x, long double y) : x(x), y(y) {}
  point friend operator+(point a, point b) {
    return point(a.x + b.x, a.y + b.y);
  }
  point friend operator-(point a, point b) {
    return point(a.x - b.x, a.y - b.y);
  }
};
long double det(point p1, point p2) { return p1.x * p2.y - p1.y * p2.x; }
long double dot(point p1, point p2) { return p1.x * p2.x + p1.y * p2.y; }
int sig(long double x) { return fabs(x) < eps ? 0 : x > 0 ? 1 : -1; }
point rot(point a, long double ang) {
  return point(a.x * cos(ang) - a.y * sin(ang),
               a.x * sin(ang) + a.y * cos(ang));
}
point rot(point a, point b, long double ang) { return rot(b - a, ang) + a; }
long double norm(point a) { return sqrt(a.x * a.x + a.y * a.y); }
long double calc_ang(point a, point b) {
  return acos(dot(a, b) / norm(a) / norm(b));
}
const int N = 2e5 + 10;
point arr[N];
int n, q;
point calc() {
  long double s = 0.0;
  long double x = 0.0, y = 0.0;
  for (int i = 1; i < n - 1; i++) {
    long double tem = fabs(det(arr[i] - arr[0], arr[i + 1] - arr[0]));
    s += tem;
    x += (arr[0].x + arr[i].x + arr[i + 1].x) / 3.0 * tem;
    y += (arr[0].y + arr[i].y + arr[i + 1].y) / 3.0 * tem;
  }
  x /= s;
  y /= s;
  return point(x, y);
}
int main() {
  std::ios::sync_with_stdio(false);
  cout << fixed << setprecision(8);
  while (cin >> n >> q) {
    for (int i = 0; i < n; i++) {
      cin >> arr[i].x >> arr[i].y;
    }
    point center = calc();
    point c = center;
    int p1 = 0, p2 = 1;
    long double ang = 0;
    for (int i = 0; i < q; i++) {
      int x, a, b;
      cin >> x;
      if (x == 1) {
        cin >> a >> b;
        a--, b--;
        if (p1 != a) swap(p1, p2);
        p1 = b;
        point t = rot(c, arr[p2], -ang) + (center - c);
        long double tem = calc_ang(center - t, point(0.0, -1.0));
        if (sig(det(point(0.0, -1.0), center - t)) < 0) {
          ang -= tem;
          center = rot(t, center, tem);
        } else if (sig(det(point(0.0, -1.0), center - t)) > 0) {
          ang += tem;
          center = rot(t, center, -tem);
        } else {
          if (sig(center.y - t.y) > 0) {
            ang += pi;
            center = t + t - center;
          }
        }
      } else {
        cin >> a;
        a--;
        point t = rot(c, arr[a], -ang) + (center - c);
        cout << t.x << ' ' << t.y << endl;
      }
    }
  }
}
