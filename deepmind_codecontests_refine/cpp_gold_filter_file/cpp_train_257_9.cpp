#include <bits/stdc++.h>
using namespace std;
const long double PI = atan2((long double)0, (long double)-1);
const long double eps = 1e-18;
long long n, c, d;
long double ang[800005];
long long C2(long long n) { return n * (n - 1) / 2; }
int main() {
  while (scanf("%I64d%I64d%I64d", &n, &c, &d) == 3) {
    for (long long i = 0; i < n; i++) {
      long long x, y;
      scanf("%I64d%I64d", &x, &y);
      x -= c;
      y -= d;
      ang[i] = atan2(y, x);
    }
    sort(ang, ang + n);
    for (long long i = 0; i < n + 3; i++) ang[i + n] = ang[i] + 2 * PI;
    long long l = 0, h = 0;
    long long ans = n * (n - 1) / 2 * (n - 2) / 3;
    for (long long i = 0; i < n; i++) {
      while (ang[l] - ang[i] < PI - eps) l++;
      while (ang[h + 1] - ang[i] < PI + eps) h++;
      ans -= C2(h - i);
      ans += C2(h - l + 1);
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
