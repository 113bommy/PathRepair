#include <bits/stdc++.h>
int main() {
  char S[100000], s[30];
  int i, r = 0;
  scanf("%s", S);
  scanf("%s", s);
  int len = strlen(s);
  int Len = strlen(S);
  for (i = 0; i < Len; i++) {
    if (!strncmp(S + i, s, len)) {
      i += len - 1;
      r++;
    }
  }
  printf("%d\n", r);
}
