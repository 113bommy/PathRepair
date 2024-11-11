#include <bits/stdc++.h>
int a[1000], n, d, x;
int s = 0;
int main() {
  scanf("%d%d", &n, &d);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  printf("\n");
  for (int i = 0; i < n; i++)
    if (a[i - 1] >= a[i]) {
      x = ((a[i - 1] - a[i]) / d) + 1;
      s += x;
      a[i] += x * d;
    }
  printf("%d", s);
  return 0;
}
