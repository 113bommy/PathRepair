#include <bits/stdc++.h>
int main() {
  int n, i;
  float s = 0;
  scanf("%d", &n);
  int a[10001];
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 0; i < n; i++) {
    s = s + a[i];
  }
  s = s / n;
  printf("%.12f\n", s);
  return 0;
}
