#include <bits/stdc++.h>
using namespace std;
int get() {
  char ch;
  while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-')
    ;
  if (ch == '-') {
    int s = 0;
    while (ch = getchar(), ch >= '0' && ch <= '9') s = s * 10 + ch - '0';
    return -s;
  }
  int s = ch - '0';
  while (ch = getchar(), ch >= '0' && ch <= '9') s = s * 10 + ch - '0';
  return s;
}
const int N = 2e5 + 5;
const int T = 20;
int dfn[T][N], d[T][N], k;
int num[N];
int n;
int a[N], to[N];
int fa[N], lef[N], rig[N];
int fir[N], dep[N], u;
int rmq[N * 2][20];
int Dfn[N], D[N];
void dfs1(int x) {
  D[Dfn[x] = dfn[T - 1][x]] = x;
  rmq[fir[x] = ++u][0] = x;
  for (int y = lef[x]; y; y = rig[y]) {
    dep[y] = dep[x] + 1;
    dfs1(y);
    rmq[++u][0] = x;
  }
}
int lg[N * 2];
void getrmq() {
  for (int j = 1; j <= log(u) / log(2); j++)
    for (int i = 1; i <= u - (1 << j) + 1; i++)
      rmq[i][j] = dep[rmq[i][j - 1]] < dep[rmq[i + (1 << (j - 1))][j - 1]]
                      ? rmq[i][j - 1]
                      : rmq[i + (1 << (j - 1))][j - 1];
  for (int i = 1; i <= u; i++) lg[i] = log(i) / log(2);
}
int lca(int x, int y) {
  x = fir[x], y = fir[y];
  if (x > y) swap(x, y);
  int t = lg[y - x + 1];
  return dep[rmq[x][t]] < dep[rmq[y - (1 << t) + 1][t]]
             ? rmq[x][t]
             : rmq[y - (1 << t) + 1][t];
}
void dfs(int x, int t) {
  d[t][dfn[t][x] = ++k] = x;
  for (int y = lef[x]; y; y = rig[y]) dfs(y, t);
}
void getdfn(int t) {
  k = 0;
  random_shuffle(num + 1, num + 1 + n);
  for (int i = 1; i <= n; i++) lef[i] = rig[i] = 0;
  for (int i = 1; i <= n; i++) {
    int x = num[i];
    if (fa[x]) {
      rig[x] = lef[fa[x]];
      lef[fa[x]] = x;
    }
  }
  dfs(1, t);
}
struct node {
  int a[T];
  int tp;
  int& operator[](int x) { return a[x]; }
} sgt[N * 2];
void build(int now, int l, int r) {
  if (l == r) {
    int x = to[l];
    for (int i = 0; i <= T - 1; i++) sgt[now][i] = dfn[i][x];
    sgt[now].tp = Dfn[x];
    return;
  }
  int mid = (l + r) / 2;
  int ls = now + 1, rs = now + (mid - l + 1) * 2;
  build(ls, l, mid);
  build(rs, mid + 1, r);
  for (int i = 0; i <= T - 1; i++) sgt[now][i] = max(sgt[ls][i], sgt[rs][i]);
  sgt[now].tp = min(sgt[ls].tp, sgt[rs].tp);
}
void change(int now, int l, int r, int x) {
  if (l == r) {
    int w = to[l];
    for (int i = 0; i <= T - 1; i++) sgt[now][i] = dfn[i][w];
    sgt[now].tp = Dfn[w];
    return;
  }
  int mid = (l + r) / 2;
  int ls = now + 1, rs = now + (mid - l + 1) * 2;
  if (x <= mid)
    change(ls, l, mid, x);
  else
    change(rs, mid + 1, r, x);
  for (int i = 0; i <= T - 1; i++) sgt[now][i] = max(sgt[ls][i], sgt[rs][i]);
  sgt[now].tp = min(sgt[ls].tp, sgt[rs].tp);
}
int tp;
int key[T];
int getans(int now, int l, int r) {
  int tp_ = min(tp, sgt[now].tp);
  int fi = 0, se = 0;
  for (int i = 0; i <= T - 1; i++) {
    int x = d[i][max(key[i], sgt[now][i])];
    if (x == fi || x == se) continue;
    if (!fi)
      fi = x;
    else {
      if (!se)
        se = x;
      else {
        fi = -1;
        break;
      }
    }
  }
  if (fi != -1) {
    if (!se || (se && dep[lca(fi, se)] <= dep[D[tp_]])) {
      tp = tp_;
      for (int i = 0; i <= T - 1; i++) key[i] = max(key[i], sgt[now][i]);
      return r;
    }
  }
  if (l == r) return l - 1;
  int mid = (l + r) / 2;
  int ls = now + 1, rs = now + (mid - l + 1) * 2;
  int ret = getans(ls, l, mid);
  if (ret == mid) return getans(rs, mid + 1, r);
  return ret;
}
int main() {
  srand(2478789);
  n = get();
  for (int i = 1; i <= n; i++) to[a[i] = get() + 1] = i;
  for (int i = 2; i <= n; i++) fa[i] = get();
  for (int i = 1; i <= n; i++) num[i] = i;
  for (int t = 0; t <= T - 1; t++) getdfn(t);
  dfs1(dep[1] = 1);
  getrmq();
  build(1, 1, n);
  for (int _ = get(); _; _--) {
    int ty = get();
    if (ty == 1) {
      int x = get(), y = get();
      swap(a[x], a[y]);
      to[a[x]] = x;
      to[a[y]] = y;
      change(1, 1, n, a[x]);
      change(1, 1, n, a[y]);
    } else {
      tp = 1e9;
      for (int i = 0; i <= T - 1; i++) key[i] = 0;
      printf("%d\n", getans(1, 1, n));
    }
  }
  return 0;
}
