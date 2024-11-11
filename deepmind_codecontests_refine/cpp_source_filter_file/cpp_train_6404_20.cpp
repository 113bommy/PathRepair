#include <bits/stdc++.h>
int main() {
  char a[20], b[20], ans[20];
  gets(a);
  gets(b);
  int i, len = strlen(a);
  for (i = 0; i < len; i++) {
    if (a[i] != b[i]) {
      ans[i] = '1';
    } else
      ans[i] = '0';
  }
  ans[i] = '\0';
  printf("%s", ans);
}
