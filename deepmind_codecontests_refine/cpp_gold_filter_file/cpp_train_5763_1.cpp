#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e3 + 5;
int n, m, c[maxn][maxn], colsum[maxn], rowsum[maxn];
ll dpx[maxn], dpy[maxn];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &c[i][j]);
      rowsum[i] += c[i][j];
      colsum[j] += c[i][j];
    }
  }
  for (int i = 0; i <= m; i++) {
    ll curx = 4 * i;
    for (int j = 1, pos = 2; j <= m; j++, pos += 4) {
      ll temp = 1ll * (curx - pos) * (curx - pos) * colsum[j];
      dpy[i] += temp;
    }
  }
  for (int i = 0; i <= n; i++) {
    ll curx = 4 * i;
    for (int j = 1, pos = 2; j <= n; j++, pos += 4) {
      ll temp = 1ll * (curx - pos) * (curx - pos) * rowsum[j];
      dpx[i] += temp;
    }
  }
  ll best = LLONG_MAX;
  int x = -1, y = -1;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (dpx[i] + dpy[j] < best) best = dpx[i] + dpy[j], x = i, y = j;
    }
  }
  printf("%lld\n%d %d\n", best, x, y);
  return 0;
}
