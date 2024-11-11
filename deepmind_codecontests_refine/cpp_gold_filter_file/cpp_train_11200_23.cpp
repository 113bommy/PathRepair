#include <bits/stdc++.h>
int main() {
  int n, i, s = 0;
  scanf("%d", &n);
  char a[25];
  for (i = 0; i < n; i++) {
    scanf("%s", a);
    if (a[0] == 'T')
      s = s + 4;
    else if (a[0] == 'C')
      s = s + 6;
    else if (a[0] == 'O')
      s = s + 8;
    else if (a[0] == 'D')
      s = s + 12;
    else if (a[0] == 'I')
      s = s + 20;
  }
  printf("%d", s);
  return 0;
}
