#include <bits/stdc++.h>
int main() {
  int n, i, h = 0;
  scanf("%d", &n);
  int a[n];
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 0; i < n; i++) {
    if (a[i] = 1) h++;
  }
  if (h > 0)
    printf("HARD");
  else
    printf("EASY");
  return 0;
}
