#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
map<int, int> mp;
vector<int> v[N], w[N], ids[N];
int f[N];
int fa[N], dep[N], son[N], top[N], cnt, sz[N], lab[N];
void dfs(int u) {
  sz[u] = 1;
  for (int i = 0; i < v[u].size(); i++) {
    int x = v[u][i];
    if (x == fa[u]) continue;
    fa[x] = u;
    dep[x] = dep[u] + 1;
    dfs(x);
    sz[u] += sz[x];
    if (sz[son[u]] < sz[x]) son[u] = x;
  }
}
void dfs(int u, int tp) {
  top[u] = tp;
  lab[u] = ++cnt;
  if (son[u]) dfs(son[u], tp);
  for (int i = 0; i < v[u].size(); i++) {
    int x = v[u][i];
    if (x != fa[u] && x != son[u]) dfs(x, x);
  }
}
struct tree {
  int lt, rt, sum;
  int ls, rs, dis;
  tree() { dis = -1; }
} a[N << 2];
void init(int lt, int rt, int step) {
  a[step].lt = lt;
  a[step].rt = rt;
  a[step].sum = a[step].ls = a[step].rs = 0;
  a[step].dis = rt - lt + 1;
  if (lt == rt) return;
  int mid = (lt + rt) >> 1;
  init(lt, mid, step << 1);
  init(mid + 1, rt, step << 1 | 1);
}
void merge(tree &a, tree &b, tree &c) {
  a.dis = b.dis + c.dis;
  a.sum = b.sum + c.sum;
  a.ls = b.ls;
  if (b.ls == b.dis) {
    a.ls += c.ls;
  }
  a.rs = c.rs;
  if (c.rs == c.dis) {
    a.rs += b.rs;
  }
  if (b.rs && c.ls) {
    a.sum -= f[b.rs];
    a.sum -= f[c.ls];
    a.sum += f[b.rs + c.ls];
  }
}
void add(int pos, int step) {
  if (a[step].lt == a[step].rt) {
    a[step].sum = f[1];
    a[step].ls = a[step].rs = 1;
    return;
  }
  if (pos <= a[step << 1].rt)
    add(pos, step << 1);
  else
    add(pos, step << 1 | 1);
  merge(a[step], a[step << 1], a[step << 1 | 1]);
}
tree query_tree(int lt, int rt, int step) {
  if (a[step].lt == lt && rt == a[step].rt) return a[step];
  if (rt <= a[step << 1].rt)
    return query_tree(lt, rt, step << 1);
  else if (lt > a[step << 1].rt)
    return query_tree(lt, rt, step << 1 | 1);
  tree ans;
  tree l = query_tree(lt, a[step << 1].rt, step << 1);
  tree r = query_tree(a[step << 1 | 1].lt, rt, step << 1 | 1);
  merge(ans, l, r);
  return ans;
}
int get_ans(int x, int y) {
  tree a, b;
  if (x == y) return 0;
  int fx = top[x], fy = top[y];
  while (fx != fy) {
    if (dep[fx] < dep[fy]) swap(fx, fy), swap(x, y), swap(a, b);
    tree c = query_tree(lab[fx], lab[x], 1);
    tree t;
    if (a.dis == -1)
      t = c;
    else
      merge(t, c, a);
    a = t;
    x = fa[fx];
    fx = top[x];
  }
  if (x == y) {
    if (a.dis == -1 && b.dis == -1) return 0;
    if (b.dis == -1) return a.sum;
    swap(a.ls, a.rs);
    tree ans;
    merge(ans, a, b);
    return ans.sum;
  }
  if (a.dis == -1 && b.dis == -1) {
    if (dep[x] > dep[y]) swap(x, y);
    return query_tree(lab[son[x]], lab[y], 1).sum;
  }
  if (b.dis == -1) {
    tree t, ans;
    if (dep[x] > dep[y]) {
      t = query_tree(lab[son[y]], lab[x], 1);
      merge(ans, t, a);
    } else {
      t = query_tree(lab[son[x]], lab[y], 1);
      swap(t.ls, t.rs);
      merge(ans, t, a);
    }
    return ans.sum;
  }
  tree t, ans;
  if (dep[x] > dep[y]) {
    t = query_tree(lab[son[y]], lab[x], 1);
    tree tmp;
    merge(tmp, t, a);
    swap(tmp.ls, tmp.rs);
    merge(ans, tmp, b);
  } else {
    t = query_tree(lab[son[x]], lab[y], 1);
    tree tmp;
    merge(tmp, t, b);
    swap(tmp.ls, tmp.rs);
    merge(ans, tmp, a);
  }
  return ans.sum;
}
struct query {
  int u, v, w, id;
  void read(int _id) {
    id = _id;
    scanf("%d%d%d", &u, &v, &w);
  }
  friend bool operator<(const query &a, const query &b) { return a.w > b.w; }
} qry[N];
int ans[N];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; i++) scanf("%d", &f[i]);
  for (int i = 1; i < n; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    v[x].push_back(y);
    v[y].push_back(x);
    w[x].push_back(z);
    w[y].push_back(z);
    mp[z] = 1;
  }
  for (int i = 1; i <= m; i++) {
    qry[i].read(i);
    mp[qry[i].w] = 1;
  }
  int idx = 0;
  for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
    it->second = ++idx;
  dfs(1);
  dfs(1, 1);
  init(1, n, 1);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < v[i].size(); j++)
      if (fa[i] == v[i][j]) {
        ids[mp[w[i][j]]].push_back(i);
      }
  sort(qry + 1, qry + m + 1);
  for (int i = 1, j = idx; i <= m; i++) {
    idx = mp[qry[i].w];
    while (j >= idx) {
      for (int k = 0; k < ids[j].size(); k++) {
        int pos = lab[ids[j][k]];
        add(pos, 1);
      }
      j--;
    }
    ans[qry[i].id] = get_ans(qry[i].u, qry[i].v);
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
