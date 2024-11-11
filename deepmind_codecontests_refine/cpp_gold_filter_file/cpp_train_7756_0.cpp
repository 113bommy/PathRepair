#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 19;
const int M = 1e9 + 7;
int tp[N], a[N], pv[N];
vector<int> con[N];
int sz[N], pa[N];
void dfs(int u) {
  sz[u] = 1;
  for (int v : con[u]) {
    dfs(v);
    sz[u] += sz[v];
  }
}
int hd[N], st[N], en[N], pid[N], T, pn = 1;
void hld(int u) {
  if (hd[pn] == 0) hd[pn] = u;
  int k(-1), mx(-1);
  st[u] = ++T;
  pid[u] = pn;
  for (int v : con[u])
    if (mx < sz[v]) mx = sz[v], k = v;
  if (k != -1) hld(k);
  for (int v : con[u]) {
    if (v == k) continue;
    pn += 2;
    hld(v);
  }
  en[u] = T;
}
int inv(int val) {
  int n = M - 2, ret = 1;
  for (; n; n >>= 1, val = 1LL * val * val % M)
    if (n % 2) ret = 1LL * ret * val % M;
  return ret;
}
int add[N], mul[N];
void down(int u) {
  if (mul[u] != 1) {
    mul[u + u] = 1LL * mul[u + u] * mul[u] % M;
    mul[u + u + 1] = 1LL * mul[u + u + 1] * mul[u] % M;
    add[u + u] = 1LL * add[u + u] * mul[u] % M;
    add[u + u + 1] = 1LL * add[u + u + 1] * mul[u] % M;
    mul[u] = 1;
  }
  if (add[u]) {
    add[u + u] = (add[u + u] + add[u]) % M;
    add[u + u + 1] = (add[u + u + 1] + add[u]) % M;
    add[u] = 0;
  }
}
void update(int u, int l, int r, int cl, int cr, int x, int y) {
  if (cl <= l && r <= cr) {
    add[u] = (add[u] + x) % M;
    mul[u] = 1LL * mul[u] * y % M;
    add[u] = 1LL * add[u] * y % M;
    return;
  }
  int md = l + r >> 1;
  down(u);
  if (cl <= md) update(u + u, l, md, cl, cr, x, y);
  if (md < cr) update(u + u + 1, md + 1, r, cl, cr, x, y);
}
int aa, bb;
void query(int u, int l, int r, int p) {
  if (l == p && r == p) {
    aa = add[u], bb = mul[u];
    return;
  }
  down(u);
  int md = l + r >> 1;
  if (p <= md)
    query(u + u, l, md, p);
  else
    query(u + u + 1, md + 1, r, p);
}
int main() {
  int n = 1, q;
  scanf("%d%d", a + 1, &q);
  for (int i = 0; i < q; i++) {
    scanf("%d%d", tp + i, pv + i);
    if (tp[i] == 1) {
      int w;
      scanf("%d", &w);
      pa[++n] = pv[i];
      con[pv[i]].push_back(n);
      a[n] = w;
    }
  }
  dfs(1);
  hld(1);
  for (int i = 0; i < N; i++) add[i] = 0, mul[i] = 1, sz[i] = 1;
  update(1, 1, n, 1, 1, a[1], 1);
  int m = 1;
  for (int i = 0; i < q; i++) {
    int u = pv[i];
    query(1, 1, n, st[u]);
    if (tp[i] == 1) {
      ++m;
      int pp = 1LL * inv(sz[u]) * (sz[u] + 1) % M;
      update(1, 1, n, st[u] + 1, en[u], 0, pp);
      aa = 1LL * aa * inv(bb) % M;
      int dQ = (1LL * aa * inv(sz[u]) % M + a[m]) % M;
      dQ = (dQ + 1LL * a[m] * sz[u] % M) % M;
      sz[u]++;
      dQ = 1LL * dQ * bb % M;
      do {
        int tp = hd[pid[u]];
        int uu = st[tp];
        int vv = st[u];
        update(1, 1, n, uu, vv, dQ, 1);
        u = pa[tp];
      } while (u);
      update(1, 1, n, st[m], st[m], 1LL * sz[pv[i]] * bb % M * a[m] % M, 1);
    } else {
      int ans = 1LL * aa * inv(bb) % M;
      printf("%d\n", ans);
    }
  }
  return 0;
}
