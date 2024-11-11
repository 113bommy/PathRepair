#include <bits/stdc++.h>
int main() {
  int x[101], n, a, b, i, sum = 0;
  scanf("%d", &n);
  x[n] = 0;
  for (i = 1; i < n; i++) {
    scanf("%d", &x[i]);
  }
  scanf("%d %d", &a, &b);
  for (i = a; i < b; i++) {
    sum = sum + x[i];
  }
  printf("%d", sum);
  return 0;
}
