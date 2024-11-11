#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkmax(T &x, T y) {
  x = x > y ? x : y;
}
template <typename T>
void chkmin(T &x, T y) {
  x = x > y ? y : x;
}
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  x *= f;
}
struct Edge {
  int next, num;
} e[200010 * 3];
struct SegmentTree {
  struct Node {
    int lc, rc, cnt;
  } t[200010 * 30];
  int tot;
  void ins(int &rt, int k, int l, int r, int x) {
    rt = ++tot, t[rt] = t[k], t[rt].cnt++;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (x <= mid)
      ins(t[rt].lc, t[k].lc, l, mid, x);
    else
      ins(t[rt].rc, t[k].rc, mid + 1, r, x);
  }
  int query(int k1, int k2, int l, int r, int L, int R) {
    if (L <= l && r <= R) return t[k2].cnt - t[k1].cnt;
    int mid = (l + r) >> 1, ret = 0;
    if (L <= mid) ret += query(t[k1].lc, t[k2].lc, l, mid, L, R);
    if (R > mid) ret += query(t[k1].rc, t[k2].rc, mid + 1, r, L, R);
    return ret;
  }
} T;
vector<int> a[200010], b[200010];
int n, cnt, Time, d[200010], rt[200010 * 2], las[200010], dfn[200010],
    siz[200010], f[200010][21], p[200010][21];
void add(int x, int y) {
  e[++cnt] = (Edge){e[x].next, y};
  e[x].next = cnt;
}
void dfs(int x, int fa) {
  d[x] = d[fa] + 1, dfn[x] = ++Time, siz[x] = 1;
  for (int i = 1; i <= 20; i++) f[x][i] = f[f[x][i - 1]][i - 1];
  for (int p = e[x].next; p; p = e[p].next) {
    int k = e[p].num;
    f[k][0] = x;
    dfs(k, x);
    siz[x] += siz[k];
  }
}
int lca(int x, int y) {
  if (d[x] < d[y]) swap(x, y);
  for (int i = 20; ~i; i--)
    if (d[f[x][i]] >= d[y]) x = f[x][i];
  if (x == y) return x;
  for (int i = 20; ~i; i--)
    if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
  return f[x][0];
}
void work(int x) {
  p[x][0] = x;
  for (int q = e[x].next; q; q = e[q].next) {
    int k = e[q].num;
    work(k);
    if (d[p[k][0]] < d[p[x][0]]) p[x][0] = p[k][0];
  }
  for (int i = 0; i < a[x].size(); i++) {
    int k = a[x][i];
    if (d[k] < d[p[x][0]]) p[x][0] = k;
  }
}
int main() {
  read(n);
  cnt = n;
  for (int i = 2; i <= n; i++) {
    int x;
    read(x);
    add(x, i);
  }
  dfs(1, 0);
  int m;
  read(m);
  for (int i = 1; i <= m; i++) {
    int x, y, z;
    read(x), read(y);
    z = lca(x, y);
    a[x].push_back(z), a[y].push_back(z);
    b[dfn[x]].push_back(dfn[y]);
    b[dfn[y]].push_back(dfn[x]);
  }
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    if (!b[i].size()) {
      las[i] = tot;
      continue;
    }
    for (int j = 0; j < b[i].size(); j++) {
      int k = b[i][j], tmp = tot;
      T.ins(rt[++tot], rt[tmp], 1, n, k);
      las[i] = tot;
    }
  }
  work(1);
  for (int j = 1; j <= 20; j++)
    for (int i = 1; i <= n; i++) p[i][j] = p[p[i][j - 1]][j - 1];
  int q;
  read(q);
  while (q--) {
    int x, y, fx = 0, fy = 0;
    read(x), read(y);
    int z = lca(x, y), ans = 0;
    if (x == z || y == z) {
      if (d[x] < d[y]) swap(x, y);
      for (int i = 20; ~i; i--) {
        if (d[p[x][i]] <= d[z] && p[x][i]) fx = 1;
        if (d[p[x][i]] > d[z]) x = p[x][i], ans += 1 << i;
      }
      x = p[x][0], ans++;
      if (d[x] <= d[y])
        cout << ans << "\n";
      else
        cout << "-1\n";
      continue;
    }
    for (int i = 20; ~i; i--) {
      if (d[p[x][i]] <= d[z] && p[x][i]) fx = 1;
      if (d[p[x][i]] > d[z]) x = p[x][i], ans += 1 << i;
    }
    for (int i = 20; ~i; i--) {
      if (d[p[y][i]] <= d[z] && p[y][i]) fy = 1;
      if (d[p[y][i]] > d[z]) y = p[y][i], ans += 1 << i;
    }
    if (!fx || !fy) {
      cout << "-1\n";
      continue;
    }
    ans++;
    int l1 = dfn[x], r1 = l1 + siz[x] - 1, l2 = dfn[y], r2 = l2 + siz[y] - 1;
    if (!T.query(rt[las[l1 - 1]], rt[las[r1]], 1, n, l2, r2)) ans++;
    cout << ans << "\n";
  }
  return 0;
}
