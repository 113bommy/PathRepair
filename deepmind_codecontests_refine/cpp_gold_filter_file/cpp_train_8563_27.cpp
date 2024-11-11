#include <bits/stdc++.h>
long GCD(long a, long b) {
  if (b == 0)
    return a;
  else
    return GCD(b, (a % b));
}
long sum(long val, long base) {
  long x = 0;
  while ((val % base) || (val / base)) {
    x += (val % base);
    val /= base;
  }
  return x;
}
int main() {
  long a, i, ans, y;
  while (scanf("%ld", &a) != EOF) {
    ans = 0;
    for (i = 2; i < a; i++) ans += sum(a, i);
    y = a - 2;
    i = GCD(ans, y);
    ans /= i;
    y /= i;
    printf("%ld/%ld\n", ans, y);
  }
  return 0;
}
