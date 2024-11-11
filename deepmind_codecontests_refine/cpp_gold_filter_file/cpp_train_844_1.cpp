#include <bits/stdc++.h>
int main() {
  int n, a, b;
  scanf("%d", &n);
  a = n / 4;
  b = n % 4;
  for (n = 0; n < a; n++) printf("abcd");
  if (b == 1)
    printf("a");
  else if (b == 2)
    printf("ab");
  else if (b == 3)
    printf("abc");
  printf("\n");
  return 0;
}
