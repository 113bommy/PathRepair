#include <bits/stdc++.h>
int main() {
  int a[3000], b[3000], i, j, k, c[3000];
  int n;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n - i; j++) {
      if (a[j] < a[j + 1]) {
        a[j] = a[j] ^ a[j + 1];
        a[j + 1] = a[j] ^ a[j + 1];
        a[j] = a[j] ^ a[j + 1];
      }
    }
  }
  c[0] = 1;
  for (i = 1; i < n; i++) {
    if (a[i] == a[i - 1]) {
      c[i] = c[i - 1];
    } else {
      c[i] = i + 1;
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (b[i] == a[j]) {
        printf("%d ", c[j]);
        break;
      }
    }
  }
  return 0;
}
