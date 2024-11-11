#include <bits/stdc++.h>
int main() {
  int n;
  int a[200005];
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  if (n % 2 == 0) {
    for (int i = 1; i <= n / 2; i += 2) {
      int flag;
      flag = a[i];
      a[i] = a[n - i + 1];
      a[n - i + 1] = flag;
    }
  } else {
    for (int i = 1; i < (n + 1) / 2; i += 2) {
      int flag;
      flag = a[i];
      a[i] = a[n - i + 1];
      a[n - i + 1] = flag;
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", a[i]);
  }
  return 0;
}
