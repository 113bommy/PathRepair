#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
int n, nn, tjm, mc, ans, ls[N * 3], f[N][N * 3], g1[N * 3], g2[N * 3], h[N];
struct tjmak {
  int p, l, r;
} a[N];
bool operator<(tjmak noi, tjmak ioi) { return noi.p < ioi.p; }
int read() {
  int tjm = 0, fh = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') fh = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') tjm = tjm * 10 + c - 48, c = getchar();
  return tjm * fh;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    ls[++nn] = a[i].p = read();
    tjm = mc = read();
    ls[++nn] = a[i].l = a[i].p - tjm;
    ls[++nn] = a[i].r = a[i].p + mc;
  }
  sort(ls + 1, ls + nn + 1);
  nn = unique(ls + 1, ls + nn + 1) - ls - 1;
  for (int i = 1; i <= n; i++) {
    a[i].p = lower_bound(ls + 1, ls + nn + 1, a[i].p) - ls;
    a[i].l = lower_bound(ls + 1, ls + nn + 1, a[i].l) - ls;
    a[i].r = lower_bound(ls + 1, ls + nn + 1, a[i].r) - ls;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= nn; i++) g2[i] = -1e9;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= a[i].p; j++)
      f[i][a[i].r] = max(f[i][a[i].r], g1[j] + ls[a[i].r] - ls[a[i].p]);
    for (int j = a[i].p + 1; j <= a[i].r; j++)
      f[i][a[i].r] = max(f[i][a[i].r], g2[j] + ls[a[i].r]);
    for (int j = a[i].r + 1; j <= nn; j++) f[i][j] = max(f[i][j], g1[j]);
    tjm = a[i].p;
    for (int j = i - 1; a[i].l <= a[j + 1].p; j--) {
      if (a[i].l <= a[j].p)
        f[i][tjm] = max(f[i][tjm], h[j] + ls[tjm]);
      else
        for (int k = a[j].p; k <= tjm; k++) {
          f[i][tjm] = max(f[i][tjm], f[j][k] + ls[tjm] - ls[max(a[i].l, k)]);
        }
      tjm = max(tjm, a[j].r);
    }
    for (int j = a[i].p; j <= nn; j++) {
      g1[j] = max(g1[j], f[i][j]);
      g2[j] = max(g2[j], f[i][j] - ls[j]);
    }
    h[i] = f[i][nn] - ls[nn];
    for (int j = nn - 1; j >= a[i].p; j--) h[i] = max(h[i], f[i][j] - ls[j]);
  }
  for (int i = a[n].p; i <= nn; i++) ans = max(ans, f[n][i]);
  printf("%d\n", ans);
  return 0;
}
