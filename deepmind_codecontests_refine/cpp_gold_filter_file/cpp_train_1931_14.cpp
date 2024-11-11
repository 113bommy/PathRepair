#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n, m, k, d[maxn][maxn][11][2], len[maxn][maxn];
char s[maxn], t[maxn];
int main() {
  memset(d, 0, sizeof(d));
  scanf("%d%d%d", &n, &m, &k);
  scanf("%s%s", s + 1, t + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int l = 1; l <= k; l++) {
        d[i][j][l][0] = max(d[i][j - 1][l][0], d[i - 1][j][l][0]);
        if (s[i] == t[j]) {
          d[i][j][l][1] =
              max(d[i - 1][j - 1][l - 1][0], d[i - 1][j - 1][l][1]) + 1;
          d[i][j][l][0] = max(d[i][j][l][0], d[i][j][l][1]);
        }
      }
    }
  }
  printf("%d\n", d[n][m][k][0]);
}
