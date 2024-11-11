#include <bits/stdc++.h>
int main() {
  int a;
  scanf("%d", &a);
  long long ans;
  if (a < 13)
    printf("%I64d\n", 1LL << a);
  else
    printf("%I64d\n", 8096LL << (a - 13));
  return 0;
}
