#include <bits/stdc++.h>
using namespace std;
const int maxn = 30005, P = 1e7 + 19, Q = 1e9 + 7;
int seg[maxn << 2], *dp[maxn << 2], obj[maxn * 17], nxt[maxn * 17], cnt;
void ins(int u, int v) {
  obj[++cnt] = v;
  nxt[cnt] = seg[u];
  seg[u] = cnt;
}
int i, j, tot, n, m, lx[maxn], rx[maxn], wt[maxn], va[maxn];
int qry[maxn], qcnt;
void upd(int x, int l, int r, int L, int R, int OBJ) {
  if (L <= l && r <= R) {
    ins(x, OBJ);
    return;
  }
  int mid = (l + r) >> 1;
  if (L <= mid) upd(x << 1, l, mid, L, R, OBJ);
  if (R > mid) upd(x << 1 | 1, mid + 1, r, L, R, OBJ);
}
void Max(int &x, int y) {
  if (x < y) x = y;
}
int cal(int x, int l, int r, int tar) {
  if (seg[x] != -1) {
    int *pd = dp[x] = new int[m + 1], i, j, t;
    memset(pd, 0, (n + 1) << 2);
    if (x != 1) memcpy(pd, dp[x >> 1], (m + 1) << 2);
    for (i = seg[x]; t = obj[i], i; i = nxt[i]) {
      for (j = m; j >= wt[t]; j--) Max(pd[j], pd[j - wt[t]] + va[t]);
    }
    seg[x] = -1;
  }
  if (l == r) {
    int ans = 0, i;
    for (i = m; i >= 1; i--) ans = ((long long)ans * P + dp[x][i]) % Q;
    return ans;
  }
  int mid = (l + r) >> 1;
  if (tar <= mid) return cal(x << 1, l, mid, tar);
  return cal(x << 1 | 1, mid + 1, r, tar);
}
int main() {
  scanf("%d%d", &tot, &m);
  for (i = 1; i <= tot; i++) scanf("%d%d", va + i, wt + i);
  scanf("%d", &n);
  for (i = 1; i <= tot; i++) lx[i] = 1, rx[i] = n;
  int opt, v, w;
  for (i = 1; i <= n; i++) {
    scanf("%d", &opt);
    if (opt == 1) {
      scanf("%d%d", &v, &w);
      ++tot;
      lx[tot] = i;
      rx[tot] = n;
      va[tot] = v;
      wt[tot] = w;
    } else if (opt == 2) {
      scanf("%d", &v);
      rx[v] = i;
    } else
      qry[++qcnt] = i;
  }
  for (i = 1; i <= tot; i++) upd(1, 1, n, lx[i], rx[i], i);
  for (i = 1; i <= qcnt; i++) printf("%d\n", cal(1, 1, n, qry[i]));
  return 0;
}
