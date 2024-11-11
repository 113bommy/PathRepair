#include <bits/stdc++.h>
int main() {
  int i, len, count = 0;
  char a[51];
  scanf(" %s", a);
  len = strlen(a);
  for (i = 0; i < len; i++) {
    if (a[i] == '2' || a[i] == '4' || a[i] == '6' || a[i] == '8' || a[i] == '0')
      count++;
    else if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' ||
             a[i] == 'u')
      count++;
  }
  printf("%d", count);
}
