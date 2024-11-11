#include <bits/stdc++.h>
using namespace std;
const int N = 505, second = 37;
int n, m;
int len[11], ini[16][11][N][N], a[N][N], f[N][N];
char s[N][N];
unsigned long long ba[N], ha[16][11][N], has[N][N];
void dfs(int t, int _, int x1, int x2, int y1, int y2) {
  if (x1 == x2) return;
  int x = (x1 + x2) / 2 + 1, y = (y1 + y2) / 2 + 1;
  if (_ & 1) {
    for (int i = (x1); i < (x); i++)
      for (int j = (y1); j < (y); j++) ini[_][t][i][j] = 1;
  } else {
    dfs(t, _, x1, x - 1, y1, y - 1);
  }
  if (_ >> 1 & 1) {
    for (int i = (x1); i < (x); i++)
      for (int j = (y); j < (y2 + 1); j++) ini[_][t][i][j] = 1;
  } else {
    dfs(t, _, x1, x - 1, y, y2);
  }
  if (_ >> 2 & 1) {
    for (int i = (x); i < (x2 + 1); i++)
      for (int j = (y1); j < (y); j++) ini[_][t][i][j] = 1;
  } else {
    dfs(t, _, x, x2, y1, y - 1);
  }
  if (_ >> 3 & 1) {
    for (int i = (x); i < (x2 + 1); i++)
      for (int j = (y); j < (y2 + 1); j++) ini[_][t][i][j] = 1;
  } else {
    dfs(t, _, x, x2, y, y2);
  }
}
void init() {
  ba[0] = 1;
  for (int i = (1); i < (N); i++) ba[i] = ba[i - 1] * second;
  len[0] = 1;
  for (int i = (1); i < (11); i++) len[i] = len[i - 1] * 2;
  for (int t = (2); t < (3); t++)
    for (int _ = (0); _ < (16); _++) {
      dfs(t, _, 1, len[t], 1, len[t]);
      for (int i = (1); i < (len[t] + 1); i++) {
        for (int j = (1); j < (len[t] + 1); j++)
          ha[_][t][i] = ha[_][t][i] * second + ini[_][t][i][j];
      }
    }
}
unsigned long long get(int x, int l, int r) {
  return has[x][r] - has[x][l - 1] * ba[r - l + 1];
}
int calc(int x, int y) {
  int mi = min(x, y);
  int res = 0;
  for (int t = 2; len[t] <= mi; ++t)
    for (int _ = (0); _ < (16); _++) {
      bool ok = 1;
      for (int i = (1); i < (len[t] + 1); i++) {
        if (get(i - len[t] + x, y - len[t] + 1, y) != ha[_][t][i]) {
          ok = 0;
          break;
        }
      }
      res += ok;
    }
  return res;
}
int main() {
  init();
  while (~scanf("%d%d", &n, &m)) {
    for (int i = (1); i < (n + 1); i++) scanf("%s", s[i] + 1);
    for (int i = (1); i < (n + 1); i++)
      for (int j = (1); j < (m + 1); j++) a[i][j] = (s[i][j] == '*') ? 1 : 0;
    for (int i = (1); i < (n + 1); i++)
      for (int j = (1); j < (m + 1); j++)
        has[i][j] = has[i][j - 1] * second + a[i][j];
    for (int i = (1); i < (n + 1); i++)
      for (int j = (1); j < (m + 1); j++) {
        f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + calc(i, j);
      }
    printf("%d\n", f[n][m]);
  }
  return 0;
}
