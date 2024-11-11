#include <bits/stdc++.h>
int main() {
  int n, i;
  scanf("%i", &n);
  printf("ROYGBIV");
  for (i = 0; i < n - 7; i++) {
    if (i == 4) {
      n = n - 4;
      i = i - 4;
    }
    if (i == 0)
      printf("R");
    else if (i == 1)
      printf("O");
    else if (i == 2)
      printf("Y");
    else if (i == 3)
      printf("G");
  }
  return 0;
}
