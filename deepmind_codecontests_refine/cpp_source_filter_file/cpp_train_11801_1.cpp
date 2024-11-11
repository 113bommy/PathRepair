#include <bits/stdc++.h>
using namespace std;
map<string, int> mm;
char s[200];
int an, n, ma, ans, m, mx, k, i, j, kk, sw, a[500001], ne[500001][17],
    f[40000][227], fir[20];
int main() {
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%s", s), mm[s] = i;
  scanf("%d", &m);
  ma = n * (n - 1) / 2 + 1;
  int mx = m;
  an = 1e9;
  for (; m; m--) {
    scanf("%d", &k);
    for (i = 0; i < n; i++) fir[i] = k;
    a[k] = 0;
    for (i = 0; i < k; i++) {
      scanf("%s", s);
      if (mm.count(s))
        a[i] = mm[s];
      else
        a[i] = -1;
    }
    for (i = k; i >= 0; i--) {
      if (a[i] != -1) fir[a[i]] = i;
      for (kk = 0; kk < n; kk++) ne[i][kk] = fir[kk];
    }
    for (i = 0; i <= (1 << n) - 1; i++)
      for (j = 0; j < ma; j++) f[i][j] = 1e9;
    f[0][0] = -1;
    for (i = 0; i < (1 << n); i++)
      for (j = 0; j < ma; j++)
        if (f[i][j] < k) {
          for (kk = 0; kk < n; kk++)
            if ((i >> kk) % 2 == 0)
              f[i + (1 << kk)][j + __builtin_popcount(i >> kk)] =
                  min(f[i + (1 << kk)][j + __builtin_popcount(i >> kk)],
                      ne[f[i][j] + 1][kk]);
        }
    for (i = 0; i < ma; i++)
      if (f[(1 << n) - 1][i] < k) {
        if (i < an) an = i;
        ans = mx - m + 1;
        break;
      }
  }
  if (an != 1e9) {
    cout << ans << endl << "[:";
    for (i = 0; i < (n - 1) * n / 2 - an + 1; i++) cout << '|';
    cout << ":]" << endl;
  } else
    cout << "Brand new problem!";
  return (0);
}
