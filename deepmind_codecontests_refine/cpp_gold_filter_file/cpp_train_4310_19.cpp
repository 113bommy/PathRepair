#include <bits/stdc++.h>
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  if (k >= n * (n - 1) / 2) {
    printf("no solution\n");
    return 0;
  }
  for (int i = 0; i < n; ++i) printf("0 %d\n", i);
}
