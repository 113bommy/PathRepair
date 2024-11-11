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
int a, b, c, d;
int s[200001];
int main() {
  scanf("%d%d%d%d", &a, &b, &c, &d);
  if (a > b) swap(a, b);
  s[1] = a;
  s[c] = b;
  int e = a;
  int h = 2;
  while (e < b) {
    e += d;
    s[h++] = e;
    if (h > c) s[h] = b;
  }
  int px = h, py = c - 1;
  while (px <= py) {
    s[py] = s[py + 1] + d;
    py--;
    if (px <= py) {
      s[px] = s[px - 1] + d;
      px++;
    }
  }
  int res = 0;
  for (int i = (1); i <= (c); i++) res += s[i];
  printf("%d\n", res);
  return 0;
}
