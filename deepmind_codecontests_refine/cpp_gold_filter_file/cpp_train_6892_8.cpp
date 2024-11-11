#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int at, bt, ax, bx, ot;
int main() {
  scanf("%d %d %d %d %d", &at, &bt, &ax, &bx, &ot);
  if (at == bt) {
    printf("%d %d\n", ax, bx);
    return 0;
  }
  if (ot == at) {
    printf("%d 0\n", ax);
    return 0;
  }
  if (ot == bt) {
    printf("0 %d\n", bx);
    return 0;
  }
  long long fa = 1LL << 40, fb = 1;
  int ay, by;
  int s = -1;
  for (int i = 1; i <= ax; ++i) {
    long long y = ((long long)i * (ot - at) - 1) / (bt - ot) + 1;
    if (y > bx) continue;
    long long ta = (long long)i * (at - ot) + (long long)y * (bt - ot);
    long long tb = i + y, p = i + y;
    long long d = gcd(ta, tb);
    ta /= d;
    tb /= d;
    if (ta * fb < fa * tb) {
      fa = ta;
      fb = tb;
      s = p;
      ay = i;
      by = y;
    } else if (ta * fb == fa * tb && p > s) {
      fa = ta;
      fb = tb;
      s = p;
      ay = i;
      by = y;
    }
  }
  if (fa == (1LL << 40)) ay = 0, by = bx;
  printf("%d %d\n", ay, by);
  return 0;
}
