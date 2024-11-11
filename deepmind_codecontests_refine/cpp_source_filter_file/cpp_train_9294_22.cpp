#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  char c = getchar();
  int w = 1;
  x = 0;
  while (!isdigit(c)) (c == '-') && (w = -w), c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ '0'), c = getchar();
  x *= w;
}
const int N = 100010;
int n, a[N], last[N];
bool vis[N];
struct node {
  int L, R, pos;
} st[N << 2];
inline void push_up(int p) {
  st[p].pos = min(st[(p << 1)].pos, st[(p << 1 | 1)].pos);
}
inline void build(int l, int r, int p) {
  st[p].L = l;
  st[p].R = r;
  st[p].pos = 0;
  if (l == r) {
    return;
  }
  int mid = l + r >> 1;
  build(l, mid, (p << 1));
  build(mid + 1, r, (p << 1 | 1));
}
inline void update(int p, int x, int v) {
  int l = st[p].L, r = st[p].R, mid = l + r >> 1;
  if (l == r) {
    st[p].pos = v;
    return;
  }
  if (x <= mid) update((p << 1), x, v);
  if (x > mid) update((p << 1 | 1), x, v);
  push_up(p);
}
inline int query(int p, int x, int y) {
  int l = st[p].L, r = st[p].R, mid = l + r >> 1;
  if (x <= l && r <= y) {
    return st[p].pos;
  }
  if (x > mid) return query((p << 1 | 1), x, y);
  if (y <= mid) return query((p << 1), x, y);
  return min(query((p << 1), x, y), query((p << 1 | 1), x, y));
}
signed main() {
  read(n);
  memset(vis, false, sizeof(vis));
  build(1, n, 1);
  for (register int i = 1; i <= n; ++i) {
    read(a[i]);
    if (a[i] > 1) vis[1] = true;
    if (a[i] > 1 && !vis[a[i]]) {
      if (query(1, 1, a[i] - 1) > last[a[i]]) vis[a[i]] = true;
    }
    update(1, a[i], i);
    last[a[i]] = i;
  }
  for (register int i = 1; i <= n; ++i) {
    if (!vis[i] && query(1, 1, i - 1) > last[i]) vis[i] = true;
  }
  for (register int i = 1; i <= n + 1; ++i) {
    if (!vis[i]) {
      return cout << i, 0;
    }
  }
  return 0;
}
