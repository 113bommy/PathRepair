#include <bits/stdc++.h>
char s[1000000], t[1000000];
int ans;
int main() {
  int i, j, x = 0, y = 0;
  scanf("%s%s", s + 1, t + 1);
  for (i = 1; t[i]; i++) y ^= t[i] - '0';
  for (i = 1; t[i]; i++) x ^= s[i] - '0';
  ans += x ^ y ^ 1;
  for (j = 1; s[i]; i++, j++) {
    x ^= s[i] - '0';
    x ^= s[j] - '0';
    ans += x ^ y ^ 1;
  }
  printf("%d", ans);
  return 0;
}
