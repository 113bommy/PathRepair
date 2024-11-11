#include <bits/stdc++.h>
int main() {
  int i, r;
  char s[10];
  scanf("%s", s);
  for (i = r = 1; i < 7; i++) {
    if (s[i] == '1') {
      r += 10;
    } else {
      r += s[i] - '0';
    }
  }
  printf("%d", r);
  return 0;
}
