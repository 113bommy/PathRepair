#include <bits/stdc++.h>
using namespace std;
long long gcd(long long aa, long long bb, long long &x, long long &y) {
  if (bb) {
    long long an = gcd(bb, aa % bb, x, y);
    x = x - (aa / bb) * y;
    swap(x, y);
    return an;
  } else {
    x = 1ll;
    y = 0ll;
    return aa;
  }
}
int main() {
  long long n, p, w, d, x, a, b, y;
  scanf("%lld%lld%lld%lld", &n, &p, &w, &d);
  if (p == 0) return printf("%d %d %lld", 0, 0, n), 0;
  x = gcd(w, d, a, b);
  if (p % x) return printf("-1"), 0;
  y = w / x;
  b = b * ((p / x) % y);
  b = (b % y + y) % y;
  if (a / d < b) return printf("-1"), 0;
  a = (p - b * d) / w;
  if (a + b > n) return printf("-1"), 0;
  if (a * w + b * d != n) return printf("-1"), 0;
  printf("%lld %lld %lld", a, b, n - a - b);
}
