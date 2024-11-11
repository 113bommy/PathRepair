#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  long long a = 1, b = 12;
  for (int i = 0; i < n - 1; i++) {
    a += b;
    b *= 2;
  }
  printf("%I64d\n", a);
  return 0;
}
