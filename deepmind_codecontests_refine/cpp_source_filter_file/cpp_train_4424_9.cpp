#include <bits/stdc++.h>
char d[105];
char s[15] = "CODEFORCES";
int main() {
  int L;
  scanf("%s", d);
  for (L = 0; d[L] != 0; L++)
    ;
  if (L < 10) {
    printf("NO");
    return 0;
  }
  int cut_L = L - 10, i;
  for (i = 0; i < 10; i++) {
    int st = 0, j;
    for (j = 0; j < i; j++) {
      if (d[j] != s[st]) break;
      st++;
    }
    if (j < i) continue;
    for (j = L - 10 + i; j < L; j++) {
      if (d[j] != s[st]) break;
      st++;
    }
    if (j < L)
      continue;
    else
      break;
  }
  if (i == 10)
    printf("NO");
  else
    printf("YES");
  return 0;
}
