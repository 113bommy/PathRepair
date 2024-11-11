#include <bits/stdc++.h>
int a[1000];
int main() {
  int n;
  int total = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    total += a[i];
    a[i] = a[i] == 0 ? 1 : -1;
  }
  int sum = 0;
  int max = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    if (sum > max) {
      max = sum;
    }
    if (sum < 0) {
      sum = 0;
    }
  }
  printf("%d\n", total + sum);
}
