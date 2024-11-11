#include <bits/stdc++.h>
using namespace std;
int a[300005];
int n;
long double ans = 10000000000;
long double test(long double x) {
  long double sum = 0;
  long double mn = 0;
  long double mx = 0;
  long double ret = 0;
  for (int i = 0; i < n; i++) {
    sum += (a[i] - x);
    ret = max(ret, abs(sum - mn));
    ret = max(ret, abs(sum - mx));
    mn = min(mn, sum);
    mx = max(mx, sum);
  }
  ans = min(ans, ret);
  return ret;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  long double s = -10000000, e = 10000000;
  while (e - s > 1e-12) {
    long double t1 = s + (e - s) / 3;
    long double t2 = s + (e - s) * 2 / 3;
    long double v1 = test(t1);
    long double v2 = test(t2);
    if (v1 < v2) {
      e = t2;
    } else {
      s = t1;
    }
  }
  printf("%.9Lf", ans);
}
