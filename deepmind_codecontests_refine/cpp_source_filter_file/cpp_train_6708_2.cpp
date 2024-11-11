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
int m, n;
int ma[50001][101];
int fin[50001][101];
int main() {
  scanf("%d%d", &m, &n);
  for (int i = (1); i <= (m); i++)
    for (int j = (1); j <= (n); j++) scanf("%d", &ma[i][j]);
  fin[1][1] = ma[1][1];
  for (int i = (2); i <= (m); i++) fin[i][1] = fin[i - 1][1] + ma[i][1];
  for (int j = (2); j <= (n); j++) {
    fin[1][j] = ma[1][j] + ma[1][j - 1];
    for (int i = (2); i <= (m); i++)
      fin[i][j] = max(fin[i - 1][j] + ma[i][j], fin[i][j - 1] + ma[i][j]);
  }
  for (int i = (1); i <= (m); i++) printf("%d ", fin[i][n]);
  puts("");
  return 0;
}
