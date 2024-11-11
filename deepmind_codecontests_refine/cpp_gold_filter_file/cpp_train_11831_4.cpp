#include <bits/stdc++.h>
int main() {
  int i, len, count = 0;
  char a[51];
  scanf(" %s", a);
  len = strlen(a);
  for (i = 0; i < len; i++) {
    if (a[i] == '1' || a[i] == '3' || a[i] == '5' || a[i] == '7' || a[i] == '9')
      count++;
    else if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' ||
             a[i] == 'u')
      count++;
  }
  printf("%d", count);
}
