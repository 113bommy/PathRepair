#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, m, has[2 * N], tot, ans[N];
struct Bus {
  int l, r, b, id;
  bool operator<(const Bus& a) const {
    if (l == a.l) return id < a.id;
    return l < a.l;
  }
} bus[2 * N];
int mx[N << 2], k[N << 2];
void pushup(int id) { mx[id] = max(mx[id << 1], mx[id << 1 | 1]); }
void update(int id, int l, int r, int pos, int val, int v) {
  if (l == r) {
    mx[id] = max(mx[id], val);
    k[id] = v;
    return;
  }
  int mid = l + r >> 1;
  if (pos <= mid)
    update(id << 1, l, mid, pos, val, v);
  else
    update(id << 1 | 1, mid + 1, r, pos, val, v);
  pushup(id);
}
int query(int id, int l, int r, int L, int R, int q) {
  if (L <= l && R >= r)
    if (mx[id] < q) return -1;
  if (l == r) return k[id];
  int mid = l + r >> 1, ret = -1;
  if (L <= mid) ret = query(id << 1, l, mid, L, R, q);
  if (ret != -1) return ret;
  if (R > mid) ret = query(id << 1 | 1, mid + 1, r, L, R, q);
  return ret;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n + m; i++) {
    scanf("%d%d%d", &bus[i].l, &bus[i].r, &bus[i].b);
    has[++tot] = bus[i].b;
    bus[i].id = i;
  }
  sort(has + 1, has + 1 + tot);
  tot = unique(has + 1, has + 1 + tot) - has - 1;
  sort(bus + 1, bus + 1 + n + m);
  for (int i = 1; i <= n + m; i++) {
    int pos = lower_bound(has + 1, has + 1 + tot, bus[i].b) - has;
    if (bus[i].id <= n)
      update(1, 1, tot, pos, bus[i].r, bus[i].id);
    else
      ans[bus[i].id - n] = query(1, 1, tot, pos, tot, bus[i].r);
  }
  for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
  return 0;
}
