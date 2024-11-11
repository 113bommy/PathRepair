#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int tr[N * 3], ltr[N * 3], rtr[N * 3];
int flag[N * 3];
int opl[N], opr[N];
void build(int o, int l, int r) {
  int m = (l + r) >> 1;
  tr[o] = ltr[o] = rtr[o] = r - l + 1;
  flag[o] = -1;
  if (l == r) return;
  build(o << 1, l, m);
  build(o << 1 | 1, m + 1, r);
}
void pushdown(int o, int l) {
  if (flag[o] == -1) return;
  flag[o << 1] = flag[o << 1 | 1] = flag[o];
  tr[o << 1] = ltr[o << 1] = rtr[o << 1] = flag[o] ? 0 : l - (l >> 1);
  tr[o << 1 | 1] = ltr[o << 1 | 1] = rtr[o << 1 | 1] = flag[o] ? 0 : (l >> 1);
  flag[o] = -1;
}
void pushup(int o, int l) {
  ltr[o] = ltr[o << 1];
  rtr[o] = rtr[o << 1 | 1];
  if (ltr[o] == l - (l >> 1)) ltr[o] += ltr[o << 1 | 1];
  if (rtr[o] == l >> 1) rtr[o] += rtr[o << 1];
  tr[o] = max(max(tr[o << 1], tr[o << 1 | 1]), rtr[o << 1] + ltr[o << 1 | 1]);
}
int yl, yr, v;
void update(int o, int l, int r) {
  if (yl <= l && yr >= r) {
    ltr[o] = rtr[o] = tr[o] = v ? 0 : (r - l + 1);
    flag[o] = v;
    return;
  }
  pushdown(o, r - l + 1);
  int m = (l + r) >> 1;
  if (yl <= m) update(o << 1, l, m);
  if (yr > m) update(o << 1 | 1, m + 1, r);
  pushup(o, r - l + 1);
}
int len;
int query(int o, int l, int r) {
  int m = (l + r) >> 1;
  if (l == r) return l;
  pushdown(o, r - l + 1);
  if (tr[o << 1] >= len) return query(o << 1, l, m);
  if (rtr[o << 1] + ltr[o << 1 | 1] >= len) return m - rtr[o << 1] + 1;
  return query(o << 1 | 1, m + 1, r);
}
int main() {
  int road, a, b, n;
  scanf("%d%d%d", &road, &a, &b);
  road += a + b;
  build(1, 1, road);
  scanf("%d", &n);
  int x, y;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &x, &y);
    len = y + a + b;
    if (x == 1) {
      if (tr[1] < len) {
        printf("-1\n");
        continue;
      }
      opl[i] = yl = query(1, 1, road) + a;
      opr[i] = yr = yl + y - 1;
      printf("%d\n", yl - 1 - a);
      v = 1;
      update(1, 1, road);
    } else {
      yl = opl[y];
      yr = opr[y];
      v = 0;
      update(1, 1, road);
    }
  }
  return 0;
}
