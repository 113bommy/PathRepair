#include <bits/stdc++.h>
char s[8];
int main() {
  scanf("%s", &s);
  if ((int)s[7] % 2 == 0)
    printf("%d", 0);
  else
    printf("%d", 1);
  return 0;
}
