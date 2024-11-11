#include <bits/stdc++.h>
using namespace std;
int n, a[400005], dep[200005], minn, ans;
int stk[200005], bot, top, fa[200005], ls[400005], rs[400005];
int maxx[1600005], tag[1600005];
void dfs(int u, int pre) {
  dep[u] = dep[pre] + 1;
  fa[u] = pre;
  if (ls[u]) dfs(ls[u], u);
  if (rs[u]) dfs(rs[u], u);
}
inline void pushup(int u) { maxx[u] = max(maxx[u << 1], maxx[u << 1 | 1]); }
void build(int u, int l, int r) {
  if (l == r) {
    maxx[u] = dep[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(u << 1, l, mid);
  build(u << 1 | 1, mid + 1, r);
  pushup(u);
}
inline void calc(int u, int val) {
  maxx[u] += val;
  tag[u] += val;
}
inline void pushdown(int u) {
  if (tag[u]) {
    calc(u << 1, tag[u]);
    calc(u << 1 | 1, tag[u]);
    tag[u] = 0;
  }
}
void modify(int u, int l, int r, int x, int y, int z) {
  if (x <= l && r <= y) {
    calc(u, z);
    return;
  }
  pushdown(u);
  int mid = (l + r) >> 1;
  if (x <= mid) modify(u << 1, l, mid, x, y, z);
  if (y > mid) modify(u << 1 | 1, mid + 1, r, x, y, z);
  pushup(u);
}
int query(int u, int l, int r, int x, int y) {
  if (x <= l && r <= y) return maxx[u];
  pushdown(u);
  int mid = (l + r) >> 1, res = 0;
  if (x <= mid) res = max(res, query(u << 1, l, mid, x, y));
  if (y > mid) res = max(res, query(u << 1 | 1, mid + 1, r, x, y));
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1, pre; i <= n; ++i) {
    scanf("%d", a + i), a[i + n] = a[i];
    pre = top;
    while (top && a[stk[top]] > a[i]) --top;
    if (top) rs[stk[top]] = i;
    if (top != pre) ls[i] = stk[top + 1];
    stk[++top] = i;
  }
  dfs(stk[1], 0);
  build(2, 1, n);
  minn = maxx[1] = maxx[2];
  bot = 1;
  for (int i = 1, pre, t; i < n; ++i) {
    if (i == stk[bot]) {
      modify(1, 1, n + n, i, i + n - 1, -1);
      fa[rs[i]] = 0;
      ++bot;
    } else {
      modify(1, 1, n + n, i, fa[i] - 1, -1);
      ls[fa[i]] = rs[i];
      fa[rs[i]] = fa[i];
    }
    pre = top;
    while (top >= bot && a[stk[top]] > a[i + n]) --top;
    if (top >= bot) {
      rs[stk[top]] = i + n, fa[i + n] = stk[top];
      modify(1, 1, n + n, i + n, i + n,
             query(1, 1, n + n, stk[top], stk[top]) + 1);
    } else
      modify(1, 1, n + n, i + n, i + n, 1);
    if (top != pre) {
      ls[i + n] = stk[top + 1], fa[stk[top + 1]] = i + n;
      modify(1, 1, n + n, stk[top] + 1, i + n - 1, 1);
    }
    stk[++top] = i + n;
    t = query(1, 1, n + n, i + 1, i + n);
    if (t < minn) minn = t, ans = i;
  }
  printf("%d %d\n", minn, ans);
  return 0;
}
