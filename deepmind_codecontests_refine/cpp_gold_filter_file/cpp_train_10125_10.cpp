#include <bits/stdc++.h>
using namespace std;
const int N = 600010;
struct Query {
  int x, y, id, pos;
} q[N];
struct Node {
  int add, mx;
} tr[N << 2];
int c[N], pos[N];
map<pair<int, int>, int> mp;
pair<int, int> p[N];
void ins(int x, int v) {
  for (int i = x; i < N; i += i & (-i)) c[i] += v;
}
int sum(int x) {
  int res = 0;
  for (int i = x; i; i -= i & (-i)) res += c[i];
  return res;
}
void pushdown(int o, int l, int r) {
  if (tr[o].add) {
    tr[o << 1].add += tr[o].add;
    tr[o << 1 | 1].add += tr[o].add;
    tr[o << 1].mx += tr[o].add;
    tr[o << 1 | 1].mx += tr[o].add;
    tr[o].add = 0;
  }
}
void update(int o, int l, int r, int L, int R, int v) {
  if (L > R) return;
  if (L <= l && R >= r) {
    tr[o].mx += v;
    tr[o].add += v;
    return;
  }
  pushdown(o, l, r);
  int mid = (l + r) >> 1;
  if (L <= mid) update(o << 1, l, mid, L, R, v);
  if (R > mid) update(o << 1 | 1, mid + 1, r, L, R, v);
  tr[o].mx = max(tr[o << 1].mx, tr[o << 1 | 1].mx);
}
void change(int o, int l, int r, int x, int v) {
  if (l == r) {
    tr[o].mx = v;
    tr[o].add = 0;
    return;
  }
  pushdown(o, l, r);
  int mid = (l + r) >> 1;
  if (x <= mid)
    change(o << 1, l, mid, x, v);
  else
    change(o << 1 | 1, mid + 1, r, x, v);
  tr[o].mx = max(tr[o << 1].mx, tr[o << 1 | 1].mx);
}
int main() {
  int n, k, m;
  scanf("%d%d%d", &n, &k, &m);
  int idx = 0;
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (!mp[{x, y}]) {
      mp[{x, y}] = ++idx;
      p[idx] = {y + abs(x - k), idx};
      q[i] = {x, y, idx, 0};
    } else {
      q[i] = {x, y, -mp[{x, y}], 0};
      mp[{x, y}] = 0;
    }
  }
  sort(p + 1, p + idx + 1);
  for (int i = 1; i <= idx; i++) pos[p[i].second] = i;
  for (int i = 1; i <= m; i++) q[i].pos = pos[abs(q[i].id)];
  int inf = n + 2 * m;
  update(1, 1, inf, 1, inf, -1e9);
  for (int i = 1; i <= m; i++) {
    int x = q[i].x, y = q[i].y, id = q[i].id, pos = q[i].pos;
    if (id > 0) {
      update(1, 1, inf, 1, pos - 1, 1);
      int cnt = sum(inf) - sum(pos);
      change(1, 1, inf, pos, p[pos].first + cnt);
      ins(pos, 1);
    } else {
      update(1, 1, inf, 1, pos - 1, -1);
      change(1, 1, inf, pos, -1e9);
      ins(pos, -1);
    }
    printf("%d\n", max(0, tr[1].mx - n));
  }
  return 0;
}
