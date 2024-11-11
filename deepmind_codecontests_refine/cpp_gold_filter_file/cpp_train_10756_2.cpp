#include <bits/stdc++.h>
using namespace std;
long long x1, x2, a, b;
int main() {
  scanf("%lld%lld%lld%lld", &x1, &x2, &a, &b);
  long long len = abs(x2 - x1);
  if (a * b <= 0) {
    if (x1 + a <= x2 && x2 <= x1 + b) {
      printf("FIRST\n%lld", x2);
    } else {
      printf("DRAW\n");
    }
    return 0;
  }
  if ((x1 < x2 && a < 0 && b < 0) || (x1 > x2 && a > 0 && b > 0)) {
    printf("DRAW\n");
    return 0;
  }
  if (a < 0 && b < 0 && x1 > x2) {
    a = -a;
    b = -b;
    swap(a, b);
  }
  if (len % (a + b) == 0) {
    printf("SECOND\n");
  } else {
    if (len % (a + b))
      if (x1 > x2 && a <= len % (a + b) && len % (a + b) <= b) {
        printf("FIRST\n%lld", x1 - len % (a + b));
      } else if (a <= len % (a + b) && len % (a + b) <= b) {
        printf("FIRST\n%lld", len % (a + b) + x1);
      } else {
        printf("DRAW\n");
      }
  }
  return 0;
}
