#include <bits/stdc++.h>
int main() {
  char a[100], b[100];
  int i;
  gets(a);
  gets(b);
  for (i = 0; a[i]; i++) {
    if (a[i] == b[i])
      a[i] = '0';
    else
      a[i] = '1';
  }
  puts(a);
  return 0;
}
