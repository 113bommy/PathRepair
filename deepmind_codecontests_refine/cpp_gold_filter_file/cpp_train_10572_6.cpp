#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 5;
const int maxh = 12;
int mat[maxn][maxn], rg[maxn][maxn], dw[maxn][maxn], a[maxn][maxn], mm[maxn];
int d[maxn << 2][maxn][maxh];
void pushup(int rt, int m) {
  for (int j = 0; (1 << j) <= m; ++j) {
    for (int i = 1; i + (1 << j) - 1 <= m; ++i) {
      d[rt][i][j] = max(d[rt << 1][i][j], d[rt << 1 | 1][i][j]);
    }
  }
}
void build(int rt, int l, int r, int m) {
  if (l == r) {
    for (int i = 1; i <= m; ++i) d[rt][i][0] = mat[l][i];
    for (int j = 1; (1 << j) <= m; ++j) {
      for (int i = 1; i + (1 << j) - 1 <= m; ++i) {
        d[rt][i][j] = max(d[rt][i][j - 1], d[rt][i + (1 << (j - 1))][j - 1]);
      }
    }
    return;
  }
  int mid = (l + r) >> 1;
  build(rt << 1, l, mid, m);
  build(rt << 1 | 1, mid + 1, r, m);
  pushup(rt, m);
}
int rmq(int rt, int l, int r) {
  int k = mm[r - l + 1];
  return max(d[rt][l][k], d[rt][r - (1 << k) + 1][k]);
}
int query(int rt, int l, int r, int x1, int y1, int x2, int y2) {
  if (x1 <= l && r <= x2) return rmq(rt, y1, y2);
  int mid = (l + r) >> 1, ret = 0;
  if (x1 <= mid) ret = max(ret, query(rt << 1, l, mid, x1, y1, x2, y2));
  if (mid < x2) ret = max(ret, query(rt << 1 | 1, mid + 1, r, x1, y1, x2, y2));
  return ret;
}
int main() {
  mm[0] = -1;
  for (int i = 1; i < maxn; ++i)
    mm[i] = (i & (i - 1)) ? mm[i - 1] : mm[i - 1] + 1;
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = n; i > 0; --i) {
    for (int j = m; j > 0; --j) {
      if (a[i][j]) {
        rg[i][j] = rg[i][j + 1] + 1;
        dw[i][j] = dw[i + 1][j] + 1;
        mat[i][j] = min(mat[i + 1][j + 1] + 1, min(rg[i][j], dw[i][j]));
      }
    }
  }
  build(1, 1, n, m);
  int q;
  scanf("%d", &q);
  while (q--) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    int l = 0, r = min(x2 - x1, y2 - y1) + 1;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (query(1, 1, n, x1, y1, x2 - mid + 1, y2 - mid + 1) >= mid)
        l = mid;
      else
        r = mid - 1;
    }
    printf("%d\n", l);
  }
  return 0;
}
