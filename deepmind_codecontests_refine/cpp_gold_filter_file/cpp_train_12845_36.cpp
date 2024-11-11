#include <bits/stdc++.h>
const int maxn = 2005;
int n, k;
int main() {
  int i, j;
  scanf("%d%d", &n, &k);
  int sum = 0;
  for (i = 0; i < n; i++) sum += i;
  if (sum <= k) {
    printf("no solution\n");
    return 0;
  }
  for (i = 0; i < n; i++) printf("%d %d\n", 0, i);
  return 0;
}
