#include <bits/stdc++.h>
using namespace std;
int main() {
  long long s, x, a, tempx, temps;
  scanf("%I64d%I64d", &s, &x);
  tempx = x, temps = s;
  if ((s - x) % 2 != 0) {
    printf("0\n");
  } else {
    long long ans = 1;
    long long a = (s - x) / 2;
    while (x > 0) {
      long long xorbit = (x & 1);
      long long andbit = (a & 1);
      if (xorbit == 1) {
        if (andbit == 1)
          ans = 0;
        else
          ans *= 2;
      }
      x >>= 1;
      a >>= 1;
    }
    if (temps == tempx) ans -= 2;
    printf("%I64d\n", ans);
  }
  return 0;
}
