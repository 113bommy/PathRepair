#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", n / 3 * 2 + ((n - 1) % 3));
  return 0;
}
