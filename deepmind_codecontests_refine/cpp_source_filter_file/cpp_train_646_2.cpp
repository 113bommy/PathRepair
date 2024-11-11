#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 19;
int n, m, k, cnt, idx, tail;
int u[N], v[N], zl[N << 6][2], sum[N << 6], sbs[N], rots[N], root[N],
    wsdj[N][M], grad[N], lnths[N], xzbh[N], lllnt[N];
long long pyt;
vector<int> gtmrr[N], stcka[N];
struct sidess {
  int v, next;
} sidesss[N << 1];
namespace doubll {
int sum[N << 2] = {0};
void add(int p, int x) {
  if (p == 0) return;
  while (p <= n) {
    sum[p] += x;
    p += p & -p;
  }
}
int query(int p) {
  int pyt = 0;
  while (p > 0) {
    pyt += sum[p];
    p -= p & -p;
  }
  return pyt;
}
void Add(int l, int r) {
  add(l, 1);
  add(r + 1, -1);
}
}  // namespace doubll
void add_edge(int u, int v);
void lllrwl(int x);
int insert(int rt, int l, int r, int p);
int merge(int u, int v);
int query(int rt, int L, int R, int l, int r);
void srcs1(int u, int f);
void srcs(int u);
int getup(int u, int x);
int lca(int u, int v) {
  if (lnths[u] < lnths[v]) swap(u, v);
  for (int i = M - 1; i >= 0; i--)
    if (lnths[wsdj[u][i]] >= lnths[v]) u = wsdj[u][i];
  if (u == v) return u;
  for (int i = M - 1; i >= 0; i--)
    if (wsdj[u][i] != wsdj[v][i]) {
      u = wsdj[u][i];
      v = wsdj[v][i];
    }
  return wsdj[u][0];
}
void dfs3(int x, int rt) {
  sbs[x] = x;
  root[x] = 0;
  for (int i = 0; i < gtmrr[x].size(); i++) {
    int d = gtmrr[x][i];
    int rd = max(0, k - (lnths[u[d]] - lnths[rt]));
    if (lnths[v[d]] - lnths[rt] >= rd) {
      int l = getup(v[d], lnths[v[d]] - lnths[rt] - rd);
      pyt += query(root[x], 1, n, xzbh[l], xzbh[l] + lllnt[l] - 1);
    }
    root[x] = insert(root[x], 1, n, xzbh[v[d]]);
  }
  for (int i = rots[x]; i; i = sidesss[i].next) {
    int t = sidesss[i].v;
    if (t == wsdj[x][0] || (rt == x && t == grad[x])) continue;
    dfs3(t, rt);
    if (gtmrr[sbs[x]].size() < gtmrr[sbs[t]].size()) {
      swap(sbs[x], sbs[t]);
      swap(root[x], root[t]);
    }
    while (!gtmrr[sbs[t]].empty()) {
      int d = gtmrr[sbs[t]][gtmrr[sbs[t]].size() - 1];
      gtmrr[sbs[t]].pop_back();
      int rd = max(0, k - (lnths[x] - lnths[rt]));
      if (lnths[v[d]] - lnths[rt] >= rd) {
        int l = getup(v[d], (lnths[v[d]] - lnths[rt] - rd));
        pyt += query(root[x], 1, n, xzbh[l], xzbh[l] + lllnt[l] - 1);
      }
      gtmrr[sbs[x]].push_back(d);
    }
    root[x] = merge(root[x], root[t]);
  }
  return;
}
void dfs2(int x) {
  int len = stcka[x].size();
  for (int i = rots[x]; i; i = sidesss[i].next)
    if (sidesss[i].v != wsdj[x][0]) dfs2(sidesss[i].v);
  for (int i = 0; i < len; i++) pyt += doubll::query(xzbh[v[stcka[x][i]]]);
  for (int i = 0; i < len; i++) {
    int j = stcka[x][i];
    if (lnths[v[j]] - lnths[x] >= k) {
      int l = getup(v[j], lnths[v[j]] - lnths[x] - k);
      doubll::Add(xzbh[l], xzbh[l] + lllnt[l] - 1);
    }
  }
  for (int i = 0; i < len; i++) {
    pyt += doubll::query(xzbh[u[stcka[x][i]]]);
    gtmrr[u[stcka[x][i]]].push_back(stcka[x][i]);
  }
  dfs3(x, x);
  while (!gtmrr[sbs[x]].empty()) gtmrr[sbs[x]].pop_back();
  for (int i = 0; i < len; i++) {
    int j = stcka[x][i];
    if (lnths[u[j]] - lnths[x] >= k) {
      int l = getup(u[j], lnths[u[j]] - lnths[x] - k);
      doubll::Add(xzbh[l], xzbh[l] + lllnt[l] - 1);
    }
  }
}
int uu, vv;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &uu, &vv);
    add_edge(uu, vv);
    add_edge(vv, uu);
  }
  srcs1(1, 0);
  srcs(1);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &u[i], &v[i]);
    if (xzbh[u[i]] > xzbh[v[i]]) swap(u[i], v[i]);
    int l = lca(u[i], v[i]);
    stcka[l].push_back(i);
  }
  dfs2(1);
  cout << pyt - 1;
  return 0;
}
void add_edge(int u, int v) {
  sidesss[++tail].v = v;
  sidesss[tail].next = rots[u];
  rots[u] = tail;
  return;
}
void lllrwl(int x) {
  sum[x] = sum[zl[x][0]] + sum[zl[x][1]];
  return;
}
int insert(int rt, int l, int r, int p) {
  if (!rt) rt = ++cnt;
  if (l == r) {
    sum[rt]++;
    return rt;
  }
  int mid = (l + r) >> 1;
  if (p <= mid)
    zl[rt][0] = insert(zl[rt][0], l, mid, p);
  else
    zl[rt][1] = insert(zl[rt][1], mid + 1, r, p);
  lllrwl(rt);
  return rt;
}
int merge(int u, int v) {
  if (!u || !v) return u + v;
  zl[u][0] = merge(zl[u][0], zl[v][0]);
  zl[u][1] = merge(zl[u][1], zl[v][1]);
  sum[u] = sum[u] + sum[v];
  return u;
}
int query(int rt, int L, int R, int l, int r) {
  if (l > R || r < L) return 0;
  if (l <= L && R <= r) return sum[rt];
  return query(zl[rt][0], L, (L + R) >> 1, l, r) +
         query(zl[rt][1], ((L + R) >> 1) + 1, R, l, r);
}
void srcs1(int u, int f) {
  wsdj[u][0] = f;
  lnths[u] = lnths[f] + 1;
  lllnt[u] = 1;
  for (int i = 1; i < M; i++) wsdj[u][i] = wsdj[wsdj[u][i - 1]][i - 1];
  for (int i = rots[u]; i; i = sidesss[i].next) {
    int v = sidesss[i].v;
    if (v == f) continue;
    srcs1(v, u);
    lllnt[u] += lllnt[v];
    if (lllnt[v] > lllnt[grad[u]]) grad[u] = v;
  }
  return;
}
void srcs(int u) {
  xzbh[u] = ++idx;
  for (int i = rots[u]; i; i = sidesss[i].next) {
    int v = sidesss[i].v;
    if (v == grad[u] || v == wsdj[u][0]) continue;
    srcs(v);
  }
  if (grad[u]) srcs(grad[u]);
  return;
}
int getup(int u, int x) {
  for (int i = M - 1; i >= 0; i--)
    if (x >= (1 << i)) {
      u = wsdj[u][i];
      x -= (1 << i);
    }
  return u;
}
