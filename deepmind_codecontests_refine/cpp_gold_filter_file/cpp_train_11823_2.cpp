#include <bits/stdc++.h>
int main() {
  int a[3];
  scanf("%d%d%d", &a[0], &a[1], &a[2]);
  if (a[0] < a[1] && a[1] < a[2]) {
    printf("%d", a[2] - a[0]);
  } else if (a[0] < a[2] && a[1] > a[2]) {
    printf("%d", a[1] - a[0]);
  } else if (a[0] > a[2] && a[2] > a[1]) {
    printf("%d", a[0] - a[1]);
  } else if (a[0] > a[1] && a[1] > a[2]) {
    printf("%d", a[0] - a[2]);
  } else if (a[1] > a[0] && a[0] > a[2]) {
    printf("%d", a[1] - a[2]);
  } else {
    printf("%d", a[2] - a[1]);
  }
  return 0;
}
