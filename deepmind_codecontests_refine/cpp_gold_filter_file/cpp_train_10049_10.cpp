#include <bits/stdc++.h>
int main(int argc, const char* argv[]) {
  int n, k;
  scanf("%d%d", &n, &k);
  if (k > n / 2) k = n / 2;
  printf("%I64d\n", k * (2 * n - 2 * k - 1ll));
  return 0;
}
