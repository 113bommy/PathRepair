#include <bits/stdc++.h>
int main() {
  int n, a, sum = 0, max = 0, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    sum += a;
    if (a > max) max = a;
  }
  printf("%d", (max * n) - sum);
}
