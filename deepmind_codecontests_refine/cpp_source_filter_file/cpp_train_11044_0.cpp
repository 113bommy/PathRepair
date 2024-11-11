#include <bits/stdc++.h>
inline int read() {
  char c = getchar();
  int x = 0;
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - 48, c = getchar();
  return x;
}
struct Ask {
  int x, y, rk;
} q[500005];
int pre[500005], a[500005], last[500005], Ans[500005];
int d[500005 << 2], t[500005 << 2];
int n, m;
inline int cmp(Ask A, Ask B) { return A.y < B.y; }
inline std::pair<int, int> min(std::pair<int, int> a, std::pair<int, int> b) {
  return (a < b) ? a : b;
}
void build(int x, int y, int i) {
  if (x == y) {
    t[i] = x, d[i] = 999999999;
    return;
  }
  int mid = x + y >> 1;
  build(x, mid, i << 1), build(mid + 1, y, i << 1 | 1);
  if (d[i << 1] <= d[i << 1 | 1])
    d[i] = d[i << 1], t[i] = t[i << 1];
  else
    d[i] = d[i << 1 | 1], t[i] = t[i << 1 | 1];
}
void change(int pos, int x, int y, int i, int val) {
  if (x == y) {
    d[i] = val;
    t[i] = x;
    return;
  }
  int mid = x + y >> 1;
  if (pos <= mid)
    change(pos, x, mid, i << 1, val);
  else
    change(pos, mid + 1, y, i << 1 | 1, val);
  if (d[i << 1] <= d[i << 1 | 1])
    d[i] = d[i << 1], t[i] = t[i << 1];
  else
    d[i] = d[i << 1 | 1], t[i] = t[i << 1 | 1];
}
std::pair<int, int> query(int x, int y, int l, int r, int i) {
  if (x <= l && y >= r) return std::make_pair(d[i], t[i]);
  int mid = l + r >> 1;
  if (y <= mid) return query(x, y, l, mid, i << 1);
  if (x > mid) return query(x, y, mid + 1, y, i << 1 | 1);
  return min(query(x, y, l, mid, i << 1), query(x, y, mid + 1, y, i << 1 | 1));
}
int main() {
  n = read();
  for (register int i = 1; i <= n; i++) a[i] = read();
  m = read();
  for (register int i = 1; i <= m; i++)
    q[i].x = read(), q[i].y = read(), q[i].rk = i;
  std::sort(q + 1, q + m + 1, cmp);
  build(1, n, 1);
  int now = 1;
  for (register int i = 1; i <= n; i++) pre[i] = last[a[i]], last[a[i]] = i;
  for (register int i = 1; i <= n; i++) {
    if (pre[i]) change(pre[i], 1, n, 1, 999999999);
    change(i, 1, n, 1, pre[i]);
    while (q[now].y == i) {
      std::pair<int, int> k = query(q[now].x, q[now].y, 1, n, 1);
      if (k.first < q[now].x) Ans[q[now].rk] = a[k.second];
      now++;
    }
  }
  for (register int i = 1; i <= m; i++) printf("%d\n", Ans[i]);
  return 0;
}
