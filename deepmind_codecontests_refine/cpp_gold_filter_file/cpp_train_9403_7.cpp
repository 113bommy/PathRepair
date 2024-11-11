#include <bits/stdc++.h>
int main() {
  int n, k, mark[50], passer = 0;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &mark[i]);
  for (int i = 1; i <= n; i++) {
    if ((mark[i] >= mark[k]) && mark[i] > 0) passer = passer + 1;
  }
  printf("%d", passer);
  return 0;
}
