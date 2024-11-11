#include <bits/stdc++.h>
int main() {
  long long n, k, tom;
  scanf("%I64d %I64d", &n, &k);
  if (n % 2 == 0)
    tom = (n / 2);
  else
    tom = (n / 2) + 1;
  if (k <= tom) {
    printf("%I64d", (2 * (k)-1));
  } else {
    k = k - tom;
    printf("%I64d", (2 * k));
  }
  return 0;
}
