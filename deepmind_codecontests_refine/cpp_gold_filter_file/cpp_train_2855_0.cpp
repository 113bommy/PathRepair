#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int x[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }
  int flag = 0;
  int ans = 1;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < n; j++) {
      if (x[j] % (i + 1) == 0) {
        flag = 0;
      } else {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      ans = i + 1;
    }
  }
  printf("%d\n", ans * n);
  return 0;
}
