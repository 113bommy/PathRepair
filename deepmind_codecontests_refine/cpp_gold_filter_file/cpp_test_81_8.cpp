#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
const int INF = 0x3f3f3f3f;
struct P {
  int s, a;
  bool operator<(const P& r) const {
    int x = max(s, a), y = max(r.s, r.a);
    if (x != y) return x < y;
    if (s != r.s) return s < r.s;
    return a < r.a;
  }
};
P p[MAXN];
int n, d;
int a[MAXN << 1], cnt;
int maxv[MAXN << 3], addv[MAXN << 3];
int unique(int a[], int n) {
  int cnt = 1;
  sort(a + 1, a + n + 1);
  for (int i = 2; i <= n; i++)
    if (a[i] != a[cnt]) a[++cnt] = a[i];
  return cnt;
}
int search(int x) {
  int l = 1, r = cnt;
  while (l < r) {
    int mid = l + r >> 1;
    if (x <= a[mid])
      r = mid;
    else
      l = mid + 1;
  }
  return l;
}
void build(int o, int l, int r) {
  maxv[o] = -INF;
  addv[o] = 0;
  if (l == r) return;
  int mid = l + r >> 1;
  build(o << 1, l, mid);
  build(o << 1 | 1, mid + 1, r);
}
void down(int o) {
  int ls = o << 1, rs = o << 1 | 1;
  if (addv[o]) {
    addv[ls] += addv[o];
    addv[rs] += addv[o];
    maxv[ls] += addv[o];
    maxv[rs] += addv[o];
    addv[o] = 0;
  }
}
int query(int o, int l, int r, int L, int R) {
  if (L <= l && r <= R) return maxv[o];
  down(o);
  int mid = l + r >> 1;
  if (R <= mid) return query(o << 1, l, mid, L, R);
  if (mid < L) return query(o << 1 | 1, mid + 1, r, L, R);
  return max(query(o << 1, l, mid, L, R), query(o << 1 | 1, mid + 1, r, L, R));
}
void update(int o, int l, int r, int x, int v) {
  if (l == r) {
    maxv[o] = max(maxv[o], v);
    return;
  }
  down(o);
  int mid = l + r >> 1;
  if (x <= mid)
    update(o << 1, l, mid, x, v);
  else
    update(o << 1 | 1, mid + 1, r, x, v);
  maxv[o] = max(maxv[o << 1], maxv[o << 1 | 1]);
}
void add(int o, int l, int r, int L, int R, int v) {
  if (L <= l && r <= R) {
    maxv[o] += v;
    addv[o] += v;
    return;
  }
  down(o);
  int mid = l + r >> 1;
  if (L <= mid) add(o << 1, l, mid, L, R, v);
  if (mid < R) add(o << 1 | 1, mid + 1, r, L, R, v);
  maxv[o] = max(maxv[o << 1], maxv[o << 1 | 1]);
}
void show(int o, int l, int r) {
  if (l == r) {
    printf("%d ", maxv[o]);
    return;
  }
  down(o);
  int mid = l + r >> 1;
  show(o << 1, l, mid);
  show(o << 1 | 1, mid + 1, r);
}
void subMain() {
  scanf("%d%d", &n, &d);
  cnt = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &p[i].s, &p[i].a);
    a[++cnt] = p[i].s;
    a[++cnt] = p[i].a;
  }
  a[++cnt] = d;
  cnt = unique(a, cnt);
  d = search(d);
  for (int i = 1; i <= n; i++) {
    p[i].s = search(p[i].s);
    p[i].a = search(p[i].a);
  }
  build(1, 1, cnt);
  update(1, 1, cnt, d, 0);
  sort(p + 1, p + n + 1);
  for (int i = 1; i <= n; i++) {
    if (p[i].s < d) continue;
    if (p[i].s <= p[i].a) {
      update(1, 1, cnt, p[i].a, query(1, 1, cnt, 1, p[i].s) + 1);
    } else {
      update(1, 1, cnt, p[i].a, query(1, 1, cnt, 1, p[i].a) + 1);
      add(1, 1, cnt, p[i].a + 1, p[i].s, 1);
    }
  }
  printf("%d\n", maxv[1]);
}
int main() {
  int T = 1;
  for (int i = 1; i <= T; i++) subMain();
  return 0;
}
