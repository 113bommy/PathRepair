#include <bits/stdc++.h>
int main() {
  int n, L, a, i, count = 0, x;
  scanf("%d%d%d", &n, &L, &a);
  int t[n], l[n];
  for (i = 0; i < n; i++) {
    scanf("%d %d", &t[i], &l[i]);
  }
  if (n == 0) {
    count = L / a;
  } else {
    count = t[0] / a;
    for (i = 0; i < n - 2; i++) {
      x = (t[i + 1] - (t[i] + l[i])) / a;
      count += x;
    }
    x = (L - (t[n - 1] + l[n - 1])) / a;
    count += x;
  }
  printf("%d", count);
  return 0;
}
