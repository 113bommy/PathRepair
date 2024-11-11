#include <bits/stdc++.h>
int main() {
  int i, n, sum = 0, count = 0, flag = 0;
  scanf("%d", &n);
  int ar[n + 1];
  for (i = 0; i < n; i++) {
    scanf("%d", &ar[i]);
    sum = sum + ar[i];
  }
  for (i = 0; i < n; i++) {
    if ((sum - ar[i] % 2) == 0) count++;
  }
  printf("%d", count);
}
