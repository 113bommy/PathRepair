#include <bits/stdc++.h>
using namespace std;
int mapn[505][505];
char s[505];
int main() {
  int n, m, i, j;
  memset(mapn, 0, sizeof(mapn));
  scanf("%d %d", &n, &m);
  if (n == 1 && m == 0) {
    printf("Yes\na\n");
    return 0;
  }
  for (i = 0; i <= n; i++) s[i] = '0';
  int st, en;
  for (i = 1; i <= m; i++) {
    scanf("%d %d", &st, &en);
    mapn[st][en] = mapn[en][st] = 1;
  }
  for (i = 1; i <= n; i++)
    for (j = i + 1; j <= n; j++)
      if (mapn[i][j] == 0) {
        if (s[i] == '0' && s[j] == '0')
          s[i] = 'a', s[j] = 'c';
        else if (s[i] == '0') {
          if (s[j] == 'a')
            s[i] = 'c';
          else
            s[i] = 'a';
        } else if (s[j] == '0') {
          if (s[i] == 'a')
            s[j] = 'c';
          else
            s[j] = 'a';
        } else if (s[i] == s[j]) {
          printf("No\n");
          return 0;
        }
      }
  for (i = 1; i <= n; i++)
    for (j = i + 1; j <= n; j++)
      if (mapn[i][j] == 1) {
        if (s[i] == '0' && s[j] == '0')
          s[i] = s[j] = 'b';
        else if (s[i] == '0')
          s[i] = 'b';
        else if (s[j] == '0')
          s[j] = 'b';
        else if (abs(s[i] - s[j]) == 2) {
          printf("No\n");
          return 0;
        }
      }
  printf("Yes\n%s\n", s + 1);
  return 0;
}
