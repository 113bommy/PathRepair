#include <bits/stdc++.h>
int main() {
  long long int n, i, a, b, c;
  scanf("%lld", &n);
  for (i = 1; i <= n; i++) {
    scanf("%lld %lld %lld", &a, &b, &c);
    c = (a + b + c) / 2;
    printf("%lld\n", c);
  }
}
