#include <bits/stdc++.h>
using namespace std;
long long n, k, l, r, a, b, res;
long long le(long long x, long long y) {
  if (x >= 0) {
    return x / y;
  } else {
    return -((-x + y - 1) / y);
  }
}
long long ge(long long x, long long y) {
  if (x >= 0) {
    return (x + y - 1) / y;
  } else {
    return -((-x) / y);
  }
}
int main() {
  scanf("%lld%lld%lld%lld", &n, &l, &r, &k);
  a = r - l + 1ll;
  if (a <= 0) a += n;
  b = n - a;
  res = -1 * 1ll;
  if (n <= 2000 * 1ll) {
    for (long long x = 0; x <= a; ++x) {
      for (long long y = 0; y <= b; ++y) {
        long long kk = k - a - x;
        long long tt = a + b + x + y;
        if (kk % tt == 0) {
          res = max(res, x + y);
        }
        ++kk;
        if (kk % tt == 0 && x > 0) {
          res = max(res, x + y);
        }
      }
    }
  } else {
    for (long long t = 0; t <= k / n; ++t) {
      if (t == 0) {
        long long kk = k - a;
        if (kk >= 0 && kk <= a) {
          res = max(res, kk + b);
        }
        ++kk;
        if (kk >= 1 && kk <= a) {
          res = max(res, kk + b);
        }
        continue;
      }
      long long kk = k - a * (t + 1ll) - b * t;
      long long maxs = min(le(a - kk, t), le(-kk, t + 1));
      long long mins = max(ge(-kk, t), ge(-kk - b, t + 1));
      if (mins <= maxs) {
        res = max(res, -mins);
      }
      ++kk;
      maxs = min(le(a - kk, t), le(-kk, t + 1));
      mins = max(ge(1 - kk, t), ge(-kk - b, t + 1));
      if (mins <= maxs) {
        res = max(res, -mins);
      }
    }
  }
  printf("%lld\n", res);
  return 0;
}
