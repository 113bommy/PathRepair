#include <bits/stdc++.h>
using namespace std;
const int N = 303000;
int headp[N], nextp[N], a[N], to[N], n, m, leftp[N], rightp[N], num[N], dfsnum,
    p[N][24], root, dep[N];
long long tag[N << 2], sum[N << 2];
inline void addedge(int x, int y, int &tot) {
  to[tot] = y;
  nextp[tot] = headp[x];
  headp[x] = tot;
  ++tot;
}
void dfs(int x) {
  ++dfsnum;
  leftp[x] = dfsnum;
  num[dfsnum] = x;
  for (int i = headp[x]; i != -1; i = nextp[i]) {
    int y = to[i];
    if (y == p[x][0]) continue;
    p[y][0] = x;
    dep[y] = dep[x] + 1;
    dfs(y);
  }
  rightp[x] = dfsnum;
}
void build(int o, int ll, int rr) {
  if (ll == rr) {
    sum[o] = a[num[ll]];
    return;
  }
  int mid = (ll + rr) >> 1, lch = o << 1, rch = lch + 1;
  build(lch, ll, mid);
  build(rch, mid + 1, rr);
  sum[o] = sum[lch] + sum[rch];
}
void ins(int o, int ll, int rr, int l, int r, int x) {
  if (ll == l && rr == r) {
    tag[o] += x;
    sum[o] += (1LL + rr - ll) * x;
    return;
  }
  int mid = (ll + rr) >> 1, lch = o << 1, rch = lch + 1;
  if (tag[o]) {
    tag[lch] += tag[o];
    sum[lch] += (1LL + mid - ll) * tag[o];
    tag[rch] += tag[o];
    sum[rch] += (1LL + rr - mid - 1LL) * tag[o];
    tag[o] = 0;
  }
  if (r <= mid)
    ins(lch, ll, mid, l, r, x);
  else if (l > mid)
    ins(rch, mid + 1, rr, l, r, x);
  else {
    ins(lch, ll, mid, l, mid, x);
    ins(rch, mid + 1, rr, mid + 1, r, x);
  }
  sum[o] = sum[lch] + sum[rch];
}
long long query(int o, int ll, int rr, int l, int r) {
  if (ll == l && rr == r) {
    return sum[o];
  }
  int mid = (ll + rr) >> 1, lch = o << 1, rch = lch + 1;
  if (tag[o]) {
    tag[lch] += tag[o];
    sum[lch] += (1LL + mid - ll) * tag[o];
    tag[rch] += tag[o];
    sum[rch] += (1LL + rr - mid - 1LL) * tag[o];
    tag[o] = 0;
  }
  long long ans;
  if (r <= mid)
    ans = query(lch, ll, mid, l, r);
  else if (l > mid)
    ans = query(rch, mid + 1, rr, l, r);
  else {
    ans = query(lch, ll, mid, l, mid) + query(rch, mid + 1, rr, mid + 1, r);
  }
  return ans;
}
int lca(int x, int y) {
  if (x == y) return x;
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 23; i >= 0; --i)
    if ((1 << i) <= dep[x] - dep[y]) x = p[x][i];
  if (x == y) return x;
  for (int i = 23; i >= 0; --i)
    if (p[x][i] != p[y][i]) {
      x = p[x][i];
      y = p[y][i];
    }
  return p[x][0];
}
int main() {
  memset(headp, -1, sizeof(headp));
  memset(nextp, -1, sizeof(nextp));
  int tot = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    addedge(x, y, tot);
    addedge(y, x, tot);
  }
  dfsnum = 0;
  p[1][0] = 1;
  dep[1] = 1;
  dfs(1);
  for (int i = 1; i < 24; ++i)
    for (int j = 1; j <= n; ++j) p[j][i] = p[p[j][i - 1]][i - 1];
  root = 1;
  memset(tag, 0, sizeof(tag));
  build(1, 1, n);
  for (int qq = 0; qq < m; ++qq) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d", &root);
    } else if (op == 2) {
      int u, v, x;
      scanf("%d%d%d", &u, &v, &x);
      int uv = lca(u, v), vr = lca(v, root), ur = lca(u, root),
          uvr = lca(uv, root);
      if (uvr == root)
        ins(1, 1, n, 1, n, x);
      else if (dep[uv] > dep[uvr])
        ins(1, 1, n, leftp[uv], rightp[uv], x);
      else if (vr == uv && vr == ur) {
        int temp = root;
        for (int i = 23; i >= 0; --i)
          if ((1 << i) < dep[temp] - dep[uv]) temp = p[temp][i];
        if (leftp[temp] > 1) ins(1, 1, n, 1, leftp[temp] - 1, x);
        if (rightp[temp] < n) ins(1, 1, n, rightp[temp] + 1, n, x);
      } else if (dep[ur] > dep[vr]) {
        if (root == ur)
          ins(1, 1, n, 1, n, x);
        else {
          int temp = root;
          for (int i = 23; i >= 0; --i)
            if ((1 << i) < dep[temp] - dep[ur]) temp = p[temp][i];
          if (leftp[temp] > 1) ins(1, 1, n, 1, leftp[temp] - 1, x);
          if (rightp[temp] < n) ins(1, 1, n, rightp[temp] + 1, n, x);
        }
      } else if (dep[ur] < dep[vr]) {
        if (root == vr)
          ins(1, 1, n, 1, n, x);
        else {
          int temp = root;
          for (int i = 23; i >= 0; --i)
            if ((1 << i) < dep[temp] - dep[vr]) temp = p[temp][i];
          if (leftp[temp] > 1) ins(1, 1, n, 1, leftp[temp] - 1, x);
          if (rightp[temp] < n) ins(1, 1, n, rightp[temp] + 1, n, x);
        }
      }
    } else {
      int v, vr;
      scanf("%d", &v);
      vr = lca(v, root);
      if (v == root) {
        printf("%lld\n", query(1, 1, n, 1, n));
      } else if (vr == v) {
        int temp = root;
        for (int i = 23; i >= 0; --i)
          if ((1 << i) < dep[temp] - dep[v]) temp = p[temp][i];
        long long ans = 0;
        if (leftp[temp] > 1) ans += query(1, 1, n, 1, leftp[temp] - 1);
        if (rightp[temp] < n) ans += query(1, 1, n, rightp[temp] + 1, n);
        printf("%lld\n", ans);
      } else {
        printf("%lld\n", query(1, 1, n, leftp[v], rightp[v]));
      }
    }
  }
}
