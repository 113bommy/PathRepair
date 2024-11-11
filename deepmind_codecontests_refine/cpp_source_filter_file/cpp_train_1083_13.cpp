#include <bits/stdc++.h>
using namespace std;
int q[101010], p[11], d[2020][11], u[2020][11], v[2020][11], tr[11][11],
    a[2020][2020], n, k, m, r, i, j, ex, s, l, ans;
int mx(int x, int y) {
  if (x > y) y = x;
  return y;
}
int main() {
  cin >> n >> m >> k >> s;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) cin >> a[i][j];
  for (i = 1; i <= s; i++) cin >> q[i];
  for (i = 1; i <= k; i++)
    for (j = 1; j <= k; j++) tr[i][j] = 0;
  for (i = 1; i <= k; i++)
    for (j = 1; j <= m; j++) u[i][j] = 0;
  for (i = 1; i <= n; i++) {
    for (l = 1; l <= k; l++) p[l] = 0;
    for (l = 1; l <= k; l++) v[0][l] = 0;
    for (j = 1; j <= m; j++) {
      for (l = 1; l <= k; l++) {
        v[j][l] = v[j - 1][l] + p[l];
      }
      p[a[i][j]] = 1;
    }
    for (l = 1; l <= k; l++) p[l] = 0;
    for (l = 1; l <= k; l++) d[m + 1][l] = 0;
    for (j = m; j >= 1; j--) {
      for (l = 1; l <= k; l++) {
        d[j][l] = d[j + 1][l] + p[l];
      }
      p[a[i][j]] = 1;
    }
    for (j = 1; j <= m; j++)
      for (l = 1; l <= k; l++) {
        v[j][l] = mx(v[j][l], d[j][l]);
        if ((u[j][l] == 0) && (a[i][j] != l)) u[j][l]--;
        u[j][l] = mx(u[j][l] + 1, v[j][l]);
        tr[l][a[i][j]] = mx(u[j][l], tr[l][a[i][j]]);
        tr[a[i][j]][l] = mx(u[j][l], tr[a[i][j]][l]);
      }
  }
  ans = 1;
  for (i = 1; i <= (s - 1); i++) {
    if (tr[q[i], q[i + 1]] == 0) ans = 0;
    ex = mx(ex, tr[q[i]][q[i + 1]]);
  }
  if (ans == 0) ex = 0;
  cout << ex;
  return 0;
}
