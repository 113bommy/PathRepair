#include <bits/stdc++.h>
int main() {
  int l, r, n;
  scanf("%d", &n);
  while (n--) {
    scanf("%d %d %d", &l, &r, &n);
    if (l > n) {
      printf("%d\n", n);
      continue;
    }
    long long k = r / n;
    printf("%lld\n", (k + 1) * n);
  }
  return 0;
}
