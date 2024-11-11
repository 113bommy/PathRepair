#include <bits/stdc++.h>
using namespace std;
int A[22][22];
int n, m, k;
int a[22][22];
int wei[50];
int wt = 0;
int Use[22][22];
int YL[22][22];
int LL2g[1000000];
long long ans = 0;
void dfs(int x, int y, int up) {
  if (x > n) {
    ans = ans + A[k - wt][up - wt];
    return;
  }
  if (a[x][y]) {
    YL[x][y] = (YL[x - 1][y] | YL[x][y - 1]);
    if (YL[x][y] & (1 << (a[x][y] - 1))) return;
    YL[x][y] |= (1 << (a[x][y] - 1));
    if (y == m)
      dfs(x + 1, 1, up);
    else
      dfs(x, y + 1, up);
  } else {
    int X = YL[x - 1][y] | YL[x][y - 1];
    for (int s = (~X) & ((1 << k) - 1); s; s -= ((s) & (-(s)))) {
      int i = LL2g[((s) & (-(s)))];
      if (i > up + 1) break;
      int P = X;
      if (P & (1 << i - 1)) continue;
      if (Use[x][y] & (1 << i - 1)) continue;
      P |= (1 << i - 1);
      YL[x][y] = P;
      if (y == m)
        dfs(x + 1, 1, (((i) > (up)) ? (i) : (up)));
      else
        dfs(x, y + 1, (((i) > (up)) ? (i) : (up)));
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  if (n + m - 1 > k) {
    printf("0\n");
    return 0;
  }
  for (int i = 0; i <= 20; i++) {
    A[i][0] = 1;
    for (int j = 1; j <= i + 1; j++)
      A[i][j] = A[i][j - 1] * 1ll * (i + 1 - j) % 1000000007;
  }
  for (int i = 1; i <= 20; i++) LL2g[1 << (i - 1)] = i;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      if (a[i][j]) {
        if (!wei[a[i][j]]) wei[a[i][j]] = ++wt;
        a[i][j] = wei[a[i][j]];
      }
      Use[i][j] = (Use[i - 1][j] | Use[i][j - 1]);
      if (a[i][j])
        if (Use[i][j] & (1 << a[i][j] - 1)) {
          printf("0\n");
          return 0;
        }
      if (a[i][j]) Use[i][j] |= (1 << a[i][j] - 1);
    }
  dfs(1, 1, wt);
  printf("%I64d\n", ans % 1000000007);
  return 0;
}
