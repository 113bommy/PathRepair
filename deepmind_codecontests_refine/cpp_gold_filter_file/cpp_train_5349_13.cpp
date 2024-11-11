#include <bits/stdc++.h>
int main() {
  char s[1000];
  gets(s);
  if (s[0] >= 97 && s[0] <= 122) s[0] = s[0] - 32;
  puts(s);
  return 0;
}
