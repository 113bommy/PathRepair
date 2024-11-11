#include <bits/stdc++.h>
int main() {
  long long int a, k;
  scanf("%lld", &a);
  k = a / 2;
  if (a == 1) {
    printf("-1");
  } else if (a % 2 == 0) {
    printf("%lld", k);
  } else {
    printf("-%lld", k + 1);
  }
  return 0;
}
