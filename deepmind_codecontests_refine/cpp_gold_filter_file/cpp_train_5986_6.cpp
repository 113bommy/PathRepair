#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x, y;
  Point() : x(), y() {}
  Point(int _x, int _y) : x(_x), y(_y) {}
  Point operator+(const Point &A) const { return Point(x + A.x, y + A.y); }
  Point operator-(const Point &A) const { return Point(x - A.x, y - A.y); }
  double operator*(const Point &A) const { return x * 1. * A.y - y * 1. * A.x; }
  void read() { scanf("%d%d", &x, &y); }
};
const int MAGIC = 140;
const int maxn = (int)1e5 + 100;
double pow2[maxn];
Point P[2 * maxn];
double rp[maxn];
const int MX = (int)1e3;
int table[MX][MX];
double getProb(int len, int n) {
  int diff = n - len;
  double ans = 1. / pow2[diff];
  if (n < MAGIC) {
    double up = pow2[n];
    up -= 1. + n + (double)n * (double)(n - 1) / 2.;
    double down = pow2[len];
    down -= 1.;
    ans = down / up;
  }
  return ans;
}
void init() {
  pow2[0] = 1;
  for (int i = 1; i < MAGIC; i++) pow2[i] = pow2[i - 1] * 2.;
  for (int i = 0; i < MX; i++)
    for (int j = i; j < MX; j++) {
      table[i][j] = (i == 0 ? j : table[j % i][i]);
    }
}
int gcd(int a, int b) {
  if (a < MX) return table[b][a];
  return b ? gcd(b, a % b) : a;
}
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n - 1; i++) {
    rp[i] = getProb(i, n);
  }
  for (int i = 0; i < n; i++) {
    P[i].read();
    P[i + n] = P[i];
  }
  double ES = 0, EB = 0;
  double ans = 2;
  for (int i = 0; i < n; i++)
    for (int skip = 0; skip + 2 < n && skip < MAGIC - 5; skip++) {
      int len = n - skip - 2;
      double p = rp[len];
      Point A = P[i];
      Point B = P[i + skip + 1];
      double s = A * B;
      int dx = abs(A.x - B.x);
      int dy = abs(A.y - B.y);
      int g = gcd(max(dx, dy), min(dx, dy));
      ans += (s - g) * p;
    }
  ans += ES - EB;
  ans /= 2.;
  printf("%.10lf\n", ans);
}
int main(int, char **) {
  init();
  solve();
  return 0;
}
