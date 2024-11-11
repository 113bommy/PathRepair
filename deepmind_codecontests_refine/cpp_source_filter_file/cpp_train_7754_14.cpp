#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  while (n % 2 == 0) {
    n = n / 2;
  }
  if (n == 1)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
