#include <bits/stdc++.h>
int main() {
  long int a, k;
  scanf("%ld", &a);
  k = a / 2;
  if (a == 1) {
    printf("-1");
  } else if (a % 2 == 0) {
    printf("%ld", k);
  } else {
    printf("-%ld", k + 1);
  }
  return 0;
}
