#include <bits/stdc++.h>
long long t[10] = {0, 9};
int main() {
  int i, n;
  long long base = 1, ans = 0;
  for (i = 2; i < 10; i++) {
    t[i] = t[i - 1] * 10;
  }
  scanf("%d", &n);
  for (i = 1; i < 10; i++) {
    if (n >= base && n < base * 10) {
      ans += i * (n - base + 1);
      break;
    } else {
      ans += i * t[i];
    }
    base *= 10;
  }
  if (n == 1000000000) ans += 10;
  printf("%I64d", ans);
  return 0;
}
