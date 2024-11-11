#include <bits/stdc++.h>
using namespace std;
int f[100010][2], g[100010][2];
char le[100010], ri[100010], up[100010], dn[100010];
int main() {
  int n, m, ans;
  scanf("%d%d%*d%s%s%s%s", &n, &m, le + 1, ri + 1, up + 1, dn + 1);
  for (int i = 1; i <= m; i++)
    f[1][0] += (up[i] == 'R'), f[1][1] += (up[i] == 'B');
  f[1][0] += (le[1] == 'R') + (ri[1] == 'R');
  f[1][1] += (le[1] == 'B') + (ri[1] == 'B');
  for (int i = 2; i <= n; i++) {
    f[i][0] =
        min(f[i - 1][0], f[i - 1][1] + m) + (le[i] == 'R') + (ri[i] == 'R');
    f[i][1] =
        min(f[i - 1][0] + m, f[i - 1][1]) + (le[i] == 'B') + (ri[i] == 'B');
  }
  for (int i = 1; i <= m; i++)
    f[n][0] += (dn[i] == 'R'), f[n][1] += (dn[i] == 'B');
  ans = min(f[n][0], f[n][1]);
  for (int i = 1; i <= n; i++)
    g[1][0] += (le[i] == 'R'), g[1][1] += (le[i] == 'B');
  g[1][0] += (up[1] == 'R') + (dn[1] == 'R');
  g[1][1] += (up[1] == 'B') + (dn[1] == 'B');
  for (int i = 2; i <= m; i++) {
    g[i][0] =
        min(g[i - 1][0], g[i - 1][1] + n) + (up[i] == 'R') + (dn[i] == 'R');
    g[i][1] =
        min(g[i - 1][0] + n, g[i - 1][1]) + (up[i] == 'B') + (dn[i] == 'B');
  }
  for (int i = 1; i <= n; i++)
    g[n][0] += (ri[i] == 'R'), g[n][1] += (ri[i] == 'B');
  ans = min(ans, min(g[m][0], g[m][1]));
  cout << ans << endl;
  return 0;
}
