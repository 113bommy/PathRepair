#include <bits/stdc++.h>
int main() {
  int a[101];
  int n, i;
  scanf("%d", &n);
  int b[n];
  for (i = 0; i < n; i++) a[i] = 0;
  int mx = 0;
  for (i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    int x = b[i];
    a[x]++;
    if (a[x] > mx) mx = a[x];
  }
  printf("%d\n", mx);
  return 0;
}
