#include <bits/stdc++.h>
char a[10000];
char b[10000];
char c[10000];
int main() {
  scanf("%s%s", a, b);
  int i, j, k, l, m, n, flag = 0;
  l = strlen(a);
  for (i = 0; i < l; i++) {
    if (b[i] < a[i])
      c[i] = b[i];
    else if (b[i] == a[i])
      c[i] = 'z';
    else if (b[i] > a[i]) {
      flag = 1;
    }
  }
  if (flag == 1)
    printf("-1\n");
  else
    printf("%s\n", c);
  return 0;
}
