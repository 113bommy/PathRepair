#include <bits/stdc++.h>
int main() {
  int t, i;
  long long int s, a, b, c, z;
  scanf("%d", &t);
  for (i = 1; i <= t; i++) {
    scanf("%lld %lld %lld %lld", &s, &a, &b, &c);
    if (s >= c) {
      z = ((s / c) / a * b) + (s / c);
      printf("%lld\n", z);
    } else
      printf("0\n");
  }
  return 0;
}
