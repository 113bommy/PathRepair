#include <bits/stdc++.h>
using namespace std;
int n, k, i, j, l, p, tot;
char s[2111][511];
int len[2111], st[2111], h[2111];
int f[8111][1111];
int M[2111][2111];
bool cmp(int x, int y) {
  for (int i = 1; i <= len[x] && i <= len[y]; i++)
    if (s[x][i] != s[y][i]) return s[x][i] < s[y][i];
  return len[x] < len[y];
}
int dp(int x, int y) {
  if (M[x][y]) return M[x][y];
  int r = M[x][y] = ++tot;
  memset(f[r], 200, sizeof(f[r]));
  f[r][0] = 0;
  if (x == y) f[r][1] = 0;
  if (x != y) {
    int p = x;
    for (int i = x; i < y; i++)
      if (h[i] < h[p]) p = i;
    int L = dp(x, p), R = dp(p + 1, y);
    for (int i = 0; i <= p - x + 1; i++)
      for (int j = 0; j <= y - p; j++)
        f[r][i + j] = max(f[r][i + j], f[L][i] + f[R][j] + h[p] * i * j);
  }
  return r;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++)
    scanf("%s", s[i] + 1), len[i] = strlen(s[i] + 1), st[i] = i;
  sort(st + 1, st + 1 + n, cmp);
  for (int i = 1; i < n; i++) {
    int x = st[i], y = st[i + 1];
    for (p = 1; p <= len[x] && p <= len[y] && s[x][p] == s[y][p]; p++)
      ;
    p--;
    h[i] = p;
  }
  int r = dp(1, n);
  printf("%d\n", f[r][k]);
  return 0;
}
