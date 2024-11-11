#include <bits/stdc++.h>
int main() {
  char a[1000];
  scanf("%s", a);
  if (a[0] > 97 && a[0] < 122) a[0] -= 32;
  printf("%s", a);
  return 0;
}
