#include <bits/stdc++.h>
int main() {
  int max = 0, pos, flag = 0, i, n, a[200005];
  scanf("%d", &n);
  for (i = 0; i < n; i = i + 1) {
    scanf("%d", &a[i]);
    if (a[i] > max) {
      max = a[i];
      pos = i;
    }
  }
  for (i = 1; i <= pos; i = i + 1) {
    if (a[i] < a[i - 1]) {
      flag = 1;
      break;
    }
  }
  if (flag != 1) {
    for (i = pos + 1; i < n; i = i + 1) {
      if (a[i] > a[i - 1]) {
        flag = 1;
        break;
      }
    }
  }
  if (flag == 0) {
    printf("YES");
  } else {
    printf("NO");
  }
}
