#include <bits/stdc++.h>
using namespace std;
inline void cmax(int &x, int y) { x < y ? x = y : 0; }
const int N = 410;
int n;
int v[N], w[N];
int f[N][N], g[N][N][2];
int ans[N];
int main() {
  scanf("%d", &n);
  for (register int i = 1; i <= n; i++) scanf("%d", &v[i]);
  for (register int i = 1; i <= n; i++) scanf("%d", &w[i]);
  for (int l = n; l; l--) {
    f[l][l] = v[1];
    for (register int r = l + 1; r <= n; r++) {
      f[l][r] = g[l][r][0] = g[l][r][1] = -(1 << 28);
      for (int k = l; k < r; k++)
        if (w[k] + 1 == w[r]) cmax(g[l][r][0], g[l][k][0] + f[k + 1][r - 1]);
      for (int k = r; k > l; k--)
        if (w[k] + 1 == w[l]) cmax(g[l][r][1], g[k][r][1] + f[l + 1][k - 1]);
      for (register int k = l; k <= r; k++) {
        int tmp = w[k] + w[k] - w[l] - w[r] + 1;
        if (1 <= tmp && tmp <= n)
          cmax(f[l][r], g[l][k][0] + g[k][r][1] + v[tmp]);
      }
      for (register int k = l; k <= r - 1; k++)
        cmax(f[l][r], f[l][k] + f[k + 1][r]);
    }
  }
  for (register int i = 1; i <= n; i++) {
    ans[i] = ans[i - 1];
    for (int j = i; j; j--) cmax(ans[i], ans[j - 1] + f[j][i]);
  }
  printf("%d\n", ans[n]);
  return 0;
}
