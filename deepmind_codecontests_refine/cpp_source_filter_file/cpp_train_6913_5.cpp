#include <bits/stdc++.h>
int main(void) {
  int k, d, i;
  scanf("%d %d", &k, &d);
  if (d == 0 && k != 1) {
    printf("No soulution");
    return 0;
  }
  printf("%d", d);
  for (i = 0; i < k - 1; i++) printf("0");
  return 0;
}
