#include <bits/stdc++.h>
using namespace std;
const int N = 510;
char s[N][N];
int n, k, ans, a[N][N], f[N * N], g[N * N], tot, t;
bool pd[N * N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
void dfs(int x, int y) {
  for (int i = 0; i < 4; i++)
    if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < n &&
        s[x + dx[i]][y + dy[i]] == '.' && a[x + dx[i]][y + dy[i]] == 0) {
      a[x + dx[i]][y + dy[i]] = a[x][y];
      f[a[x][y]]++;
      dfs(x + dx[i], y + dy[i]);
    }
}
void check2(int x, int y) {
  for (int i = 0; i < 4; i++)
    if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < n &&
        s[x + dx[i]][y + dy[i]] == '.' && !pd[a[x + dx[i]][y + dy[i]]]) {
      pd[a[x + dx[i]][y + dy[i]]] = true;
      t += f[a[x + dx[i]][y + dy[i]]];
    }
}
void check(int x, int y) {
  for (int i = 0; i < k; i++) check2(x, y + i);
  for (int i = 0; i < k; i++) check2(x + i, y);
  for (int i = 0; i < k; i++) check2(x + k - 1, y + i);
  for (int i = 0; i < k; i++) check2(x + i, y + k - 1);
}
void check3(int x, int y) {
  for (int i = 0; i < 4; i++)
    if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < n &&
        s[x + dx[i]][y + dy[i]] == '.' && pd[a[x + dx[i]][y + dy[i]]] &&
        g[a[x + dx[i]][y + dy[i]]] == 0) {
      pd[a[x + dx[i]][y + dy[i]]] = false;
      t -= f[a[x + dx[i]][y + dy[i]]];
    }
}
int main() {
  memset(pd, false, sizeof(pd));
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (s[i][j] == '.' && a[i][j] == 0) {
        a[i][j] = ++tot;
        f[tot]++;
        dfs(i, j);
      }
  for (int i = 0; i <= n - k; i++) {
    t = 0;
    memset(g, 0, sizeof(g));
    memset(pd, false, sizeof(pd));
    for (int j = 0; j < k; j++)
      for (int p = 0; p < k; p++) {
        if (s[i + j][p] == 'X')
          t++;
        else {
          g[a[i + j][p]]++;
          if (!pd[a[i + j][p]]) {
            pd[a[i + j][p]] = true;
            t += f[a[i + j][p]];
          }
        }
      }
    check(i, 0);
    ans = max(ans, t);
    for (int j = 1; j <= n - k; j++) {
      for (int p = 0; p < k; p++) {
        if (s[i + p][j - 1] == 'X')
          t--;
        else {
          g[a[i + p][j - 1]]--;
          if (g[a[i + p][j - 1]] == 0) {
            pd[a[i + p][j - 1]] = false;
            t -= f[a[i + p][j - 1]];
          }
        }
        if (s[i + p][j + k - 1] == 'X')
          t++;
        else {
          g[a[i + p][j + k - 1]]++;
          if (!pd[a[i + p][j + k - 1]]) {
            pd[a[i + p][j + k - 1]] = true;
            t += f[a[i + p][j + k - 1]];
          }
        }
      }
      for (int p = 0; p < k; p++) check3(i + p, j - 1);
      check(i, j);
      ans = max(ans, t);
    }
  }
  printf("%d\n", ans);
  return 0;
}
