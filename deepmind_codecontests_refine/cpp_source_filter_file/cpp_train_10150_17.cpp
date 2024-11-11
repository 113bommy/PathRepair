#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7, N = 505;
int f[2][N][N];
char a[N][N];
void add(int &x, int val) {
  x += val;
  if (x >= P) x -= P;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%s", a[i] + 1);
  f[0][1][n] = a[1][1] == a[n][m];
  int len = n + m - 1;
  int cur = 0, nxt = 1;
  for (int t = 0; t < len / 2; ++t) {
    for (int i = 1; i <= n; ++i) {
      int j = t - (i - 1) + 1;
      for (int p = n; p >= 1; --p) {
        if (!f[cur][i][p]) continue;
        int q = m - (i - 1 + j - 1 - (n - p));
        if (a[i + 1][j] != 0 && a[i + 1][j] == a[p - 1][q])
          add(f[nxt][i + 1][p - 1], f[cur][i][p]);
        if (a[i + 1][j] != 0 && a[i + 1][j] == a[p][q - 1])
          add(f[nxt][i + 1][p], f[cur][i][p]);
        if (a[i][j + 1] != 0 && a[i][j + 1] == a[p][q - 1])
          add(f[nxt][i][p], f[cur][i][p]);
        if (a[i][j + 1] != 0 && a[i][j + 1] == a[p - 1][q])
          add(f[nxt][i][p - 1], f[cur][i][p]);
      }
    }
    memset(f[cur], 0, sizeof(f[cur]));
    swap(cur, nxt);
  }
  int ans = 0;
  if (len & 1) {
    for (int i = 1; i <= n; ++i) add(ans, f[cur][i][i]);
  } else {
    for (int i = 1; i <= n; ++i) {
      if (i + 1 <= n) add(ans, f[cur][i][i + 1]);
      add(ans, f[cur][i][i]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
