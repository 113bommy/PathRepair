#include <bits/stdc++.h>
int main() {
  int n, i;
  scanf("%d", &n);
  if (n == 1 || n == 2)
    printf("-1\n");
  else {
    printf("3 2");
    for (i = 3; i <= n; i++) printf(" 1");
    printf("\n");
  }
  return 0;
}
