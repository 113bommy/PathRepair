#include <bits/stdc++.h>
int main() {
  long long int n, k, m;
  scanf("%lld %lld", &n, &k);
  if (n % 2 == 0) {
    if (k <= n / 2)
      m = 2 * k - 1;
    else
      m = (k - n / 2) * 2;
  } else if (n % 2 == 1) {
    if (k <= (n / 2 + 1))
      m = 2 * k - 1;
    else
      m = (k - (n / 2 + 1)) * 2;
  }
  printf("%lld", m);
  return 0;
}
