#include <bits/stdc++.h>
int main() {
  int n, i, sum = 1;
  scanf("%d", &n);
  for (i = 0; i < n - 1; i++) {
    sum = sum + (i + 1);
    if (sum > n) sum = sum - n;
    printf("%d", sum);
  }
  return 0;
}
