#include <bits/stdc++.h>
int main() {
  static char s[1024];
  static int kk[2];
  int n, i;
  scanf("%s", s);
  n = strlen(s);
  for (i = 0; i < n; i++)
    if (s[i] == '0')
      printf(kk[0]++ % 2 == 0 ? "1 1\n" : "1 3\n");
    else
      printf(kk[1]++ % 2 == 0 ? "3 1\n" : "1 1\n");
  return 0;
}
