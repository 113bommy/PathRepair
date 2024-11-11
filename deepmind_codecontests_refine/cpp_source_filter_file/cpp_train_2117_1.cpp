#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
struct BUS {
  int s, f, t, id;
  inline bool operator<(const BUS &rhs) const { return s < rhs.s; }
} bus[N];
int temp[N * 4];
struct PEOPLE {
  int l, r, b, id;
  inline bool operator<(const PEOPLE &rhs) const { return l < rhs.l; }
} peo[N];
struct Seg {
  int pos[N << 2], mx[N << 2];
  inline void pushup(int p) {
    mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
    pos[p] = mx[p] == mx[p << 1] ? pos[p << 1] : pos[p << 1 | 1];
  }
  void update(int p, int l, int r, int x, int val, int id) {
    if (l == r) {
      if (val >= mx[p]) {
        mx[p] = val;
        pos[p] = id;
      }
      return;
    }
    int mid = l + r >> 1;
    if (x <= mid)
      update(p << 1, l, mid, x, val, id);
    else
      update(p << 1 | 1, mid + 1, r, x, val, id);
    pushup(p);
  }
  int query(int p, int l, int r, int x, int y, int val) {
    if (mx[p] < val) return -1;
    if (x <= l && y >= r && mx[p] < val) return -1;
    if (l == r) {
      if (mx[p] >= val) return pos[p];
      return -1;
    }
    int mid = l + r >> 1;
    if (x <= mid) {
      int temp = query(p << 1, l, mid, x, y, val);
      if (temp != -1) return temp;
      return query(p << 1 | 1, mid + 1, r, x, y, val);
    }
    return query(p << 1 | 1, mid + 1, r, x, y, val);
  }
} seg;
int ans[N];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &bus[i].s, &bus[i].f, &bus[i].t);
    bus[i].id = i;
    temp[++cnt] = bus[i].t;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &peo[i].l, &peo[i].r, &peo[i].b);
    peo[i].id = i;
    temp[++cnt] = peo[i].b;
  }
  sort(temp + 1, temp + 1 + cnt);
  cnt = unique(temp + 1, temp + 1 + cnt) - temp - 1;
  for (int i = 1; i <= n; i++) {
    bus[i].t = lower_bound(temp + 1, temp + 1 + cnt, bus[i].t) - temp;
  }
  for (int i = 1; i <= m; i++) {
    peo[i].b = lower_bound(temp + 1, temp + 1 + cnt, peo[i].b) - temp;
  }
  sort(bus + 1, bus + 1 + n);
  sort(peo + 1, peo + 1 + m);
  int now = 1;
  for (int i = 1; i <= m; i++) {
    while (now <= n && bus[now].s <= peo[i].l) {
      seg.update(1, 1, cnt, bus[now].t, bus[now].f, bus[now].id);
      now++;
    }
    ans[peo[i].id] = seg.query(1, 1, cnt, peo[i].b, cnt, peo[i].r);
  }
  for (int i = 1; i <= m; i++) printf("%d%c", ans[i], " \n"[i == m]);
  return 0;
}
