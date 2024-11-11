#include <bits/stdc++.h>
int main() {
  int i, l1, l2;
  char a[1000], b[1000];
  scanf("%s", a);
  scanf("%s", b);
  l1 = strlen(a);
  l2 = strlen(b);
  for (i = 0; i < l1; i++) {
    if (a[i] == '0' && b[i] == '0') {
      a[i] = '0';
    } else if (a[i] == '0' && b[i] == '1') {
      a[i] = '1';
    } else if (a[i] == '1' && b[i] == '0') {
      a[i] = '1';
    } else if (a[i] == '0' && b[i] == '1') {
      a[i] = '0';
    }
  }
  printf("%s\n", a);
}
