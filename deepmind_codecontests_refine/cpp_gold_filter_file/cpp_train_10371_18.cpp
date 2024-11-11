#include <bits/stdc++.h>
using namespace std;
int n, a[105][105], m;
pair<long double, long double> d[105][10];
int main() {
  scanf("%d", &n);
  m = 1 << n;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  }
  int h = (1 << 1);
  for (int i = 1; i <= m; i++) {
    if (i % 2 == 0) {
      d[i][1].first = a[i][i - 1] / 100.0;
    } else
      d[i][1].first = a[i][i + 1] / 100.0;
    d[i][1].second = d[i][1].first;
  }
  for (int l = 2; l <= n; l++) {
    int num = 1 << l;
    for (int i = 1; i <= m; i++) {
      int x = i % num, s, e;
      if (x <= num / 2 && x != 0) {
        s = i - x + num / 2 + 1;
      } else if (x != 0) {
        s = i - x + 1;
      } else {
        s = i - num + 1;
      }
      e = s + num / 2 - 1;
      double sum = 0;
      double val = 0;
      d[i][l].second = d[i][l - 1].second;
      double mx = 0;
      for (int j = s; j <= e; j++) {
        long double tmp =
            (a[i][j] / 100.0) * d[i][l - 1].first * d[j][l - 1].first;
        long double ts = tmp * (1 << (l - 1));
        sum += tmp;
        mx = fmax(mx, d[j][l - 1].second);
        d[i][l].second += ts;
      }
      d[i][l].first = sum;
      d[i][l].second += mx;
    }
  }
  double ans = 0;
  for (int i = 1; i <= m; i++) {
    ans = fmax(ans, d[i][n].second);
  }
  printf("%.12lf\n", ans);
  return 0;
}
