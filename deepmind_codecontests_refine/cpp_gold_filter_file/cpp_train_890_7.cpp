#include <bits/stdc++.h>
int main() {
  int n, m, z, i;
  scanf("%d %d %d", &n, &m, &z);
  int count = 0;
  for (i = 1; i <= z; i++) {
    if (i % n == 0 && i % m == 0) count++;
  }
  printf("%d", count);
  return 0;
}
