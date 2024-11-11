#include <bits/stdc++.h>
char s[1000];
int main() {
  scanf("%s", s);
  int a = 0;
  for (int i = 1; i < 7; i++) {
    if (s[i] == '1' && s[i + 1] == '0')
      a += 10;
    else
      a += s[i] - '0';
  }
  printf("%d\n", a);
  return 0;
}
