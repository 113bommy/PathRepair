#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  printf("%d", n);
  for (int i = 2; i <= n; ++i) printf(" %d", n - 1);
  printf("\n");
  return 0;
}
