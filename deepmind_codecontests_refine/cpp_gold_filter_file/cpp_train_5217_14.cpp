#include <bits/stdc++.h>
int main() {
  int n, x, a;
  scanf("%d", &n);
  x = n - 10;
  if (x == 10)
    printf("15\n");
  else if ((x < 10 && x > 0) || x == 11 || x == 21 || x == 31 || x == 41 ||
           x == 51)
    printf("4\n");
  else if (x > 10 || x == 0 || n < 10)
    printf("0\n");
}
