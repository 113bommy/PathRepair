#include <bits/stdc++.h>
char s[100][100];
int main() {
  int n, m, ans = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int f = 0, g = 0;
      for (int k = 1; k <= m; k++)
        if (s[i][k] != '.' || s[j][k] != '.') {
          if (s[i][k] == s[j][k])
            f = 1;
          else
            g = 1;
        }
      if (f == g) {
        printf("No");
        return 0;
      }
    }
  }
  printf("Yes");
}
