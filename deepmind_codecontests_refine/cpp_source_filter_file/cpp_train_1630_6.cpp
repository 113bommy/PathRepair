#include <bits/stdc++.h>
const double eps = 1e-9;
int main() {
  long long k, d, t;
  scanf("%lld %lld %lld", &k, &d, &t);
  if (k >= d && k % d == 0) {
    printf("%lld\n", t);
  } else {
    long long tmp = (long long)(k / d);
    long long min = (tmp + 1) * d;
    double val = (double)k + (min - k) * 0.5;
    long long ans = (long long)t * 1.0 / val;
    double ed = (double)t, kk = (double)k, aans = (double)ans,
           mmin = (double)min;
    if (abs(val * aans - ed) <= eps) {
      printf("%.9f\n", aans * min);
    } else {
      double now = (aans)*val;
      if (ed - now > kk)
        printf("%.9f\n", aans * mmin + kk + (ed - now - kk) * 2.0);
      else
        printf("%.9f\n", aans * mmin + (ed - now));
    }
  }
  return 0;
}
