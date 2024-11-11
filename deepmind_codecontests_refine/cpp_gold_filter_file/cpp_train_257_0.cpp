#include <bits/stdc++.h>
using namespace std;
const long double PI = acos((long double)-1), eps = 1e-18;
long double ang[800000];
int main() {
  long long n, c, d, r, w, hi, lo, ans, i;
  while (~scanf("%lld%lld%lld", &n, &c, &d)) {
    for (i = 0; i < n; i++) {
      scanf("%lld%lld", &r, &w);
      ang[i] = atan2(w - d, r - c);
    }
    sort(ang, ang + n);
    for (i = 0; i < n + 3; i++) {
      ang[n + i] = ang[i] + 2 * PI;
    }
    ans = n * (n - 1) * (n - 2) / 6;
    lo = hi = 0;
    for (i = 0; i < n; i++) {
      while (ang[lo] - ang[i] < PI - eps) lo++;
      while (ang[hi + 1] - ang[i] < PI + eps) hi++;
      ans -= (hi - i) * (hi - i - 1) / 2;
      ans += (hi - lo) * (hi - lo + 1) / 2;
    }
    cout << ans << endl;
  }
}
