#include <bits/stdc++.h>
int tem[20];
int main() {
  long long i, res;
  long long n;
  scanf("%I64d", &n);
  while (n % 3 == 0) n /= 3;
  n /= 3;
  n++;
  printf("%I64d\n", n);
  return 0;
}
