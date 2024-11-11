#include <bits/stdc++.h>
int main() {
  int n, i = 0, t, s = 0, g;
  scanf("%d", &n);
  g = n;
  int x = 100 * n + 1;
  int a[x], c[101];
  while (n > 0) {
    scanf("%d", &t);
    s = s + t;
    for (i; i < s; i++) scanf("%d", &a[i]);
    n--;
  }
  for (i = 0; i < 101; i++) c[i] = 0;
  for (i = 0; i < s; i++) c[a[i]]++;
  for (i = 0; i < 101; i++)
    if (c[i] == g) printf("%d ", i);
  printf("\n");
  return 0;
}
