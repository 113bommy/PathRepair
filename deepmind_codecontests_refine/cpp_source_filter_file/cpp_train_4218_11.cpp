#include <bits/stdc++.h>
using namespace std;
long long x, y;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  scanf("%I64d%I64d", &x, &y);
  if (gcd(x, y) != 1)
    printf("Impossible\n");
  else {
    while (x && y) {
      if (x > y) {
        if (y == 1) x--;
        printf("%dA", x / y);
        x = x % y;
      } else {
        if (x == 1) y--;
        printf("%dB", y / x);
        y = y % x;
      }
    }
  }
  return 0;
}
