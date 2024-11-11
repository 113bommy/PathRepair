#include <bits/stdc++.h>
using namespace std;
const int maxn = 500;
int dx[5] = {-1, 1, 0, 0};
int dy[5] = {0, 0, -1, 1};
int n, k;
char c[maxn + 5][maxn + 5];
int tot, f[maxn + 5][maxn + 5], sz[maxn * maxn + 5];
int cnt[maxn + 5];
int ans, tans;
void dfs(int i, int j) {
  if (i < 1 || j < 1 || i > n || j > n || c[i][j] == 'X' || f[i][j] != 0)
    return;
  sz[tot]++;
  f[i][j] = tot;
  for (int t = 0; t < 4; t++) dfs(i + dx[t], j + dy[t]);
}
void ins(int i, int j) {
  if (c[i][j] != '.') return;
  if (!cnt[f[i][j]]) tans += sz[f[i][j]];
  cnt[f[i][j]]++;
}
void del(int i, int j) {
  if (c[i][j] != '.') return;
  cnt[f[i][j]]--;
  if (!cnt[f[i][j]]) tans -= sz[f[i][j]];
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%s", c[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (c[i][j] == 'X') continue;
      if (!f[i][j]) {
        tot++;
        dfs(i, j);
      }
    }
  for (int i = 1; i <= n - k + 1; i++) {
    memset(cnt, 0, tot * 4 + 4);
    tans = 0;
    for (int ti = -1; ti <= k; ti++)
      for (int tj = 0; tj <= k + 1; tj++) {
        ins(i + ti, tj);
        if (c[i + ti][tj] == 'X')
          if (ti >= 0 && ti < k && tj >= 1 && tj <= k) tans++;
      }
    del(i - 1, 0);
    del(i - 1, k + 1);
    del(i + k, 0);
    del(i + k, k + 1);
    for (int j = 1; j <= n - k; j++) {
      ans = max(ans, tans);
      for (int ti = 0; ti < k; ti++) del(i + ti, j - 1);
      for (int ti = 0; ti < k; ti++) ins(i + ti, j + k + 1);
      for (int ti = 0; ti < k; ti++)
        if (c[i + ti][j] == 'X') tans--;
      for (int ti = 0; ti < k; ti++)
        if (c[i + ti][j + k] == 'X') tans++;
      del(i - 1, j);
      del(i + k, j);
      ins(i - 1, j + k);
      ins(i + k, j + k);
    }
    ans = max(ans, tans);
  }
  printf("%d\n", ans);
  return 0;
}
