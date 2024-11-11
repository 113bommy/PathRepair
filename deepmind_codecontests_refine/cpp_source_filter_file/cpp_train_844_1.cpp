#include <bits/stdc++.h>
int main() {
  int a, b, i, j, n;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    printf("%c", 97 + i % 5);
  }
  printf("\n");
  return 0;
}
