#include <bits/stdc++.h>
int a[10];
int main() {
  int n, i, ans;
  for (i = 1; i <= 8; i++) {
    a[i] = (pow(2, i) - 1) * (pow(2, i - 1));
  }
  scanf("%d", &n);
  for (i = 8; i >= 1; i--) {
    if (n % a[i] == 0) {
      ans = a[i];
      break;
    }
  }
  printf("%d\n", ans);
}
