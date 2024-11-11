#include <bits/stdc++.h>
using namespace std;
const int maxn = 6e5 + 10;
int p[maxn], a[maxn], b[maxn], flag[maxn];
int qur[maxn], id[maxn], f[maxn], tot;
int head[maxn], to[maxn << 1], nxt[maxn << 1], cnt, now;
void add(int u, int v) {
  ++cnt, to[cnt] = v, nxt[cnt] = head[u], head[u] = cnt;
  ++cnt, to[cnt] = u, nxt[cnt] = head[v], head[v] = cnt;
}
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
void unite(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  ++tot, add(x, tot), add(y, tot);
  f[tot] = f[x] = f[y] = tot;
}
bool same(int x, int y) { return find(x) == find(y); }
int el[maxn], er[maxn], rk[maxn];
void dfs(int u, int pre) {
  el[u] = ++now, rk[now] = u;
  for (int i = head[u]; i; i = nxt[i]) {
    int v = to[i];
    if (v == pre) continue;
    dfs(v, u);
  }
  er[u] = now;
}
int maxs[maxn << 2];
int Max(int i, int j) { return p[rk[i]] > p[rk[j]] ? i : j; }
void push_up(int id) { maxs[id] = Max(maxs[(id << 1)], maxs[(id << 1 | 1)]); }
void build(int id, int l, int r) {
  if (l == r) {
    maxs[id] = l;
    return;
  }
  int mid = (l + r) >> 1;
  build((id << 1), l, mid);
  build((id << 1 | 1), mid + 1, r);
  push_up(id);
}
int query(int id, int l, int r, int x, int y) {
  if (x <= l && y >= r) return maxs[id];
  int mid = (l + r) >> 1, ans = 0;
  if (x <= mid) ans = Max(ans, query((id << 1), l, mid, x, y));
  if (y > mid) ans = Max(ans, query((id << 1 | 1), mid + 1, r, x, y));
  return ans;
}
void update(int id, int l, int r, int pos, int val) {
  if (l == r) {
    maxs[id] = 0;
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid) update((id << 1), l, mid, pos, val);
  if (pos > mid) update((id << 1 | 1), mid + 1, r, pos, val);
  push_up(id);
}
int tree[maxn];
int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  tot = n, cnt = 0, now = 0;
  p[0] = 0, rk[0] = 0;
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]), f[i] = i;
  for (int i = 1; i <= m; i++) scanf("%d%d", &a[i], &b[i]), flag[i] = false;
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &qur[i], &id[i]);
    if (qur[i] == 2) flag[id[i]] = true;
  }
  for (int i = 1; i <= m; i++) {
    if (!flag[i]) unite(a[i], b[i]);
  }
  for (int i = q; i >= 1; i--) {
    int x = id[i];
    if (qur[i] == 2) {
      if (same(a[x], b[x])) continue;
      unite(a[x], b[x]);
    } else
      tree[i] = find(x);
  }
  for (int i = 1; i <= tot; i++) {
    if (f[i] == i) dfs(i, 0);
  }
  build(1, 1, now);
  for (int i = 1; i <= q; i++) {
    if (qur[i] == 1) {
      int rt = tree[i];
      int ans = query(1, 1, now, el[rt], er[rt]);
      printf("%d\n", p[rk[ans]]);
      update(1, 1, now, ans, 0);
    }
  }
  return 0;
}
