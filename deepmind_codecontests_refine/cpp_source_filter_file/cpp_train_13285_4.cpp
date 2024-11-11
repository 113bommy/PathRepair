#include <bits/stdc++.h>
using namespace std;
const int N = 100010, M = 269000;
const int blc = 90;
const int root = 1;
int fa[N][18];
int dep[N];
int ch[N][26];
int tot = 1;
int len[N], lcp[N], p[N];
int a[N], cnt;
int father[N], L[N], R[N], vis[N];
int n;
char str[N];
struct SEG1 {
  int seg[M];
  inline void update(int node) {
    seg[node] = max(seg[node << 1], seg[node << 1 | 1]);
  }
  void build(int node, int l, int r) {
    if (l == r) {
      seg[node] = len[l];
      return;
    }
    int mid = l + r >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    update(node);
  }
  void cg(int node, int l, int r, int x, int w) {
    if (l > x || r < x) return;
    if (l == r) {
      seg[node] = w;
      return;
    }
    int mid = l + r >> 1;
    cg(node << 1, l, mid, x, w);
    cg(node << 1 | 1, mid + 1, r, x, w);
    update(node);
  }
  int query(int node, int l, int r, int fl, int fr) {
    if (fl <= l && r <= fr) return seg[node];
    int mid = l + r >> 1;
    if (mid >= fr)
      return query(node << 1, l, mid, fl, fr);
    else if (mid + 1 <= fl)
      return query(node << 1 | 1, mid + 1, r, fl, fr);
    else
      return max(query(node << 1, l, mid, fl, fr),
                 query(node << 1 | 1, mid + 1, r, fl, fr));
  }
};
struct data {
  int ls, rs, ans;
  data() {}
  data(int ls, int rs, int ans) : ls(ls), rs(rs), ans(ans) {}
};
data cur;
struct SEG2 {
  data seg[M];
  bool ok[M];
  inline void update(int node) {
    ok[node] = ok[node << 1] && ok[node << 1 | 1];
    seg[node].ls = ok[node << 1] ? seg[node << 1].ls + seg[node << 1 | 1].ls
                                 : seg[node << 1].ls;
    seg[node].rs = ok[node << 1 | 1] ? seg[node << 1 | 1].rs + seg[node << 1].rs
                                     : seg[node << 1 | 1].rs;
    seg[node].ans = max(seg[node << 1].rs + seg[node << 1 | 1].ls,
                        max(seg[node << 1].ans, seg[node << 1 | 1].ans));
  }
  void cg(int node, int l, int r, int x, int w) {
    if (l > x || r < x) return;
    if (l == r) {
      seg[node].ls = seg[node].rs = seg[node].ans = ok[node] = w;
      return;
    }
    int mid = l + r >> 1;
    cg(node << 1, l, mid, x, w);
    cg(node << 1 | 1, mid + 1, r, x, w);
    update(node);
  }
  void query(int node, int l, int r, int fl, int fr) {
    if (l > fr || r < fl) return;
    if (fl <= l && r <= fr) {
      cur.ans = max(cur.ans, max(seg[node].ans, cur.rs + seg[node].ls));
      cur.rs = ok[node] ? seg[node].rs + cur.rs : seg[node].rs;
      return;
    }
    int mid = l + r >> 1;
    query(node << 1, l, mid, fl, fr);
    query(node << 1 | 1, mid + 1, r, fl, fr);
  }
};
SEG2 s[blc + 1];
SEG1 S;
int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  int i, delta = dep[x] - dep[y];
  for (i = 0; i <= 17; i++)
    if (1 << i & delta) x = fa[x][i];
  if (x == y) return dep[x];
  for (i = 17; i >= 0; i--)
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  return dep[fa[x][0]];
}
void insert(int id) {
  scanf("%s", str + 1);
  len[id] = strlen(str + 1);
  int x = root, i, j;
  for (i = 1; i <= len[id]; i++) {
    if (!ch[x][str[i] - 'a']) {
      ch[x][str[i] - 'a'] = ++tot;
      dep[tot] = dep[x] + 1;
      fa[tot][0] = x;
      for (j = 1; j <= 17; j++) fa[tot][j] = fa[fa[tot][j - 1]][j - 1];
    }
    x = ch[x][str[i] - 'a'];
  }
  p[id] = x;
}
bool cmp(int x, int y) { return lcp[x] < lcp[y]; }
void erase(int id) {
  register int i, j;
  for (i = 1; i <= cnt; i++)
    if (a[i] == id) break;
  for (j = i + 1; j <= cnt; j++) a[j - 1] = a[j];
  cnt--;
}
void add(int id) {
  register int i;
  a[++cnt] = id;
  for (i = cnt - 1; i; i--)
    if (lcp[a[i]] > lcp[a[i + 1]]) swap(a[i], a[i + 1]);
}
void work(int id) {
  int pre, now;
  register int i;
  pre = lcp[id];
  now = lcp[id] = lca(p[id], p[id + 1]);
  if (pre > blc) erase(id);
  if (now > blc) add(id);
  if (pre < now)
    for (i = min(blc, pre) + 1; i <= min(blc, now); i++)
      s[i].cg(1, 1, n - 1, id, 1);
  if (now < pre)
    for (i = min(now, blc) + 1; i <= min(blc, pre); i++)
      s[i].cg(1, 1, n - 1, id, 0);
}
int find(int x) {
  if (father[x] != x) father[x] = find(father[x]);
  return x;
}
int main() {
  int j, Q, opt, l, r, x, ans;
  register int i;
  scanf("%d%d", &n, &Q);
  for (i = 1; i <= n; i++) insert(i);
  S.build(1, 1, n);
  for (i = 1; i <= n - 1; i++) lcp[i] = lca(p[i], p[i + 1]);
  for (i = 1; i <= n - 1; i++) {
    for (j = 1; j <= min(blc, lcp[i]); j++) s[j].cg(1, 1, n - 1, i, 1);
    if (lcp[i] > blc) a[++cnt] = i;
  }
  sort(a + 1, a + 1 + cnt, cmp);
  for (i = 1; i <= n; i++) father[i] = L[i] = R[i] = i, vis[i] = 0;
  while (Q--) {
    scanf("%d", &opt);
    if (opt == 1) {
      scanf("%d%d", &l, &r);
      ans = S.query(1, 1, n, l, r);
      if (l == r) {
        printf("%d\n", ans);
        continue;
      }
      for (i = 1; i <= blc; i++) {
        cur = data(0, 0, 0);
        s[i].query(1, 1, n - 1, l, r - 1);
        if (cur.ans) ans = max(ans, i * (cur.ans + 1));
      }
      for (i = cnt; i; i--)
        if (l <= a[i] && a[i] <= r - 1) {
          vis[a[i]] = 1;
          if (a[i] > l && vis[a[i] - 1]) {
            x = find(a[i] - 1);
            father[x] = a[i];
            L[a[i]] = L[x];
          }
          if (a[i] < r - 1 && vis[a[i] + 1]) {
            x = find(a[i] + 1);
            father[x] = a[i];
            R[a[i]] = R[x];
          }
          ans = max(ans, (R[a[i]] - L[a[i]] + 2) * lcp[a[i]]);
        }
      for (i = cnt; i; i--) {
        vis[a[i]] = 0;
        father[a[i]] = L[a[i]] = R[a[i]] = a[i];
      }
      printf("%d\n", ans);
    }
    if (opt == 2) {
      scanf("%d", &x);
      insert(x);
      S.cg(1, 1, n, x, len[x]);
      if (x > 1) work(x - 1);
      if (x < n) work(x);
    }
  }
}
