#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int p = n;
  if (n == 0) {
    printf("1");
    return 0;
  }
  printf("%d", 4 * (int)(n * sqrt(1.0)));
  return 0;
}
