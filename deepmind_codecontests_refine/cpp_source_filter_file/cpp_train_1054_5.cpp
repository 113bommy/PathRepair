#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, q, fa[N], leaf, rk[N];
long long mn[N * 4], add_tag[N * 4];
int li[N], ri[N];
long long ans[N];
vector<int> ch[N], wi[N];
long long dep[N];
struct query {
  int l, r, id;
};
vector<query> qr[N];
void dfs(int x, long long d) {
  dep[x] = d;
  if (ch[x].size() == 0) {
    rk[++leaf] = x;
    li[x] = ri[x] = leaf;
    return;
  }
  li[x] = n;
  ri[x] = 0;
  for (int i = 0; i < ch[x].size(); ++i) {
    dfs(ch[x][i], d + wi[x][i]);
    li[x] = min(li[x], li[ch[x][i]]);
    ri[x] = max(ri[x], ri[ch[x][i]]);
  }
}
void build(int x, int l, int r) {
  if (l == r) {
    mn[x] = dep[rk[l]];
    return;
  }
  int mid = (l + r) >> 1;
  build((x << 1), l, mid);
  build((x << 1 | 1), mid + 1, r);
  mn[x] = min(mn[(x << 1)], mn[(x << 1 | 1)]);
}
void add(int x, long long v) {
  add_tag[x] += v;
  mn[x] += v;
}
void pd(int x) {
  if (add_tag[x]) {
    add((x << 1), add_tag[x]);
    add((x << 1 | 1), add_tag[x]);
    add_tag[x] = 0;
  }
}
void intv_add(int x, int l, int r, int ql, int qr, long long v) {
  if (ql <= l && r <= qr) {
    add(x, v);
    return;
  }
  int mid = l + r >> 1;
  pd(x);
  if (ql <= mid) intv_add((x << 1), l, mid, ql, qr, v);
  if (qr > mid) intv_add((x << 1 | 1), mid + 1, r, ql, qr, v);
  mn[x] = min(mn[(x << 1)], mn[(x << 1 | 1)]);
}
long long intv_query(int x, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return mn[x];
  int mid = (l + r) >> 1;
  pd(x);
  long long res = 1ll << 60;
  if (ql <= mid) res = min(res, intv_query((x << 1), l, mid, ql, qr));
  if (qr > mid) res = min(res, intv_query((x << 1 | 1), mid + 1, r, ql, qr));
  return res;
}
void solve(int x) {
  for (int i = 0; i < qr[x].size(); ++i) {
    int l = lower_bound(rk + 1, rk + leaf + 1, qr[x][i].l) - rk;
    int r = lower_bound(rk + 1, rk + leaf + 1, qr[x][i].r) - rk;
    ans[qr[x][i].id] = intv_query(1, 1, leaf, l, r);
  }
  for (int i = 0; i < ch[x].size(); ++i) {
    intv_add(1, 1, leaf, li[ch[x][i]], ri[ch[x][i]], -wi[x][i]);
    if (li[ch[x][i]] > 1) intv_add(1, 1, leaf, 1, li[ch[x][i]] - 1, wi[x][i]);
    if (ri[ch[x][i]] < leaf)
      intv_add(1, 1, leaf, ri[ch[x][i]] + 1, leaf, wi[x][i]);
    solve(ch[x][i]);
    intv_add(1, 1, leaf, li[ch[x][i]], ri[ch[x][i]], +wi[x][i]);
    if (li[ch[x][i]] > 1) intv_add(1, 1, leaf, 1, li[ch[x][i]] - 1, -wi[x][i]);
    if (ri[ch[x][i]] < leaf)
      intv_add(1, 1, leaf, ri[ch[x][i]] + 1, leaf, -wi[x][i]);
  }
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 2; i <= n; ++i) {
    int w;
    scanf("%d%d", &fa[i], &w);
    ch[fa[i]].push_back(i);
    wi[fa[i]].push_back(w);
  }
  dfs(1, 0);
  build(1, 1, leaf);
  for (int i = 1; i <= q; ++i) {
    int u, l, r;
    scanf("%d%d%d", &u, &l, &r);
    qr[u].push_back((query){l, r, i});
  }
  solve(1);
  for (int i = 1; i <= q; ++i) cout << ans[i] << endl;
  return 0;
}
