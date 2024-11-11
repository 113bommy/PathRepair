#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  if (n == 1)
    printf("1");
  else {
    if (n % 2 == 0) printf("%d", (n / 2));
    if (n % 2 != 0) printf("%d", ((n - 1) / 2));
  }
  return 0;
}
