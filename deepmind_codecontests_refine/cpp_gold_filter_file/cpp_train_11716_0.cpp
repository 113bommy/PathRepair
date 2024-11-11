#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
double dist(int x1, int y1, int x2, int y2) {
  return sqrt((long long)(x1 - x2) * (x1 - x2) +
              (long long)(y1 - y2) * (y1 - y2));
}
int main() {
  int ax, ay, bx, by, tx, ty;
  cin >> ax >> ay >> bx >> by >> tx >> ty;
  int i;
  int n;
  cin >> n;
  vector<double> pre(n + 1), suff(n + 2), Be(n + 1);
  pre[0] = suff[n + 1] = inf;
  double tot = 0.0;
  for (i = 1; i < n + 1; i++) {
    int x, y;
    cin >> x >> y;
    double t = dist(tx, ty, x, y);
    tot += 2 * t;
    pre[i] = suff[i] = dist(ax, ay, x, y) - t;
    Be[i] = dist(bx, by, x, y) - t;
  }
  for (i = 1; i < n + 1; i++) {
    pre[i] = min(pre[i - 1], pre[i]);
  }
  for (i = n; i > 0; i--) {
    suff[i] = min(suff[i + 1], suff[i]);
  }
  double ans = tot + suff[1];
  for (i = 1; i < n + 1; i++) {
    ans = min(ans, tot + min(0.0, min(pre[i - 1], suff[i + 1])) + Be[i]);
  }
  cout << fixed << setprecision(15) << ans << endl;
  return 0;
}
