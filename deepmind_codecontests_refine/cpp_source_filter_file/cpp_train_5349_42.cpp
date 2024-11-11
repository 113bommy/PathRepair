#include <bits/stdc++.h>
int main() {
  char str[1001];
  scanf("%s", str);
  if (str[0] == 'a' && str[0] == 'z') {
    str[0] = str[0] - 32;
  }
  printf("%s", str);
  return 0;
}
