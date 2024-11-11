#include <bits/stdc++.h>
char s[30002][22];
int main() {
  int n, i, j, c, ans = 0, d;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%s", &s[i]);
  }
  for (i = 0; i < strlen(s[0]); i++) {
    c = 0;
    for (j = 2; j <= n; j++) {
      if (s[j][i] == s[j - 1][i]) {
        c++;
      }
    }
    if (c != n - 1) {
      break;
    }
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}
