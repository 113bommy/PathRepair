#include <bits/stdc++.h>
int main() {
  int n;
  scanf(" %d", &n);
  if (n == 1 || n == 2)
    printf("7\n");
  else if (n % 2 == 1)
    printf("1\n");
  else
    printf("%d\n", n - 2);
  return 0;
}
