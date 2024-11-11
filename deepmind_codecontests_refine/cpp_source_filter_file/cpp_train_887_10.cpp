#include <bits/stdc++.h>
using namespace std;
int k, n, x[10000], y[10000], z[10000], ans, xx[10000], yy[10000], r,
    la[10][10000], d[10000];
bool flag[10000], ff[10000];
struct lsg {
  int x, y;
} a[10000], b[10000];
int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }
bool dfs(int l) {
  if (l > r) return true;
  int rr = r;
  for (int i = 1; i <= k; i++)
    if (!flag[i]) {
      while (r < rr) ff[d[r--]] = false;
      for (int j = la[i][d[l]]; j; j = la[i][j])
        if (!ff[j]) d[++r] = j, ff[j] = true;
      if (r > k) continue;
      flag[i] = true;
      if (dfs(l + 1)) return true;
      flag[i] = false;
    }
  return false;
}
signed main() {
  ios::sync_with_stdio(false);
  cin >> k >> n;
  for (int i = 1; i <= k; i++) cin >> b[i].x >> b[i].y;
  for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
  for (int l = 1; l <= k; l++) {
    for (int i = 1; i <= n; i++)
      x[i] = a[i].x - b[l].x, y[i] = a[i].y - b[l].y,
      z[i] = gcd(abs(x[i]), abs(y[i])), xx[i] = x[i] / z[i],
      yy[i] = y[i] / z[i];
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (xx[i] == xx[j] && yy[i] == yy[j]) {
          if (i == j) continue;
          if (z[i] > z[j]) {
            if (!la[l][i] || z[la[l][i]] < z[j]) la[l][i] = j;
          } else if (!la[l][j] || z[la[l][j]] < z[i])
            la[l][j] = i;
        }
  }
  for (int i = 1; i <= n; i++) {
    r = 1;
    d[1] = i;
    memset(flag, 0, sizeof(flag));
    memset(ff, 0, sizeof(ff));
    if (dfs(1)) ans++;
  }
  cout << ans << endl;
}
