#include <bits/stdc++.h>
int main() {
  int i;
  char a[200], b[200];
  scanf("%s%s", a, b);
  for (i = 0; i < strlen(a); i++) {
    printf("%d", a[i] ^ b[i]);
  }
  return 0;
}
