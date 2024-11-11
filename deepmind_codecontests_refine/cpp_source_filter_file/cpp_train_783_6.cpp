#include <bits/stdc++.h>
using namespace std;
pair<int, int> p[10100];
int main() {
  int n, w, v, u;
  cin >> n >> w >> v >> u;
  for (int i = 1; i <= n; ++i) scanf("%d%d", &p[i].first, &p[i].second);
  int c1 = 0, c2 = 0;
  for (int i = 1; i <= n; ++i) {
    if ((long long)p[i].first * v - (long long)u * p[i].second < 0)
      ++c1;
    else if ((long long)p[i].first * v - (long long)u * p[i].second > 0)
      ++c2;
  }
  if (c1 * c2 == 0) {
    printf("%.10lf\n", (double)w / u);
    return 0;
  }
  double l = 0, r = 1e9;
  for (int k = 0; k < 100; ++k) {
    double m = (l + r) / 2;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; ++i) {
      if ((p[i].first - m) * u - (long long)v * p[i].second < 0)
        ++cnt1;
      else if ((p[i].first - m) * u - (long long)v * p[i].second > 0)
        ++cnt2;
    }
    if (cnt1 > 0 && cnt2 > 0)
      l = m;
    else
      r = m;
  }
  printf("%.10lf\n", (double)w / u + l / v);
  return 0;
}
