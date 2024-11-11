#include <bits/stdc++.h>
using namespace std;
int n, m, f[53][35005], v[35005], co[35005], nowl, nowr, nowans;
int query(int ql, int qr) {
  while (nowl > ql) {
    --nowl;
    if (!co[v[nowl]]) ++nowans;
    ++co[v[nowl]];
  }
  while (nowr < qr) {
    ++nowr;
    if (!co[v[nowr]]) ++nowans;
    ++co[v[nowr]];
  }
  while (nowl < ql) {
    --co[v[nowl]];
    if (!co[v[nowl]]) --nowans;
    ++nowl;
  }
  while (nowr > qr) {
    --co[v[nowr]];
    if (!co[v[nowr]]) --nowans;
    --nowr;
  }
  return nowans;
}
void solve(int k, int l, int r, int ql, int qr) {
  int mid = l + r >> 1, opt;
  for (int hc, i = min(qr, mid); i >= ql; --i) {
    hc = query(i + 1, mid) + f[k - 1][i];
    if (hc > f[k][mid]) f[k][mid] = hc, opt = i;
  }
  if (mid - 1 >= l) solve(k, l, mid - 1, ql, opt);
  if (mid + 1 <= r) solve(k, mid + 1, r, opt, qr);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &v[i]);
  for (int i = 1; i <= m; ++i) solve(i, 1, n, 0, n);
  printf("%d", f[m][n]);
  return 0;
}
