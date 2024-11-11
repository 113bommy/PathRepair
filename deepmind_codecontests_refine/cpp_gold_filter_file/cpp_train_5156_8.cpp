#include <bits/stdc++.h>
char s[11];
int v;
long long x;
int main() {
  scanf("%s", s);
  v = (s[0] - '0') * 10000 + (s[2] - '0') * 1000 + (s[4] - '0') * 100 +
      (s[3] - '0') * 10 + (s[1] - '0');
  x = 1LL * v;
  for (int i = 0; i < 4; i++) x = x * v % 100000;
  printf("%05I64d\n", x);
  return 0;
}
