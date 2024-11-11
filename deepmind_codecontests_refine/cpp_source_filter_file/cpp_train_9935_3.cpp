#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[405][405];
short int up[405][405][405];
int f[405][405];
int ret;
bool bo[160010];
void init() {
  int i, j, k, l, r;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  ret = 0;
  for (l = 1; l <= m - 1; l++) {
    for (r = l + 1; r <= m; r++) {
      int now = n;
      for (i = n; i >= 1; i--) {
        now = min(now, i);
        while (now && a[now][l] != a[now][r] && !bo[a[now][l]] &&
               !bo[a[now][r]]) {
          bo[a[now][l]] = bo[a[now][r]] = 1;
          now--;
        }
        up[i][l][r] = i - now;
        bo[a[i][l]] = bo[a[i][r]] = 0;
      }
    }
    int now = n;
    for (i = n; i >= 1; i--) {
      now = min(now, i);
      while (now && !bo[a[now][l]]) {
        bo[a[now][l]] = 1;
        now--;
      }
      ret = max(i - now, ret);
      bo[a[i][l]] = 0;
    }
  }
}
void solve() {
  int i, j, k, l, r, len;
  for (i = 1; i <= n; i++) {
    memset(f, 0, sizeof(f));
    for (l = 1; l <= m - 1; l++) {
      f[l][l + 1] = up[i][l][l + 1];
      ret = max(ret, (int)f[l][l + 1] * 2);
    }
    for (len = 3; len <= m; len++) {
      for (l = 1; l <= m - len + 1; l++) {
        r = l + len - 1;
        f[l][r] = min(min(f[l + 1][r], f[l][r - 1]), (int)up[i][l][r]);
        ret = max(ret, (int)f[l][r] * (r - l + 1));
      }
    }
  }
  printf("%d\n", ret);
}
int main() {
  init();
  solve();
  return 0;
}
