#include <bits/stdc++.h>
int main() {
  long long N, K, i, j, count = 0, ans = 1;
  scanf("%lld %lld", &N, &K);
  if (K == 1)
    printf("%lld", N);
  else {
    while (N != 0) {
      N >>= 1;
      count += 1;
    }
    while (count--) ans *= 2;
    printf("%lld", ans - 1);
  }
  return 0;
}
