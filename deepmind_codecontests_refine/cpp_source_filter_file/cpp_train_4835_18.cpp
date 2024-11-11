#include <bits/stdc++.h>
int FASTBUFFER;
using namespace std;
int n, m, k, i, j, kk, ans, s, a[105][105];
void dfs(int i, int s);
int main() {
  scanf("%d %d %d", &n, &m, &kk);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  ans = kk + 1;
  if (n > k) {
    for (i = 1; i <= n; i++) {
      s = 0;
      for (j = 1; j <= n; j++) {
        if (i == j) continue;
        int s1 = 0, s2 = 0;
        for (k = 1; k <= m; k++)
          if (a[i][k] == a[j][k])
            s1++;
          else
            s2++;
        s += min(s1, s2);
      }
      ans = min(ans, s);
    }
  } else
    dfs(1, 0);
  if (ans > kk)
    printf("-1\n");
  else
    printf("%d\n", ans);
  return 0;
}
void dfs(int i, int s) {
  int x, y;
  if (i > n) {
    for (x = 2; x <= m; x++) {
      int s1 = 0, s2 = 0;
      for (y = 1; y <= n; y++)
        if (a[y][x] == a[1][x])
          s1++;
        else
          s2++;
      s += min(s1, s2);
    }
    ans = min(ans, s);
    return;
  }
  dfs(i + 1, s);
  a[i][1] ^= 1;
  dfs(i + 1, s + 1);
  a[i][1] ^= 1;
}
