#include <bits/stdc++.h>
using namespace std;
pair<int, int> p[500005];
int n;
bool ok(double t) {
  bool r = false;
  double maxR = 0;
  for (int i = 0; i < n; i++) {
    double pp = p[i].first + p[i].second * t;
    if (p[i].second > 0) {
      if (r == false) maxR = pp;
      maxR = max(pp, maxR);
      r = true;
    } else if (pp <= maxR && r)
      return true;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", &p[i].first, &p[i].second);
  sort(p, p + n);
  double start = 0;
  double end = 1e18;
  bool k = false;
  for (int i = 0; i < 100; i++) {
    double mid = (end + start) / 2;
    if (ok(mid))
      end = mid, k = true;
    else
      start = mid;
  }
  if (!k)
    puts("-1");
  else
    printf("%.13lf\n", end);
  return 0;
}
