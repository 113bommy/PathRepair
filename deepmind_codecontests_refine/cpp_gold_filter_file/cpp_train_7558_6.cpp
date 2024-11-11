#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000 + 10;
const int MAXLOGV = 20;
struct edge {
  int v, next;
} e[MAXN << 1];
int head[MAXN] = {-1};
int tot = 0;
void add(int u, int v) {
  e[tot].v = v;
  e[tot].next = head[u];
  head[u] = tot++;
}
int cnt = 0;
int que[MAXN << 1], fir[MAXN], en[MAXN];
int f[MAXLOGV][MAXN];
int dep[MAXN];
void dfs(int u, int fa) {
  que[++cnt] = u;
  fir[u] = cnt;
  f[0][u] = fa;
  dep[u] = dep[fa] + 1;
  for (int k = head[u]; k != -1; k = e[k].next) {
    int v = e[k].v;
    if (v == fa) continue;
    dfs(v, u);
  }
  que[++cnt] = u;
  en[u] = cnt;
}
void lca_init(int n) {
  for (int k = 0; k + 1 < MAXLOGV; k++) {
    for (int v = 1; v <= n; v++) {
      if (f[k][v] == 0)
        f[k + 1][v] = 0;
      else
        f[k + 1][v] = f[k][f[k][v]];
    }
  }
}
int lca(int u, int v) {
  if (dep[u] > dep[v]) swap(u, v);
  for (int k = 0; k < MAXLOGV; k++) {
    if ((dep[v] - dep[u]) >> k & 1) {
      v = f[k][v];
    }
  }
  if (u == v) return u;
  for (int k = MAXLOGV - 1; k >= 0; k--) {
    if (f[k][u] != f[k][v]) {
      u = f[k][u];
      v = f[k][v];
    }
  }
  return f[0][u];
}
struct ask {
  int l, r, id;
  int lca;
} qu[MAXN << 1];
int pos[MAXN], vis[MAXN];
int cmp(ask a, ask b) {
  if (pos[b.l] == pos[a.l])
    return a.r < b.r;
  else
    return pos[a.l] < pos[b.l];
}
int Hash[MAXN];
int num;
void getHash(int a[], int n) {
  for (int i = 1; i <= n; i++) {
    Hash[i] = a[i];
  }
  sort(Hash + 1, Hash + n + 1);
  num = (int)(unique(Hash + 1, Hash + n + 1) - Hash - 1);
}
int getNum(int x) {
  int res = (int)(lower_bound(Hash + 1, Hash + num + 1, x) - Hash);
  return res;
}
int c[MAXN];
int a[MAXN];
long long val[MAXN][2];
int n, m;
void update(int u, long long &res) {
  int tmp = getNum(a[u]);
  vis[u] ^= 1;
  if (vis[u]) {
    res += val[tmp][c[u] ^ 1];
    val[tmp][c[u]]++;
  } else {
    res -= val[tmp][c[u] ^ 1];
    val[tmp][c[u]]--;
  }
}
long long ans[MAXN];
void solve() {
  int bk = ceil(sqrt(1.0 * cnt));
  for (int i = 1; i <= cnt; i++) {
    pos[i] = (i - 1) / bk;
  }
  sort(qu + 1, qu + m + 1, cmp);
  int l = qu[1].l, r = qu[1].l - 1;
  long long res = 0;
  for (int i = 1; i <= m; i++) {
    int id = qu[i].id, ml = qu[i].l, mr = qu[i].r, LCA = qu[i].lca;
    while (l > ml) update(que[--l], res);
    while (l < ml) update(que[l++], res);
    while (r > mr) update(que[r--], res);
    while (r < mr) update(que[++r], res);
    ans[id] = res;
    if (LCA) ans[id] += val[getNum(a[LCA])][c[LCA] ^ 1];
  }
  for (int i = 1; i <= m; i++) printf("%lld\n", ans[i]);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", c + i);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  getHash(a, n);
  memset(head, -1, sizeof head);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v);
    add(v, u);
  }
  dep[0] = 0;
  dfs(1, 0);
  lca_init(n);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    int LCA = lca(u, v);
    if (LCA == u || LCA == v) {
      if (fir[u] > fir[v]) {
        swap(u, v);
      }
      qu[i].l = fir[u];
      qu[i].r = fir[v];
      qu[i].lca = 0;
      qu[i].id = i;
    } else {
      if (en[u] > fir[v]) swap(u, v);
      qu[i].l = en[u];
      qu[i].r = fir[v];
      qu[i].lca = LCA;
      qu[i].id = i;
    }
  }
  solve();
}
