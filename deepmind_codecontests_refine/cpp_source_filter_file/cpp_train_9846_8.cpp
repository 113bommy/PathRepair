#include <bits/stdc++.h>
int main() {
  int n, a, sum = 0, max, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    sum += a;
    if (a > max) max = a;
  }
  printf("%d", (a * n) - sum);
}
