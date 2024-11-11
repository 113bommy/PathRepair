#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[1005][1005], a[1005][1005];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> s[i][j];
      a[i][j] = '.';
    }
  for (int i = 1; i <= n - 2; i++)
    for (int j = 1; j <= m - 2; j++) {
      if (s[i][j] == '#' && s[i][j + 1] == '#' && s[i][j + 2] == '#' &&
          s[i + 1][j] == '#' && s[i + 1][j + 2] == '#' && s[i + 2][j] == '#' &&
          s[i + 2][j + 1] == '#' && s[i + 2][j + 2] == '#') {
        a[i][j] = a[i][j + 1] = a[i][j + 2] = a[i + 1][j] = a[i + 1][j + 2] =
            a[i + 2][j] = a[i + 2][j + 1] = a[i + 2][j + 2] = '#';
      }
    }
  bool flag = true;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (a[i][j] != s[i][j]) flag = false;
  if (flag)
    printf("Yes");
  else
    printf("NO");
  return 0;
}
