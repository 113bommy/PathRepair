#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int a[200010];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  int sc = 0;
  a[n] = 2;
  for (int i = 1; i < n + 1; i++) {
    if (a[i] != a[i - 1]) {
      sc = i;
      break;
    }
  }
  int cur = a[0];
  if (n % sc != 0) {
    printf("NO");
    return 0;
  }
  for (int i = 0; i < n; i += sc) {
    for (int j = i; j < i + sc - 1; j++) {
      if (a[j] != cur) {
        printf("NO");
        return 0;
      }
    }
    cur++;
    cur %= 2;
  }
  printf("YES");
  return 0;
}
