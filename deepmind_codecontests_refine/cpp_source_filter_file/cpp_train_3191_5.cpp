#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int a[109], b[109];
  for (int i = 0; i < n; i++) {
    scanf("%d:%d", &a[i], &b[i]);
  }
  for (int i = 0; i < n; i++) {
    a[i] = a[i] * 60 + b[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (a[j] > a[j + 1]) {
        int c = a[j];
        a[j] = a[j + 1];
        a[j + 1] = c;
      }
    }
  }
  int mx = 0;
  for (int i = 1; i < n; i++) {
    int t = a[i] - a[i - 1] - 1;
    if (t > mx) {
      mx = t;
    }
  }
  int t = a[0] - 1 + 1439 - a[n - 1] + 1;
  if (t > mx) {
    mx = t;
  }
  if (mx / 60 < 10 && mx % 60 < 10) {
    printf("0%d:0%d", mx / 60, mx % 60);
  } else if (mx / 60 < 10) {
    printf("0%d:%d", mx / 60, mx % 60);
  } else if (mx % 60 < 10) {
    printf("%d:0%d", mx % 60);
  } else {
    printf("%d:%d", mx / 60, mx % 60);
  }
  return 0;
}
