#include <bits/stdc++.h>
using namespace std;
int n;
int v[405], a[405], ans[405];
int f[405][405], g[405][405], h[405][405];
template <class T>
void chkmax(T &a, T b) {
  if (a < b) a = b;
}
void calc() {
  for (int l = 1; l <= n; l++) {
    for (int i = 1; i + l - 1 <= n; i++) {
      int j = i + l - 1;
      if (i == j) {
        g[i][j] = h[i][j] = 0;
        f[i][j] = v[1];
      } else {
        g[i][j] = h[i][j] = -1000000007;
        for (int k = i + 1; k <= j; k++) {
          if (a[k] == a[i] + 1) chkmax(g[i][j], f[i + 1][k - 1] + g[k][j]);
          if (a[k] == a[i] - 1) chkmax(h[i][j], f[i + 1][k - 1] + h[k][j]);
        }
        f[i][j] = -1000000007;
        for (int k = i; k < j; k++) {
          chkmax(f[i][j], f[i][k] + f[k + 1][j]);
        }
        for (int k = i; k <= j; k++) {
          if (g[i][k] >= 1000000 && h[k][j] >= 1000000)
            chkmax(f[i][j], g[i][k] + h[k][j] + v[2 * a[k] - a[i] - a[j] + 1]);
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    ans[i] = ans[i - 1];
    for (int j = 1; j <= i; j++) {
      chkmax(ans[i], ans[j - 1] + f[j][i]);
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  calc();
  printf("%d\n", ans[n]);
}
