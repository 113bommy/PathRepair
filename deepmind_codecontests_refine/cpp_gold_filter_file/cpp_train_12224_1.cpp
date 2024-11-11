#include <bits/stdc++.h>
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
using namespace std;
const double eps = 1e-10;
int sgn(double x) { return (x > eps) - (x < -eps); }
int cmp(double x, double y) { return sgn(x - y); }
struct P {
  double x, y, k;
  P() : x(0), y(0) {}
  P(double a, double b) : x(a), y(b) {}
  void in() { scanf("%lf%lf", &x, &y); }
  P operator+(const P &a) const { return P(x + a.x, y + a.y); }
  P operator-(const P &a) const { return P(x - a.x, y - a.y); }
  P operator*(const double &a) const { return P(x * a, y * a); }
  P operator/(const double &a) const { return P(x / a, y / a); }
  double norm2() { return x * x + y * y; }
} p[1000 + 5];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    p[i] = P((double)a / b, (double)c / d);
    p[i] = p[i] / p[i].norm2();
  }
  vector<P> pt;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i - 1; j++) {
      P mid = (p[i] + p[j]) / 2, tmp = p[i] - p[j];
      mid.k = sgn(tmp.x) == 0 ? 1e100 : tmp.y / tmp.x;
      pt.push_back(mid);
    }
  sort(pt.begin(), pt.end(), [](P a, P b) {
    if (cmp(a.x, b.x)) return cmp(a.x, b.x) < 0;
    if (cmp(a.y, b.y)) return cmp(a.y, b.y) < 0;
    return a.k < b.k;
  });
  int N = pt.size();
  long long ans = 0;
  for (int l = 0, r; l < N; l = r) {
    for (r = l;
         r < N && cmp(pt[r].x, pt[l].x) == 0 && cmp(pt[r].y, pt[l].y) == 0; r++)
      ;
    int c = 2, ways = 1;
    for (int i = l + 1; i <= r; i++) {
      if (i < r && cmp(pt[i].k, pt[i - 1].k) == 0)
        c++;
      else
        ways = 1ll * ways * c % 1000000007, c = 2;
    }
    ans = (ans + ways - 1 - (r - l) + 1000000007) % 1000000007;
  }
  printf("%lld\n", ans);
  return 0;
}
