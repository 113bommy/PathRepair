#include <bits/stdc++.h>
int main() {
  long long p;
  scanf("%I64d", &p);
  while (p % 3 == 0) p /= 3;
  printf("I64d", (p / 3) + 1);
  return 0;
}
