#include <bits/stdc++.h>
using namespace std;
int n, m, nxt[(45)], to[(45)][2];
long long f[(45)][(45)][2], ans;
char str[(45)];
int main(int argc, char const* argv[]) {
  scanf("%d%s", &n, str + 1), m = strlen(str + 1), str[m + 1] = 3;
  for (int i = 1; i <= m; i += 1) str[i] -= '0';
  for (int i = 2, j = 0; i <= m; i += 1) {
    if (j && str[i] != str[j + 1]) j = nxt[j];
    if (str[i] == str[j + 1]) j++;
    nxt[i] = j;
  }
  for (int i = 0; i <= m; i += 1)
    for (int c = 0; c <= 1; c += 1) {
      int j = i;
      while (j && str[j + 1] != c) j = nxt[j];
      if (str[j + 1] == c) j++;
      to[i][c] = j;
    }
  for (int x = 0; x <= m; x += 1) {
    memset(f, 0, sizeof(f)), f[0][x][x == m] = 1;
    for (int i = 0; i < n; i += 1)
      for (int j = 0; j <= m; j += 1)
        for (int c = 0; c <= 1; c += 1)
          if (to[j][c] == m)
            f[i + 1][m][1] += f[i][j][0] + f[i][j][1];
          else {
            f[i + 1][to[j][c]][0] += f[i][j][0];
            f[i + 1][to[j][c]][1] += f[i][j][1];
          }
    ans += f[n][x][1];
  }
  printf("%lld\n", ans);
  return 0;
}
