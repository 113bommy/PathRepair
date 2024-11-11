#include <bits/stdc++.h>
int main() {
  char a[101], b[101];
  scanf("%s%s", a, b);
  int l = strlen(a), i;
  for (i = 0; i < l; i++) printf((a[i] != b[i]) ? "1" : "0");
  return 0;
}
