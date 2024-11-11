#include <bits/stdc++.h>
int main() {
  long long m, n, a, l1, l2, k;
  scanf("%d %d", &m, &n);
  scanf("%d", &a);
  l1 = m / a;
  l2 = n / a;
  if (m % a != 0 && n % a != 0) {
    k = l1 * l2 + l1 + l2 + 1;
  } else if (m % a != 0) {
    k = l1 * l2 + l2;
  } else if (n % a != 0) {
    k = l1 * l2 + l1;
  } else {
    k = l1 * l2;
  }
  printf("%lld", k);
  return 0;
}
