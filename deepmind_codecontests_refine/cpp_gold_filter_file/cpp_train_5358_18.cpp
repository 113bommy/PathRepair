#include <bits/stdc++.h>
int start, a, b, i;
int main() {
  scanf("%d %d", &a, &b);
  start = b + 1;
  for (i = start; i <= a + b + 1; i++) printf("%d ", i);
  for (i = start - 1; i >= 1; i--) printf("%d ", i);
  return 0;
}
