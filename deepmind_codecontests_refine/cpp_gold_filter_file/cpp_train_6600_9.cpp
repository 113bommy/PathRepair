#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) {
  if (x < y) swap(x, y);
  if (y == 0) return x;
  return gcd(y, x % y);
}
long long lcm(long long x, long long y) { return x * y / gcd(x, y); }
int main() {
  long long a, b, c, d;
  while (~scanf("%I64d%I64d%I64d%I64d", &a, &b, &c, &d)) {
    long long Lcm = lcm(a, c);
    long long aa = Lcm;
    long long bb = b * (Lcm / a);
    long long h = min(bb / d, Lcm / c);
    long long cc = h * c;
    long long dd = h * d;
    long long up, down;
    up = (aa - cc) * bb + aa * (bb - dd), down = aa * bb;
    long long di = gcd(up, down);
    if (di != 0) {
      up /= di, down /= di;
    }
    Lcm = lcm(b, d);
    bb = Lcm;
    aa = a * (Lcm / b);
    h = min(aa / c, Lcm / d);
    cc = h * c;
    dd = h * d;
    double up1 = (aa - cc) * bb + aa * (bb - dd), down1 = aa * bb;
    di = gcd(up1, down1);
    if (di != 0) {
      up1 /= di, down1 /= di;
    }
    double x1 = 1.0 * up / down, x2 = 1.0 * up1 / down1;
    if (x1 > x2) {
      up = up1;
      down = down1;
    }
    printf("%I64d/%I64d\n", up, down);
  }
  return 0;
}
