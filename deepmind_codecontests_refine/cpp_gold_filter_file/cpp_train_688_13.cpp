#include <bits/stdc++.h>
int i, n, f[1000];
char a[1100];
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    a[i] = 'o';
  }
  f[1] = 1;
  f[2] = 1;
  for (i = 3; i <= 16; i++) f[i] = f[i - 1] + f[i - 2];
  i = 1;
  while (f[i] <= n) {
    a[f[i]] = 'O';
    i++;
  }
  for (i = 1; i <= n; i++) printf("%c", a[i]);
  return 0;
}
