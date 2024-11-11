#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
vector<int> v[N << 2];
struct node {
  int l, r, opt;
} a[N << 2];
int n, m = 0, num, fa[N], lft[N], rgt[N];
bool check(int u, int x, int y) { return x < u && u < y; }
int d[N << 2];
int finds(int x) {
  if (fa[x] == x) return x;
  fa[x] = finds(fa[x]);
  return fa[x];
}
void query(int x, int l, int r, int p, int now) {
  if (v[x].size()) {
    for (int y : v[x]) {
      int u = finds(y);
      fa[u] = now;
      lft[now] = min(lft[now], lft[u]);
      rgt[now] = max(rgt[now], rgt[u]);
    }
    v[x].clear();
    v[x].push_back(now);
  }
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (p <= mid)
    query(x << 1, l, mid, p, now);
  else
    query(x << 1 | 1, mid + 1, r, p, now);
}
void modify(int x, int l, int r, int L, int R, int now) {
  if (L <= l && r <= R) {
    v[x].push_back(now);
    return;
  }
  int mid = (l + r) >> 1;
  if (L <= mid) modify(x << 1, l, mid, L, R, now);
  if (R > mid) modify(x << 1 | 1, mid + 1, r, L, R, now);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d", &a[i].opt, &a[i].l, &a[i].r);
    if (a[i].opt == 1) {
      d[++m] = a[i].l;
      d[++m] = a[i].r;
    }
  }
  sort(d + 1, d + 1 + m);
  m = unique(d + 1, d + 1 + m) - d - 1;
  for (int i = 1; i <= n; ++i) {
    if (a[i].opt == 1) {
      a[i].l = lower_bound(d + 1, d + 1 + m, a[i].l) - d;
      a[i].r = lower_bound(d + 1, d + 1 + m, a[i].r) - d;
      ++num;
      fa[num] = num;
      lft[num] = a[i].l;
      rgt[num] = a[i].r;
      query(1, 1, m, a[i].l, num);
      query(1, 1, m, a[i].r, num);
      if ((a[i].l + 1) <= (a[i].r - 1)) {
        modify(1, 1, m, a[i].l + 1, a[i].r - 1, num);
      }
    }
    if (a[i].opt == 2) {
      int x = finds(a[i].l), y = finds(a[i].r);
      if (x == y || check(lft[x], lft[y], rgt[y]) ||
          check(rgt[x], lft[y], rgt[y])) {
        puts("YES");
      } else
        puts("NO");
    }
  }
  return 0;
}
