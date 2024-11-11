#include <bits/stdc++.h>
int main() {
  int a[5], i, s = 0, k;
  for (i = 0; i < 5; i++) {
    scanf("%d", &a[i]);
    s = s + a[i];
  }
  k = s / 5;
  if (s % 5 == 0 && k != 0)
    printf("%d", k);
  else
    printf("-1");
}
