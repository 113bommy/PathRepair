#include <bits/stdc++.h>
int main() {
  int i, p = 0;
  char s[50], t[50];
  gets(s);
  gets(t);
  for (i = 0; i < sizeof(t); i++)
    if (t[i] == s[p]) p++;
  printf("%d", p + 1);
  return 0;
}
