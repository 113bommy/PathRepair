#include <bits/stdc++.h>
int main() {
  long long int n, m, a, x, y;
  scanf("%lld%lld%lld", &n, &m, &a);
  if (m % a == 0)
    x = m / a;
  else
    x = m / a + 1;
  if (n % a == 0)
    y = n / a;
  else
    y = n / a + 1;
  printf("ll%d", (x * y));
  printf("\n");
  return 0;
}
