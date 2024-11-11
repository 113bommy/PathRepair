#include <bits/stdc++.h>
int main(void) {
  unsigned short int m, n, c;
  scanf("%hu%hu", &m, &n);
  c = m * n;
  int i = 1;
  while (i) {
    if (c >= 2 * i)
      i++;
    else
      break;
  }
  printf("%d\n", (i - 1));
  return 0;
}
