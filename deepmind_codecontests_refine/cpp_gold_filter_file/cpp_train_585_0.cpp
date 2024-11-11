#include <bits/stdc++.h>
using namespace std;
double k, d, t, ans, r, rlen, change, chick;
signed main() {
  cin >> k >> d >> t;
  r = (long long)((k - 1) / d) + 1;
  rlen = r * d;
  change = (long long)(2 * t / (rlen + k));
  chick = 2 * t - (rlen + k) * change;
  ans += change * rlen;
  if (chick < 2 * k)
    ans += chick / 2;
  else
    ans += k, ans += chick - 2 * k;
  printf("%.10lf", ans);
  return 0;
}
