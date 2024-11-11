#include <bits/stdc++.h>
int main() {
  char a[200], b[200], e[200];
  int c[26], d[26], i;
  for (i = 0; i < 26; i++) {
    c[i] = 0;
    d[i] = 0;
  }
  scanf("%s", a);
  for (i = 0; i < strlen(a); i++) {
    c[a[i] - 65]++;
  }
  scanf("%s", b);
  for (i = 0; i < strlen(b); i++) {
    c[b[i] - 65]++;
  }
  scanf("%s", e);
  for (i = 0; i < strlen(e); i++) {
    d[e[i] - 65]++;
  }
  for (i = 0; i < 26; i++) {
    if (c[i] != d[i]) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
}
