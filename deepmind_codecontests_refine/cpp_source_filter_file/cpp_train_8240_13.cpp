#include <bits/stdc++.h>
int main() {
  long long int n, i, sum, a, b, c, r;
  scanf("%lld", &n);
  for (i = 0; i < n; i++) {
    scanf("%lld%lld%lld", &a, &b, &c);
    sum = a + b + c;
    r = sum / 3;
    printf("%lld\n", r);
  }
}
