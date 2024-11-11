#include <bits/stdc++.h>
int main() {
  int m, n, i;
  scanf("%d", &n);
  scanf("%d", &m);
  if (n > 63)
    printf("%d", m);
  else {
    long long z = 1;
    for (i = 0; i < n; i++) z *= 2;
    printf("%ld", m % z);
  }
  return 0;
}
