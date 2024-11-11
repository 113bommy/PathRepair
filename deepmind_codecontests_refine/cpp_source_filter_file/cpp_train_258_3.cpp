#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
double xx[maxn], yy[maxn];
double dist(double x, double y, double x1, double y1, double x2, double y2) {
  if ((x - x1) * (x2 - x1) + (y - y1) * (y2 - y1) <= 0)
    return sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));
  if ((x - x2) * (x1 - x2) + (y - y2) * (y1 - y2) <= 0)
    return sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));
  return abs(((x - x1) * (y2 - y1) - (x2 - x1) * (y - y1)) /
             sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
int main() {
  double maxx = 0, minn = 2000000;
  int n;
  double x, y;
  scanf("%d%f%f", &n, &x, &y);
  for (int i = 1; i <= n; i++) {
    scanf("%f%f", &xx[i], &yy[i]);
    double ans = sqrt((xx[i] - x) * (xx[i] - x) + (yy[i] - y) * (yy[i] - y));
    maxx = max(maxx, ans);
    if (i == 1) continue;
    double anss = dist(x, y, xx[i - 1], yy[i - 1], xx[i], yy[i]);
    minn = min(minn, anss);
  }
  minn = min(minn, dist(x, y, xx[n], yy[n], xx[1], yy[1]));
  double answer = acos(-1) * (maxx * maxx - minn * minn);
  printf("%lf\n", answer);
}
