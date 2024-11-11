#include <bits/stdc++.h>
int main(int argc, char const *argv[]) {
  long long i, t, n, l, r, d;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld%lld", &l, &r);
    d = r - l + 1;
    if (d % 2 == 0) {
      if (r % 2 == 0)
        printf("%lld\n", d / 2);
      else
        printf("%lld\n", -d / 2);
    } else {
      d = d - 1;
      d = d / 2;
      if (r % 2 == 0)
        printf("%lld\n", d + r);
      else
        printf("%lld\n", d - r);
    }
  }
  return 0;
}
