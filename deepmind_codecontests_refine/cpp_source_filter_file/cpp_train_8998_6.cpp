#include <bits/stdc++.h>
int main() {
  int c, sum = 0, a = 0, b;
  while ((c = getchar()) != '\n') {
    b = a;
    a = c;
  }
  sum = a + b;
  if (sum % 4 == 0)
    printf("%d\n", 4);
  else
    printf("%d\n", 0);
  return 0;
}
