#include <bits/stdc++.h>
int n;
int main() {
  scanf("%d", &n);
  if (n % 2 != 0) return printf("0"), 0;
  printf("%d", (n / 4) % 2 == 0 ? n / 4 - 1 : n / 4);
}
