#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) {
    if (ch == '-') f = -1;
  }
  for (; isdigit(ch); ch = getchar()) {
    x = x * 10 + ch - 48;
  }
  return x * f;
}
const int N = 2e5;
const int Q = 5e5;
const int S = 26;
int n, q, m, siz, dfnn, en;
int bit[N + 3];
void add(int u, int x) {
  while (u <= siz + 1) {
    bit[u] += x;
    u += (u & (-u));
  }
}
int query(int u) {
  int ret = 0;
  while (u) {
    ret += bit[u];
    u -= (u & (-u));
  }
  return ret;
}
int query(int l, int r) { return query(r) - query(l - 1); }
struct Query {
  int r, x, id, coe;
  bool operator<(const Query &arg) const { return r < arg.r; }
} qr[(Q << 1) + 3];
int ans[N + 3];
int que[N + 3];
char str[N + 3];
int acaid[N + 3];
struct Edge {
  int v, nxt;
} e[(N << 1) + 3];
int fe[N + 3];
int fa[N + 3], son[N + 3][S + 3], fail[N + 3];
int dfn[N + 3], sz[N + 3];
void addedge(int u, int v) {
  en++;
  e[en].v = v;
  e[en].nxt = fe[u];
  fe[u] = en;
}
int insertstr() {
  scanf("%s", str + 1);
  int len = strlen(str + 1);
  int u = 0;
  for (int i = 1; i <= len; i++) {
    str[i] -= 96;
    if (!son[u][str[i]]) {
      son[u][str[i]] = ++siz;
      fa[siz] = u;
    }
    u = son[u][str[i]];
  }
  return u;
}
void buildACA() {
  int hd = 1, tl = 0;
  for (int i = 1; i <= S; i++)
    if (son[0][i]) {
      que[++tl] = son[0][i];
    }
  while (hd <= tl) {
    int u = que[hd];
    hd++;
    addedge(fail[u], u);
    for (int i = 1; i <= S; i++) {
      if (son[u][i]) {
        fail[son[u][i]] = son[fail[u]][i];
        que[++tl] = son[u][i];
      } else {
        son[u][i] = son[fail[u]][i];
      }
    }
  }
}
void dfs(int u) {
  dfn[u] = ++dfnn;
  sz[u] = 1;
  for (int i = fe[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    dfs(v);
    sz[u] += sz[v];
  }
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    acaid[i] = insertstr();
  }
  buildACA();
  dfs(0);
  for (int i = 1; i <= q; i++) {
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x);
    if (l > 1) {
      qr[++m].r = l - 1, qr[m].x = x, qr[m].coe = -1, qr[m].id = i;
    }
    qr[++m].r = r, qr[m].x = x, qr[m].coe = 1, qr[m].id = i;
  }
  sort(qr + 1, qr + m + 1);
  for (int i = 1, j = 1; i <= n; i++) {
    int u = acaid[i];
    while (u != 0) {
      add(dfn[u], 1);
      u = fa[u];
    }
    while (j <= m && qr[j].r == i) {
      u = acaid[qr[j].x];
      ans[qr[j].id] += qr[j].coe * query(dfn[u], dfn[u] + sz[u] - 1);
      j++;
    }
  }
  for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
  return 0;
}
