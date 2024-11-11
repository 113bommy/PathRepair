#include <bits/stdc++.h>
int main() {
  int m, b;
  long long ans = 0;
  scanf("%d %d", &m, &b);
  for (int i = 0; i <= b; i++) {
    int sum = 0;
    sum += (long long)i * (i + 1) / 2 * ((b - i) * m + 1);
    sum += (long long)(b - i) * m * ((b - i) * m + 1) / 2 * (i + 1);
    if (sum > ans) ans = sum;
  }
  printf("%lld", ans);
  return 0;
}
