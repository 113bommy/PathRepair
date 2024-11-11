#include <bits/stdc++.h>
using namespace std;
char str[300010];
int n, ans = 0, s[300010][30];
long long f[300010][30], t[30];
int main() {
  scanf("%s", str);
  n = strlen(str);
  for (int i = 0; i < n; i++) {
    f[i][1] = 1;
    s[i][1] = 1 << (str[i] - 'a');
  }
  for (int i = 0; i < n - 1; i++)
    for (int j = 1; j <= 26; j++)
      if (f[i][j])
        if (((1 << (str[i + 1] - 'a')) | s[i][j]) != s[i][j]) {
          s[i + 1][j + 1] = (1 << (str[i + 1] - 'a')) | s[i][j];
          f[i + 1][j + 1] += f[i][j];
        } else {
          f[i + 1][j] += f[i][j];
          s[i + 1][j] = s[i][j];
        }
  for (int i = 0; i < n; i++)
    for (int j = 1; j <= 26; j++)
      t[j] += f[i][j], ans = max(ans, j * (f[i][j] > 0));
  printf("%d\n", ans);
  for (int i = 1; i <= ans; i++) printf("%d\n", t[i]);
  return 0;
}
