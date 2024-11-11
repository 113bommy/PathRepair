#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
const int maxm = 510;
char s[maxn], p[maxm];
int n, m;
int d[maxn][maxn];
int f[maxn];
int main() {
  scanf("%s%s", s, p);
  int n = strlen(s), m = strlen(p);
  for (int i = 0; i < n; i++) {
    int st = i, j;
    for (j = 0; j < m; j++) {
      while (st < n && s[st] != p[j]) ++st;
      if (st == n)
        break;
      else
        ++st;
    }
    if (j == m)
      f[i] = st - i;
    else
      f[i] = -1;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++) {
      d[i + 1][j] = max(d[i + 1][j], d[i][j]);
      d[i + 1][j + 1] = max(d[i + 1][j + 1], d[i][j]);
      if (f[i] >= 0)
        d[i + f[i]][j + f[i] - m] = max(d[i + f[i]][j + f[i] - m], d[i][j] + 1);
    }
  for (int i = 0; i <= n; i++) printf("%d ", d[n][i]);
  printf("\n");
  return 0;
}
