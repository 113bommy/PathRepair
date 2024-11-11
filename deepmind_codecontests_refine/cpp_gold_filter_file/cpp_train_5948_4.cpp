#include <bits/stdc++.h>
int main() {
  int n, i, j, k = 0, z = 0, c = 0;
  scanf("%d\n", &n);
  char a[n];
  gets(a);
  while (c <= n) {
    z++;
    c = c + z;
  }
  char s[z];
  c = z;
  for (i = n - 1, j = z - 1; i >= 0; i = i - z, j--) {
    s[j] = a[i];
    z = z - 1;
  }
  for (i = 1; i < c; i++) {
    printf("%c", s[i]);
  }
  return 0;
}
