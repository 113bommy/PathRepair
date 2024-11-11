#include <bits/stdc++.h>
int main() {
  int i, len, len2, c = 1;
  char a[100], b[100];
  scanf("%s", a);
  scanf("%s", b);
  len = strlen(a);
  len2 = strlen(b);
  if (len != len2)
    c = 0;
  else
    for (i = 0; i < len; i++) {
      if (b[i] != a[len - 1 - i]) {
        c = 0;
        break;
      }
    }
  if (c == 0) printf("NO");
  if (c == 1) printf("YES");
  return 0;
}
