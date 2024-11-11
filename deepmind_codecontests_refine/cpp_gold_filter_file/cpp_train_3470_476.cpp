#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  if (n == 5)
    printf("1");
  else
    printf("%d", n % 3 + 1);
  return 0;
}
