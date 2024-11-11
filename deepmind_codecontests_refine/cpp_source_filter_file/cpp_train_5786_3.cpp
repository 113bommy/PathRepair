#include <bits/stdc++.h>
using namespace std;
const int maxn = 16;
int f[1 << maxn][maxn * maxn], col[maxn], a[maxn], b[maxn], n;
int main() {
  scanf("%d", &n);
  int sa = 0, sb = 0;
  for (int i = 0; i < n; i++) {
    char st[10];
    scanf("%s", st);
    col[i] = (st[0] == 'R' ? 0 : 1);
    scanf("%d%d", &a[i], &b[i]);
    sa += a[i], sb += b[i];
  }
  memset(f, 255, sizeof f);
  f[0][0] = 0;
  for (int s = 0; s < (1 << n) - 1; s++) {
    int b_c = 0, r_c = 0;
    for (int i = 0; i < n; i++)
      if (s & (1 << i)) {
        if (col[i])
          ++b_c;
        else
          ++r_c;
      }
    for (int r = 0; r <= n * n; r++)
      if (f[s][r] >= 0) {
        int v = f[s][r];
        for (int i = 0; i < n; i++)
          if (!(s & (1 << i))) {
            int nr = r + min(a[i], r_c), nb = f[s][r] + min(b[i], b_c);
            f[s | (1 << i)][nr] = max(f[s | (1 << i)][nr], nb);
          }
      }
  }
  int ans = (1 << 30);
  for (int i = 0; i <= n * n; i++)
    if (f[(1 << n) - 1][i] >= 0)
      ans = min(ans, max(sa - i, sb - f[(1 << n) - 1][i]));
  ans = max(ans, 0);
  cout << ans + n << endl;
  return 0;
}
