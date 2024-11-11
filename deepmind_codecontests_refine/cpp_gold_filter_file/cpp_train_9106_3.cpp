#include <bits/stdc++.h>
char s[1010];
int main() {
  while (~scanf("%s", s)) {
    int m;
    scanf("%d", &m);
    int len = strlen(s);
    int n = len / m;
    int ans = 0;
    if (len % m != 0) {
      printf("NO\n");
      continue;
    }
    for (int i = 0; i < len; i += n) {
      for (int j = 0; j <= n / 2; j++) {
        if (s[i + j] != s[i + n - j - 1]) {
          ans = 1;
          break;
        }
      }
    }
    if (ans == 1)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
