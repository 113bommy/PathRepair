#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    long long s, a, b, c, sum = 0;
    scanf("%lld%lld%lld%lld", &s, &a, &b, &c);
    sum = s / c;
    if (sum >= a) {
      sum = sum + ((s / a) * b);
    }
    printf("%lld\n", sum);
  }
  return 0;
}
