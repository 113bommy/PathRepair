#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
const long long inf = 1e18;
int n, m, p, a[maxn];
long long bot[maxn * 22], *pt = bot;
long long *lim[maxn << 2], sum[maxn << 2];
void pushup(int id, int len) {
  int lc = id << 1, rc = id << 1 | 1;
  sum[id] = sum[lc] + sum[rc];
  int lenl = (len + 1) / 2, lenr = len / 2;
  for (int i = 0, nw = 0; i <= lenl && nw <= len; i++) {
    assert(nw >= i);
    long long nl = lim[lc][i], nr = (i == lenl) ? inf : lim[lc][i + 1] - 1;
    assert(nl <= nr);
    while (nw - i <= lenr && nr + sum[lc] - 1ll * i * p >= lim[rc][nw - i]) {
      lim[id][nw] = max(nl, lim[rc][nw - i] + 1ll * i * p - sum[lc]);
      nw++;
    }
  }
}
void build(int l, int r, int id) {
  lim[id] = pt, pt += r - l + 2;
  lim[id][0] = -inf;
  if (l == r) {
    sum[id] = a[l];
    lim[id][1] = p - a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, id << 1);
  build(mid + 1, r, id << 1 | 1);
  pushup(id, r - l + 1);
}
long long now;
void query(int l, int r, int id, int L, int R) {
  if (L <= l && r <= R) {
    int x = upper_bound(lim[id] + 1, lim[id] + r - l + 2, now) - lim[id] - 1;
    now += sum[id] - x * p;
    return;
  }
  int mid = (l + r) >> 1;
  if (L <= mid) query(l, mid, id << 1, L, R);
  if (R > mid) query(mid + 1, r, id << 1 | 1, L, R);
}
int main() {
  scanf("%d%d%d", &n, &m, &p);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  build(1, n, 1);
  for (int i = 1, l, r; i <= m; i++) {
    scanf("%d%d", &l, &r);
    now = 0;
    query(1, n, 1, l, r);
    printf("%lld\n", now);
  }
  return 0;
}
