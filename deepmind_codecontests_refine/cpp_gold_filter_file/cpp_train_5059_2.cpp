#include <bits/stdc++.h>
bool check(long s, long p) {
  long i = (s / 50) % 475;
  for (long j = 0; j < 25; j++) {
    i = (i * 96 + 42) % 475;
    if (i + 26 == p) return true;
  }
  return false;
}
int main() {
  long p, x, y;
  scanf("%ld%ld%ld", &p, &x, &y);
  long ans = 0x7fffffff;
  for (long i = 0; x - i * 50 >= y; i++)
    if (check(x - i * 50, p)) {
      ans = 0;
      break;
    }
  if (ans != 0) {
    for (long i = 1; i < 1e6; i++)
      if (check(x + i * 100 - 50, p) || check(x + i * 100, p)) {
        ans = i;
        break;
      }
  }
  printf("%ld\n", ans);
  return 0;
}
