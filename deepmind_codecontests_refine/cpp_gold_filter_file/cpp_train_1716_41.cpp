#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}
long long min(long long a, long long b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}
struct P {
  double x, y;
  P() {}
  P(int x, int y) : x(double(x)), y(double(y)) {}
  P(double x, double y) : x(x), y(y) {}
  P operator+(const P &a) const { return P(x + a.x, y + a.y); }
  P operator-(const P &a) const { return P(x - a.x, y - a.y); }
  double operator^(const P &a) const { return x * a.x + y * a.y; }
  void in() { scanf("%lf%lf", &x, &y); }
  void out() { printf("REQUIRED %.7f %.7f\n", x, y); }
  double dist(P a, P b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
  }
  double sqdist(P a, P b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
  }
};
long long c, hr, hb, wr, wb;
long long res = 0;
int main() {
  cin >> c >> hr >> hb >> wr >> wb;
  if (wr < wb) {
    int t = wr;
    wr = wb;
    wb = t;
    t = hr;
    hr = hb;
    hb = t;
  }
  if (wr > 50) {
    long long cur = 0;
    while (c >= 0) {
      res = max(res, cur + (long long)(c / wb) * hb);
      c -= wr;
      cur += (long long)hr;
    }
  } else {
    if ((long long)wr * hb < (long long)wb * hr) {
      int t = wr;
      wr = wb;
      wb = t;
      t = hr;
      hr = hb;
      hb = t;
    }
    long long cur = 0;
    long long opt = 0;
    while (opt <= wr * wb && opt <= c) {
      res = max(res, cur + (long long)(c - opt) / wb * hb);
      cur += (long long)hr;
      opt += wr;
    }
  }
  cout << res << endl;
  return 0;
}
