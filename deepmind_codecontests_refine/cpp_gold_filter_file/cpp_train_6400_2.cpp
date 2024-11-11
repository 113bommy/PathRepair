#include <bits/stdc++.h>
using namespace std;
struct po {
  int l, r, ind;
};
inline bool operator<(po a, po b) {
  if (a.l < b.l)
    return true;
  else if (a.l == b.l && a.r < b.r)
    return true;
  else
    return false;
}
po lr[500010];
int n, m, a[500010], b[500010], c[500010], i, t[2000010], otv[500010], k;
const int inf = 1000000007;
map<int, int> mi;
void build(int v, int tl, int tr) {
  if (tl == tr)
    t[v] = b[tl];
  else {
    int tm = (tl + tr) >> 1;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
  }
}
int get_min(int v, int tl, int tr, int l, int r) {
  if (l > r) return inf;
  if (l == tl && r == tr) return t[v];
  int tm = (tl + tr) >> 1;
  return min(get_min(v * 2, tl, tm, l, min(r, tm)),
             get_min(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
void update(int v, int tl, int tr, int pos) {
  if (tl == tr)
    t[v] = inf;
  else {
    int tm = (tl + tr) >> 1;
    if (pos <= tm)
      update(v * 2, tl, tm, pos);
    else
      update(v * 2 + 1, tm + 1, tr, pos);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  for (i = 0; i < n; i++) {
    if (mi[a[i]] == 0) {
      b[i] = inf;
      mi[a[i]] = i + 1;
    } else {
      b[i] = i - mi[a[i]] + 1;
      mi[a[i]] = i + 1;
    }
  }
  for (i = 0; i < n; i++) {
    if (b[i] != inf) {
      c[i] = inf;
      c[i - b[i]] = b[i];
    } else {
      c[i] = inf;
    }
  }
  build(1, 0, n - 1);
  for (i = 0; i < m; i++) {
    scanf("%d %d", &lr[i].l, &lr[i].r);
    lr[i].ind = i;
    lr[i].l--;
    lr[i].r--;
  }
  sort(lr, lr + m);
  k = 0;
  for (i = 0; i < m; i++) {
    while (k < lr[i].l) {
      if (c[k] != inf) update(1, 0, n - 1, k + c[k]);
      k++;
    }
    otv[lr[i].ind] = get_min(1, 0, n - 1, lr[i].l, lr[i].r);
    if (otv[lr[i].ind] == inf) otv[lr[i].ind] = -1;
  }
  for (i = 0; i < m; i++) printf("%d\n", otv[i]);
  return 0;
}
