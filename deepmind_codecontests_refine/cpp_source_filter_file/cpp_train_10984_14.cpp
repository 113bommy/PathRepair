#include <bits/stdc++.h>
using namespace std;
vector<int> d[400001];
int n, m, t, x, y, c[400001], l[400001], r[400001];
struct rua {
  int l, r;
  long long f, w;
} tr[400001 << 2];
long long a[400001];
void update(int x) {
  int lson = x * 2, rson = x * 2 + 1;
  tr[x].w = tr[lson].w | tr[rson].w;
}
void down(int x) {
  long long c = tr[x].w;
  tr[x].w = 0;
  int lson = x * 2, rson = x * 2 + 1;
  tr[lson].f = tr[lson].w = c;
  tr[rson].f = tr[rson].w = c;
}
void Build(int l, int r, int x) {
  tr[x] = {l, r, 0, 0};
  if (l == r) {
    tr[x].w = a[l];
    return;
  }
  int mid = l + r >> 1;
  Build(l, mid, x * 2);
  Build(mid + 1, r, x * 2 + 1);
  update(x);
}
void Change(int L, int R, long long c, int x) {
  int l = tr[x].l, r = tr[x].r;
  int mid = l + r >> 1;
  if (L <= l && r <= R) {
    tr[x].f = tr[x].w = c;
    return;
  }
  if (tr[x].f) down(x);
  if (L <= mid) Change(L, R, c, x * 2);
  if (R > mid) Change(L, R, c, x * 2 + 1);
  update(x);
}
long long Query(int L, int R, int x) {
  int l = tr[x].l, r = tr[x].r;
  int mid = l + r >> 1;
  long long res = 0;
  if (L <= l && r <= R) return tr[x].w;
  if (tr[x].f) down(x);
  if (L <= mid) res |= Query(L, R, x * 2);
  if (R > mid) res |= Query(L, R, x * 2 + 1);
  update(x);
  return res;
}
void dfs(int cur, int pre) {
  l[cur] = ++x;
  a[x] = 1ll << c[cur];
  for (auto nxt : d[cur])
    if (nxt != pre) dfs(nxt, cur);
  r[cur] = x;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
  for (int i = 2; i <= n; i++)
    scanf("%d%d", &x, &y), d[x].push_back(y), d[y].push_back(x);
  x = 0, dfs(1, 0);
  Build(1, n, 1);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &t);
    if (t == 1)
      scanf("%d%d", &x, &y), Change(l[x], r[x], 1ll << y, 1);
    else
      scanf("%d", &x),
          printf("%d\n", (int)__builtin_popcountll(Query(l[x], r[x], 1)));
  }
}
