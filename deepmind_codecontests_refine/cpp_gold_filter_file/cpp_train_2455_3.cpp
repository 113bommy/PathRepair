#include <bits/stdc++.h>
int main() {
  int a[7], b, c, i, d;
  scanf("%d", &b);
  for (i = 0; i < b; i++) {
    scanf("%d", &a[i]);
  }
  for (d = 1; d < b; d++) {
    for (i = 0; i < b - 1; i++) {
      if (a[i] > a[i + 1]) {
        c = a[i];
        a[i] = a[i + 1];
        a[i + 1] = c;
      }
    }
  }
  printf("%d", a[b / 2]);
}
