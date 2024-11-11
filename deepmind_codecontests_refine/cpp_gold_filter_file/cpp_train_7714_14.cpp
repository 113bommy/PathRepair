#include <bits/stdc++.h>
int main() {
  long long l, r;
  scanf("%lld%lld", &l, &r);
  printf("YES\n");
  for (; l < r; l += 2) {
    printf("%lld %lld\n", l, l + 1);
  }
  return 0;
}
