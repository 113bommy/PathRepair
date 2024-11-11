#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
void RlxMax(int &x, int y) {
  if (x < y) x = y;
}
int n, m, q0, lf[1010][1010], rt[1010][1010], up[1010][1010], dn[1010][1010];
bool a[1010][1010];
void CalcY(int x) {
  int lst = 0;
  for (int i = 1; i <= m; i++) {
    if (!a[x][i]) lst = i;
    lf[x][i] = lst + 1;
  }
  lst = m + 1;
  for (int i = m; i >= 1; i--) {
    if (!a[x][i]) lst = i;
    rt[x][i] = lst - 1;
  }
}
void CalcX(int y) {
  int lst = 0;
  for (int i = 1; i <= n; i++) {
    if (!a[i][y]) lst = i;
    up[i][y] = lst + 1;
  }
  lst = n + 1;
  for (int i = n; i >= 1; i--) {
    if (!a[i][y]) lst = i;
    dn[i][y] = lst - 1;
  }
}
int Query(int x, int y) {
  int l = y, r = y, ans = 0;
  for (int i = min(dn[x][y], n); i >= x; i--) {
    while (l > 1 && dn[x][l - 1] >= i) l--;
    while (r < n && dn[x][r + 1] >= i) r++;
    RlxMax(ans, (r - l + 1) * (i - x + 1));
  }
  l = y, r = y;
  for (int i = max(up[x][y], 1); i <= x; i++) {
    while (l > 1 && up[x][l - 1] <= i) l--;
    while (r < n && up[x][r + 1] <= i) r++;
    RlxMax(ans, (r - l + 1) * (x - i + 1));
  }
  l = x, r = x;
  for (int i = min(rt[x][y], m); i >= y; i--) {
    while (l > 1 && rt[l - 1][y] >= i) l--;
    while (r < m && rt[r + 1][y] >= i) r++;
    RlxMax(ans, (r - l + 1) * (i - y + 1));
  }
  l = x, r = x;
  for (int i = max(lf[x][y], 1); i <= y; i++) {
    while (l > 1 && lf[l - 1][y] <= i) l--;
    while (r < m && lf[r + 1][y] <= i) r++;
    RlxMax(ans, (r - l + 1) * (y - i + 1));
  }
  return ans;
}
int main() {
  scanf("%d%d%d", &n, &m, &q0);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  for (int i = 1; i <= m; i++) CalcX(i);
  for (int i = 1; i <= n; i++) CalcY(i);
  int ty, x, y;
  for (int i = 1; i <= q0; i++) {
    scanf("%d%d%d", &ty, &x, &y);
    if (ty == 1)
      a[x][y] ^= 1, CalcX(y), CalcY(x);
    else
      printf("%d\n", Query(x, y));
  }
  return 0;
}
