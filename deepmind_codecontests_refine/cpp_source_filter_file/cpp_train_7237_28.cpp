#include <bits/stdc++.h>
int main() {
  int n, a;
  scanf("%d %d", &n, &a);
  if ((n % 2) == 1) {
    printf("%d", (n / 2) + 1);
  } else {
    printf("%d", (n / 2) - a + 1);
  }
  return 0;
}
