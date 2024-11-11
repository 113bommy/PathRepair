#include <bits/stdc++.h>
int main() {
  char a[100];
  char b[100];
  int i, j, l, c = 0;
  scanf("%s", a);
  scanf("%s", b);
  l = strlen(a);
  for (i = 0, j = l - 1; i < l; i++, j--) {
    if (b[i] != a[j]) c = 1;
  }
  if (c)
    printf("NO");
  else
    printf("YES");
}
