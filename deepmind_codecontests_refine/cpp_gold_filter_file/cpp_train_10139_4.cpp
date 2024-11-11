#include <bits/stdc++.h>
int main() {
  int n, k, i;
  scanf("%d%d", &n, &k);
  for (i = 0; i < n % k; i++) printf("%d ", n / k + 1);
  for (; i < k; i++) printf("%d ", n / k);
  return 0;
}
