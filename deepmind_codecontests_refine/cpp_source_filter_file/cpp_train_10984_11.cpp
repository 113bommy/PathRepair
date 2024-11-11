#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int n, q;
int c[N];
vector<vector<int>> g(N);
int idx, od[N], st[N], ed[N];
struct seg {
  int l, r, pure;
  bitset<62> bit;
};
seg t[N << 2];
void push_up(int x) {
  t[x].bit = t[(x << 1)].bit | t[((x << 1) | 1)].bit;
  t[x].pure = (t[x].bit.count() == 1);
}
void push_down(int x) {
  if (t[x].pure) {
    t[(x << 1)].bit = t[x].bit;
    t[((x << 1) | 1)].bit = t[x].bit;
    t[(x << 1)].pure = t[((x << 1) | 1)].pure = 1;
  }
}
void build(int l, int r, int x = 1) {
  t[x].l = l, t[x].r = r;
  if (l == r) {
    t[x].bit.set(c[od[l]]);
    t[x].pure = 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, (x << 1));
  build(mid + 1, r, ((x << 1) | 1));
  push_up(x);
}
void update(int l, int r, int c, int x = 1) {
  int L = t[x].l, R = t[x].r;
  if (l <= L and R <= r) {
    t[x].bit.reset();
    t[x].bit.set(c);
    t[x].pure = 1;
    return;
  }
  push_down(x);
  int mid = (L + R) >> 1;
  if (l <= mid) update(l, r, c, (x << 1));
  if (r > mid) update(l, r, c, ((x << 1) | 1));
  push_up(x);
}
bitset<62> query(int l, int r, int x = 1) {
  int L = t[x].l, R = t[x].r;
  if (l <= L and R <= r) return t[x].bit;
  push_down(x);
  bitset<62> ret;
  ret.reset();
  int mid = (L + R) >> 1;
  if (l <= mid) ret |= query(l, r, (x << 1));
  if (r > mid) ret |= query(l, r, ((x << 1) | 1));
  return ret;
}
void dfs(int u, int f) {
  od[++idx] = u;
  st[u] = ed[u] = idx;
  for (int v : g[u])
    if (v != f) {
      dfs(v, u);
      ed[u] = ed[v];
    }
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", c + i);
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(n, -1);
  build(1, n);
  while (q--) {
    int o, u, c;
    scanf("%d%d", &o, &u);
    if (o == 1) {
      scanf("%d", &c);
      update(st[u], ed[u], c);
    } else {
      printf("%d\n", (int)query(st[u], ed[u]).count());
    }
  }
}
