#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
inline int sign(double x) { return (x > eps) - (x < -eps); }
const int maxn = 2e5 + 10, mod = 1e9 + 7, INF = 0x3f3f3f3f;
int a[maxn], st[2][maxn][22], lg[maxn];
void init(int n) {
  for (int i = 2; i <= n; ++i) lg[i] = lg[i - 1] + (i == (i & -i));
  for (int i = 1; i <= n; ++i) st[0][i][0] = st[1][i][0] = a[i];
  for (int j = 1; (1 << j) <= n; ++j)
    for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
      st[0][i][j] = min(st[0][i][j - 1], st[0][i + (1 << (j - 1))][j - 1]);
      st[1][i][j] = max(st[1][i][j - 1], st[1][i + (1 << (j - 1))][j - 1]);
    }
}
inline int qry_dif(int l, int r) {
  int k = lg[r - l + 1];
  return max(st[1][l][k], st[1][r - (1 << k) + 1][k]) -
         min(st[0][l][k], st[0][r - (1 << k) + 1][k]);
}
int f[maxn << 2];
void upd(int p, int c, int l, int r, int rt) {
  if (l == r) {
    f[rt] = c;
    return;
  }
  int m = l + r >> 1;
  if (p <= m)
    upd(p, c, l, m, rt << 1);
  else
    upd(p, c, m + 1, r, rt << 1 | 1);
  f[rt] = min(f[rt << 1], f[rt << 1 | 1]);
}
int qry(int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) return f[rt];
  int m = l + r >> 1, res = INF;
  if (L <= m) res = min(res, qry(L, R, l, m, rt << 1));
  if (R > m) res = min(res, qry(L, R, m + 1, r, rt << 1 | 1));
  return res;
}
int main() {
  int n, s, len;
  cin >> n >> s >> len;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  init(n);
  int ans = INF;
  upd(0, 0, 0, n, 1);
  for (int i = 1; i <= n; ++i) {
    int l = 1, r = i, pos;
    while (l <= r) {
      int m = l + r >> 1;
      if (qry_dif(m, i) <= s)
        r = m - 1, pos = m;
      else
        l = m + 1;
    }
    int val = pos - 1 <= i - len ? qry(pos - 1, i - len, 0, n, 1) + 1 : INF;
    upd(i, val, 0, n, 1);
    ans = val;
  }
  printf("%d", ans > n ? -1 : ans);
  return 0;
}
