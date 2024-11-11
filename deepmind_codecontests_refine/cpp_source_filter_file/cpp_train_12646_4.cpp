#include <bits/stdc++.h>
int main() {
  int i, j, n, t = 1;
  char s[105], s1[35];
  scanf("%d", &n);
  for (i = 0; i <= n; i++) scanf("%c", &s[i]);
  if (n < 26)
    printf("NO");
  else {
    for (i = 0; i < n; i++) {
      if (s[i] >= 'A' && s[i] <= 'Z') {
        s[i] = s[i] + 32;
      }
    }
    s1[1] = s[1];
    for (i = 2; i <= n; i++) {
      for (j = 1; j <= t; j++) {
        if (s[i] == s1[j])
          break;
        else if (j == t) {
          t++;
          s1[t] = s[i];
          break;
        } else
          continue;
      }
    }
    if (t >= 26)
      printf("YES");
    else
      printf("NO");
  }
  return 0;
}
