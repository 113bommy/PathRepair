#include <bits/stdc++.h>
int main() {
  char s[100], a[100];
  gets(s);
  gets(a);
  int i, b;
  b = strlen(s);
  for (i = 0; i < b; i++) {
    if (s[i] == a[i])
      printf("0");
    else
      printf("1");
  }
}
