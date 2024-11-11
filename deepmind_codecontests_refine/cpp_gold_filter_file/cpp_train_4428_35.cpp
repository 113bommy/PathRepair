#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  long long ans = (6 * (1LL * n * (n + 1)) / 2);
  printf("%I64d\n", ans + 1);
}
