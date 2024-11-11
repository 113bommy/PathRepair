#include <bits/stdc++.h>
using namespace std;
double eps = 1e-9;
struct point {
  double x, y;
  point() {}
  point(double x1, double y1) {
    x = x1;
    y = y1;
  }
  bool operator<(const point &t) const {
    return x < t.x - eps || fabs(x - t.x) < eps && y < t.y - eps;
  }
  point operator-(const point &t) { return point(x - t.x, y - t.y); }
  point operator+(const point &t) { return point(x + t.x, y + t.y); }
  double operator*(const point &t) { return x * t.x + y * t.y; }
  double operator%(const point &t) { return x * t.y - y * t.x; }
  point operator/(double k) { return point(x / k, y / k); }
  point operator*(double k) { return point(x * k, y * k); }
  double dis() { return x * x + y * y; }
} a[100008];
set<point> F;
int n;
struct Tprogram {
  void open() {
    freopen("", "r", stdin);
    freopen("", "w", stdout);
  }
  void close() {
    fclose(stdin);
    fclose(stdout);
  }
  void rand_init() {
    srand(time(0));
    n = 100;
    for (int i = 1; i <= n; i++) a[i].x = rand(), a[i].y = rand();
  }
  void init() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lf%lf", &a[i].x, &a[i].y);
  }
  point get(point a, point b, point c) {
    point d = (a + b) / 2;
    point d1 = d + point(a.y - b.y, b.x - a.x);
    point e = (a + c) / 2;
    point e1 = e + point(a.y - c.y, c.x - a.x);
    double s1 = (e1 - e) % (d - e), s2 = (d1 - e) % (e1 - e);
    return (d * s2 + d1 * s1) / (s1 + s2);
  }
  void work() {
    double ans = -1;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++)
        for (int k = j + 1; k <= n; k++) {
          if (fabs((a[i] - a[j]) % (a[i] - a[k])) <= eps) continue;
          point g = get(a[i], a[j], a[k]);
          if (F.find(g) != F.end()) continue;
          double tmp = 1e12, t;
          vector<point> H;
          H.clear();
          for (int l = 1; l <= n; l++)
            if ((t = (a[l] - g).dis()) < tmp - eps)
              H.clear(), H.push_back(a[l]), tmp = (a[l] - g).dis();
            else if (fabs(t - tmp) < eps)
              H.push_back(a[l]);
          if (fabs((a[i] - g).dis() - tmp) > eps) continue;
          if (fabs((a[j] - g).dis() - tmp) > eps) continue;
          if (fabs((a[k] - g).dis() - tmp) > eps) continue;
          F.insert(g);
          for (int i = 0; i <= H.size() - 1; i++) {
            point t = H[i] - g;
            for (int j = 0; j <= H.size() - 1; j++)
              if ((H[j] - g) % t > eps) goto die;
            goto die1;
          die:;
          }
          ans = (ans > (a[i] - g).dis() ? ans : (a[i] - g).dis());
        die1:;
        }
    if (ans < 0.5)
      printf("-1\n");
    else
      printf("%lf\n", sqrt(ans));
  }
} Program;
int main() {
  Program.init();
  Program.work();
  return 0;
}
