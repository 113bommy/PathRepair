#include <bits/stdc++.h>
int main() {
  long long l, r, num = 0, i, j, k, lol;
  scanf("%lld%lld", &l, &r);
  for (j = 0; j <= 50; j++) {
    for (k = 0; k <= 50; k++) {
      lol = pow(2, j) * pow(3, k);
      if (lol >= l && lol <= r) {
        num++;
      }
    }
  }
  printf("%lld", num);
  return 0;
}
