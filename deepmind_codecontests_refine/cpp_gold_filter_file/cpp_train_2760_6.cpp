#include <bits/stdc++.h>
using namespace std;
const int nmax = 1002, hx[]{-1, 0, 1, 0}, hy[]{0, -1, 0, 1};
int n, m, lab[nmax][nmax], mark[nmax * nmax], num[nmax * nmax], c, t;
char a[nmax][nmax], s[nmax];
int dfs(int x, int y) {
  if (lab[x][y] != 0 || a[x][y] != '.') return 0;
  lab[x][y] = c;
  int res = 1;
  for (int i = 0; i < 4; i++) res += dfs(x + hx[i], y + hy[i]);
  return res;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    for (int j = 1; j <= m; j++) a[i][j] = s[j - 1];
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      c++;
      num[c] = dfs(i, j);
    }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == '.')
        cout << ".";
      else {
        int res = 1;
        t++;
        for (int k = 0; k < 4; k++) {
          int tmp = lab[i + hx[k]][j + hy[k]];
          if (mark[tmp] != t) res += num[tmp];
          mark[tmp] = t;
        }
        cout << res % 10;
      }
    }
    cout << endl;
  }
}
