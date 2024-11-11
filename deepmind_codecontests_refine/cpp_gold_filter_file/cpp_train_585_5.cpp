#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k, d, t;
  cin >> k >> d >> t;
  t *= 2;
  double tt = t * 1.0;
  long long u = (k + d - 1) / d * d;
  long long tmp = k * 2 + u - k;
  double ans = 0.0;
  ans += t / tmp * u;
  tt -= t / tmp * tmp;
  if (tt <= 2 * k)
    ans += 0.5 * tt;
  else {
    ans += k;
    tt -= 2 * k;
    ans += 1.0 * tt;
  }
  printf("%.15lf\n", ans);
}
