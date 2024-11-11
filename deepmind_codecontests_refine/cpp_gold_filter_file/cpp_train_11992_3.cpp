#include <bits/stdc++.h>
int main() {
  int n, x, one = 0, zero = 0;
  scanf("%d", &n);
  char str[n];
  scanf("%s", str);
  x = strlen(str);
  for (int i = 0; i < x; i++) {
    if (str[i] == 'z')
      ++zero;
    else if (str[i] == 'n')
      ++one;
  }
  while (one != 0) {
    printf("1 ");
    one = one - 1;
  }
  while (zero != 0) {
    printf("0 ");
    zero = zero - 1;
  }
  return 0;
}
