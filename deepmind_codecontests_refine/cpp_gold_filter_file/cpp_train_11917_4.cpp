#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int i = 1, j = 1;
  int count = 0;
  while (n > 0) {
    n -= i;
    i = i + (j + 1);
    j++;
    if (n >= 0) count++;
  }
  printf("%d\n", count);
  return 0;
}
