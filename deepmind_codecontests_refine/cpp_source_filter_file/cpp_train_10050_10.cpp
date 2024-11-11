#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool checkMax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T, typename... Args>
inline void checkMax(T &a, const Args... arg) {
  checkMax(a, max(arg...));
}
template <class T>
inline bool checkMin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T, typename... Args>
inline void checkMin(T &a, const Args... arg) {
  checkMin(a, min(arg...));
}
const int INF = 0x3f3f3f3f;
const long long llINF = 1e18;
const int MAXN = 1e5 + 5;
int n, K, len, top;
long long ans;
int a[MAXN], w[MAXN], head[MAXN], nxt[MAXN], st[MAXN];
long long pre[MAXN], suf[MAXN];
struct Edge {
  int to, next;
} e[MAXN << 1];
void add_edge(int u, int v) {
  e[++len] = (Edge){v, head[u]};
  head[u] = len;
}
struct SegmentTree {
  struct Tree {
    int l, r;
    long long mina, minb, ans, tag;
  } tree[MAXN << 2];
  void apply(int k, long long v) {
    tree[k].tag += v;
    tree[k].minb += v;
    tree[k].ans -= v;
  }
  void pushdown(int k) {
    if (tree[k].tag) {
      apply(k << 1, tree[k].tag);
      apply(k << 1 | 1, tree[k].tag);
      tree[k].tag = 0;
    }
  }
  long long calc(int k, long long pre) {
    if (tree[k].l == tree[k].r) return tree[k].mina - pre;
    pushdown(k);
    if (pre > tree[k << 1].minb)
      return min(calc(k << 1, pre), tree[k].ans);
    else
      return min(calc(k << 1 | 1, pre), tree[k << 1].mina - pre);
  }
  void update(int k) {
    tree[k].mina = min(tree[k << 1].mina, tree[k << 1 | 1].mina);
    tree[k].minb = min(tree[k << 1].minb, tree[k << 1 | 1].minb);
    tree[k].ans = calc(k << 1 | 1, tree[k << 1].minb);
  }
  void build(int k, int l, int r) {
    tree[k].l = l;
    tree[k].r = r;
    if (l == r) {
      tree[k].mina = tree[k].minb = suf[r];
      return;
    }
    int mid = (l + r) >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
    update(k);
  }
  void modify(int k, int l, int r, long long v) {
    if (tree[k].l >= l && tree[k].r <= r) {
      apply(k, v);
      return;
    }
    int mid = (tree[k].l + tree[k].r) >> 1;
    pushdown(k);
    if (l <= mid) modify(k << 1, l, r, v);
    if (r > mid) modify(k << 1 | 1, l, r, v);
    update(k);
  }
  long long findpos(int k, long long x) {
    if (tree[k].l == tree[k].r) return tree[k].l;
    return tree[k << 1 | 1].mina <= x ? findpos(k << 1 | 1, x)
                                      : findpos(k << 1, x);
  }
  long long query(int k, long long &x) {
    if (tree[k].l == tree[k].r) {
      int res = tree[k].mina - x <= k ? tree[k].r : 0;
      checkMin(x, tree[k].minb);
      return res;
    }
    pushdown(k);
    if (tree[k << 1].minb < x) {
      if (tree[k].ans <= K) return query(k << 1 | 1, x = tree[k << 1].minb);
      int res = query(k << 1, x);
      checkMin(x, tree[k].minb);
      return res;
    } else {
      long long res = tree[k << 1].mina <= K + x ? findpos(k << 1, K + x) : 0;
      checkMax(res, query(k << 1 | 1, x));
      return res;
    }
  }
} T;
void dfs(int u) {
  st[++top] = u;
  if (nxt[u] <= n) T.modify(1, nxt[u] - 1, n, pre[u] - pre[nxt[u]]);
  if (u <= n) {
    int l = 2, r = top - 1, res = 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (pre[st[mid]] - pre[u] > K)
        res = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    int maxr = st[res] - 1;
    long long mn = llINF;
    if (u > 1) T.modify(1, 1, u - 1, llINF);
    T.modify(1, maxr, n, -llINF);
    long long pos = T.query(1, mn);
    if (u > 1) T.modify(1, 1, u - 1, -llINF);
    T.modify(1, maxr, n, llINF);
    checkMax(ans, pos - u + 1);
  }
  for (int i = head[u]; i != -1; i = e[i].next) dfs(e[i].to);
  if (nxt[u] <= n) T.modify(1, nxt[u] - 1, n, pre[nxt[u]] - pre[u]);
  top -= 1;
}
int main() {
  memset(head, -1, sizeof(head));
  scanf("%d%d", &n, &K);
  for (int i = 1; i < n; i++) scanf("%d", &w[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 2; i <= n; i++) {
    pre[i] = pre[i - 1] + w[i - 1] - a[i - 1];
    suf[i] = suf[i - 1] + w[i - 1] - a[i];
  }
  nxt[n + 1] = n + 1;
  pre[n + 1] = llINF;
  ans = 1;
  for (int i = n; i >= 1; i--) {
    while (top && pre[i] >= pre[st[top]]) top -= 1;
    nxt[i] = top ? st[top] : n + 1;
    st[++top] = i;
    add_edge(nxt[i], i);
  }
  top = 0;
  T.build(1, 1, n);
  dfs(n + 1);
  printf("%lld\n", ans);
  return 0;
}
