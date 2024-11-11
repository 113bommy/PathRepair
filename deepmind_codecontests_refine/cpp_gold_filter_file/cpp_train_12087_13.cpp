#include <bits/stdc++.h>
int main(void) {
  int n, o, f = 0;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &o);
    if (o == 1) f = 1;
  }
  if (f == 1)
    printf("HARD");
  else
    printf("EASY");
  return 0;
}
