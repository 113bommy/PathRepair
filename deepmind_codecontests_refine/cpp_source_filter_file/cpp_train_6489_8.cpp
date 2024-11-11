#include <bits/stdc++.h>
const int MAX = 1000 * 1000;
int main() {
  char s[50];
  scanf("%s", s);
  int l = strlen(s);
  int maxres = -1;
  for (int a = 1; a <= l && a <= 7; a++)
    for (int b = 1; a + b < l && b <= 7; b++) {
      if (l - a - b >= 7) continue;
      char s1[30], s2[30], s3[30];
      strncpy(s1, s, a);
      s1[a] = 0;
      strncpy(s2, s + a, b);
      s2[b] = 0;
      strcpy(s3, s + a + b);
      if (s1[0] == '0' && s1[1] != 0) continue;
      if (s2[0] == '0' && s2[1] != 0) continue;
      if (s3[0] == '0' && s3[1] != 0) continue;
      if (atoi(s1) > MAX || atoi(s2) > MAX || atoi(s3) > MAX) continue;
      int res = atoi(s1) + atoi(s2) + atoi(s3);
      if (res > maxres) maxres = res;
    }
  printf("%d\n", maxres);
  return 0;
}
