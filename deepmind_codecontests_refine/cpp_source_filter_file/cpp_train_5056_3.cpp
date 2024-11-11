#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int a[maxn];
int ancenstor[maxn][19];
long long dist2a[maxn][19];
int head[maxn];
int Next[maxn * 2];
int to[maxn * 2];
int siz[maxn];
int dep[maxn];
int top[maxn];
int fa[maxn];
int son[maxn];
int w[maxn];
int w_1[maxn];
bool vis[maxn];
int pos;
int End;
int n, m, p;
void init(int n) {
  for (int i = 1; i <= n; i++) {
    siz[i] = top[i] = son[i] = 0;
    dep[i] = w[i] = w_1[i] = fa[i] = 0;
    head[i] = -1;
  }
  pos = 0;
  End = 0;
}
void addedge(int u, int v) {
  to[End] = v, Next[End] = head[u], head[u] = End++;
  to[End] = u, Next[End] = head[v], head[v] = End++;
}
void dfs1(int x, int pre) {
  vis[x] = 1;
  dep[x] = dep[pre] + 1;
  fa[x] = pre;
  for (int i = head[x]; i != -1; i = Next[i]) {
    if (to[i] == pre) continue;
    if (vis[to[i]]) continue;
    dfs1(to[i], x);
    siz[x] += siz[to[i]];
    if (son[x] == 0)
      son[x] = to[i];
    else if (siz[son[x]] < siz[to[i]])
      son[x] = to[i];
  }
  siz[x]++;
}
void dfs2(int x, int pre) {
  vis[x] = 1;
  pos++;
  w[x] = pos;
  w_1[pos] = x;
  if (son[fa[x]] == x)
    top[x] = top[fa[x]];
  else
    top[x] = x;
  if (son[x] == 0) return;
  dfs2(son[x], x);
  for (int i = head[x]; i != -1; i = Next[i]) {
    if (to[i] == pre) continue;
    if (to[i] == son[x]) continue;
    if (vis[to[i]]) continue;
    dfs2(to[i], x);
  }
}
struct node {
  int l, r;
  int val;
  int lazy;
};
node tree[maxn << 2];
void build_tree(int n, int l, int r) {
  tree[n].l = l;
  tree[n].r = r;
  tree[n].val = tree[n].lazy = 0;
  if (l == r) {
    return;
  }
  int mid = (l + r) >> 1;
  build_tree(n << 1, l, mid);
  build_tree((n << 1) | 1, mid + 1, r);
}
void push_down(int x) {
  int& add = tree[x].lazy;
  node& lch = tree[x << 1];
  node& rch = tree[(x << 1) | 1];
  if (lch.l == lch.r)
    lch.val += add;
  else
    lch.lazy += add;
  if (rch.l == rch.r)
    rch.val += add;
  else
    rch.lazy += add;
  add = 0;
}
void update(int n, int l, int r, int v) {
  if (tree[n].l == l && tree[n].r == r) {
    if (l == r) {
      tree[n].val += v;
    } else {
      tree[n].lazy += v;
    }
    return;
  }
  if (tree[n].lazy) push_down(n);
  int mid = (tree[n].l + tree[n].r) >> 1;
  if (r <= mid) {
    update(n << 1, l, r, v);
  } else {
    if (l > mid) {
      update((n << 1) | 1, l, r, v);
    } else {
      update(n << 1, l, mid, v);
      update((n << 1) | 1, mid + 1, r, v);
    }
  }
}
int query(int n, int pos) {
  if (tree[n].l == tree[n].r) return tree[n].val;
  if (tree[n].lazy) push_down(n);
  int mid = (tree[n].l + tree[n].r) >> 1;
  if (pos <= mid)
    return query(n << 1, pos);
  else
    return query((n << 1) | 1, pos);
}
void fun(int u, int v) {
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    update(1, w[top[u]], w[u], 1);
    u = fa[top[u]];
  }
  if (w[u] > w[v]) swap(u, v);
  update(1, w[u], w[v], 1);
}
int main() {
  int n;
  cin >> n;
  init(n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 2; i <= n; i++) {
    scanf("%d %d", &ancenstor[i][0], &dist2a[i][0]);
    addedge(ancenstor[i][0], i);
  }
  for (int t = 1; t < 19; t++) {
    for (int i = 1; i <= n; i++) {
      ancenstor[i][t] = ancenstor[ancenstor[i][t - 1]][t - 1];
      dist2a[i][t] = dist2a[i][t - 1] + dist2a[ancenstor[i][t - 1]][t - 1];
    }
  }
  memset(vis, 0, sizeof(vis));
  dfs1(1, 0);
  memset(vis, 0, sizeof(vis));
  dfs2(1, 0);
  build_tree(1, 1, n);
  for (int i = 1; i <= n; i++) {
  }
  for (int i = 2; i <= n; i++) {
    int u = i;
    long long weight = a[i];
    for (int k = 0;; k++) {
      if (dist2a[u][k] > weight) {
        if (k == 0) {
          break;
        } else {
          weight -= dist2a[u][k - 1];
          u = ancenstor[u][k - 1];
          k -= 2;
          continue;
        }
      }
      if (ancenstor[u][k] == 0) {
        u = 1;
        break;
      }
    }
    if (i != u) {
      fun(u, ancenstor[i][0]);
    }
  }
  for (int i = 1; i <= n; i++) {
    int ans = query(1, w[i]);
    printf("%d ", ans);
  }
  return 0;
}
