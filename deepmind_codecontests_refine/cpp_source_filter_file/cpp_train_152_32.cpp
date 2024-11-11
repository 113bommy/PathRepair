#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int it_count = 80;
int a[maxn];
int n;
inline double f(double x) {
  double cur = 0, minn = 0, maxx = 0;
  double ret = 0.0;
  for (int pos = 0; pos < (int)n; pos++) {
    cur += a[pos] - x;
    minn = min(minn, cur);
    maxx = max(maxx, cur);
    ret = max(ret, max(abs(cur - minn), abs(cur - maxx)));
  }
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int j = 0; j < (int)n; j++) scanf("%d", &a[j]);
  double start = -1e5;
  double finish = 1e5;
  for (int iter = 0; iter < (int)it_count; iter++) {
    double m1 = start + (finish - start) / 3;
    double m2 = finish - (finish - start) / 3;
    double f1 = f(m1);
    double f2 = f(m2);
    if (f1 < f2)
      finish = m2;
    else
      start = m1;
  }
  double ans = f(start);
  printf("%.10lf\n", ans);
}
