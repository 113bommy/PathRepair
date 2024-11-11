#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k, d, t, x1, x2;
  double x, ans = 0.0, y, y1, y2;
  cin >> k >> d >> t;
  if (k >= t) {
    cout << t << endl;
    return 0;
  }
  if (k % d == 0) {
    cout << t << endl;
    return 0;
  }
  if (k < d) {
    x = ((double)(k) + (.5) * (double)(d - k));
    y = (long long)((double)(t) / x);
    ans += (y * (double)(d));
    y1 = y * x;
    y1 = (double)(t)-y1;
    y2 = y1 - (double)(k);
    if (y2 < 0) {
      ans += ((double)(t) - (double)(y * x));
    } else {
      ans += (double)(k);
      ans += (.5) * (y2);
    }
    printf("%.10f\n", ans);
    return 0;
  }
  x1 = k / d;
  x1 = (d * (x1 + 1));
  x2 = x1 * d;
  x = (double)(k) + (.5) * ((double)(x1) - (double)(k));
  y = (long long)((double)(t) / x);
  ans = (double)(y) * (double)(x1);
  x *= (double)(y);
  if ((long long)((double)(t)-x) > k) {
    ans += (double)(k);
    y1 = ((double)(t)-x) - (double)(k);
    ans += ((2.0) * (y1));
  } else {
    ans += ((double)(t)-x);
  }
  printf("%.10f\n", ans);
  return 0;
}
