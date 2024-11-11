#include <bits/stdc++.h>
int main() {
  long long s, n, p;
  scanf("%lld%lld", &n, &s);
  if (s == n)
    printf("1");
  else if (s % n == 0) {
    p = s / n;
    printf("%lld", p);
  } else if (s % n != 0) {
    p = s / n;
    printf("%lld", p + 1);
  }
  return 0;
}
