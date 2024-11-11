#include <bits/stdc++.h>
int abs(int x) {
  if (x < 0) return -x;
  return x;
}
int main() {
  int q, n, flag = 0;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    flag = 0;
    scanf("%d", &n);
    int a[n];
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[j]);
    }
    for (int j = 1; j < n; j++) {
      if (abs(a[j] - a[j - 1]) == 1 || abs(a[j] - a[j - 1]) == n - 1) {
        flag = 0;
      } else {
        flag = 1;
        break;
      }
    }
  }
  if (flag == 0) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
}
