#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[40][40];
int a[40][40], A[40], B[40], ans = 0, flag = 0;
int u[40][40], q[40];
void dfs(const int C, const int x) {
  if (x == 14) {
    ++flag;
    for (int i = 0, X, Y; i < 28; ++i) {
      X = q[A[i]], Y = q[B[i]];
      if (u[X][Y] == flag) return;
      u[X][Y] = u[Y][X] = flag;
    }
    ++ans;
    if (ans == 1) {
      for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
          s[i][j] = (a[i][j] >= 0 ? q[a[i][j]] + '0' : '.');
    }
    return;
  }
  if (q[x] >= 0) {
    dfs(C, x + 1);
    return;
  }
  q[x] = C;
  for (int i = x + 1; i < 14; ++i)
    if (q[i] < 0) {
      q[i] = C;
      dfs(C + 1, x + 1);
      q[i] = -1;
    }
  q[x] = -1;
}
int main() {
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= m; ++i) scanf("%s", s[i] + 1);
  memset(a, -1, sizeof(a));
  memset(A, -1, sizeof(A));
  memset(B, -1, sizeof(B));
  memset(u, -1, sizeof(u));
  memset(q, -1, sizeof(q));
  for (int cp = 0, i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j)
      if (s[i][j] != '.') {
        if (a[i][j] < 0)
          a[i][j] = a[i + 1][j] = a[i][j + 1] = a[i + 1][j + 1] = cp, ++cp;
        int p = (s[i][j] <= 'B' ? s[i][j] - 'A' + 26 : s[i][j] - 'a');
        if (A[p] >= 0)
          B[p] = a[i][j];
        else
          A[p] = a[i][j];
      }
  dfs(0, 0);
  cout << ans * 5040 << endl;
  for (int i = 1; i <= m; ++i) puts(s[i] + 1);
  return 0;
}
