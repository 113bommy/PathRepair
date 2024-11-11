#include <bits/stdc++.h>
using namespace std;
long long t, qq, n, m, r1, p, q, i, k, x, y, cnt, top[1000001], w[1000001],
    a[1000001], dep[1000001], f[1000001], siz[1000001], he[1000001],
    ll[2000001], ne[2000001], to[2000001], z[4000001], l[4000001], r[4000001],
    c[4000001], son[1000001], id[1000001];
inline void did1(long long u, long long fat, long long dee) {
  dep[u] = dee;
  f[u] = fat;
  siz[u] = 1;
  register long long max1 = -1;
  register long long v;
  for (register long long i = he[u]; i; i = ne[i]) {
    v = to[i];
    if (v == fat) continue;
    did1(v, u, dee + 1);
    if (siz[v] > max1) {
      son[u] = v;
      max1 = siz[v];
    }
    siz[u] += siz[v];
  }
}
inline void did2(long long u, long long topf) {
  id[u] = ++cnt;
  top[u] = topf;
  if (!son[u]) return;
  did2(son[u], topf);
  for (register long long i = he[u]; i; i = ne[i]) {
    register long long v = to[i];
    if (v == f[u] || v == son[u]) continue;
    did2(v, v);
  }
}
inline void build(long long u, long long l1, long long r1) {
  l[u] = l1;
  r[u] = r1;
  if (l1 == r1) {
    z[u] = 1;
    return;
  }
  build(u * 2, l1, (l1 + r1) / 2);
  build(u * 2 + 1, (l1 + r1) / 2 + 1, r1);
  z[u] = (z[u * 2] + z[u * 2 + 1]);
}
inline void jia(long long u, long long l1, long long r1, long long k) {
  if ((l[u] > r1) || (r[u] < l1)) return;
  if ((l[u] >= l1) && (r[u] <= r1)) {
    z[u] = k;
    return;
  }
  jia(u * 2, l1, r1, k);
  jia(u * 2 + 1, l1, r1, k);
  z[u] = (z[u * 2] + z[u * 2 + 1]);
}
inline long long qui(long long u, long long l1, long long r1) {
  if (l1 > r1) return 0;
  if ((l1 > r[u]) || (r1 < l[u])) return 0;
  if ((l1 <= l[u]) && (r1 >= r[u])) return z[u];
  return (qui(u * 2, l1, r1) + qui(u * 2 + 1, l1, r1));
}
inline long long quimax(long long x, long long y) {
  register long long ans = 0;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    ans = (ans + qui(1, id[top[x]], id[x]));
    x = f[top[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  ans = (ans + qui(1, id[son[x]], id[y]));
  return ans;
}
int main() {
  scanf("%lld", &n);
  for (i = 1; i < n; i++) {
    scanf("%lld%lld", &x, &y);
    cnt++;
    ne[cnt] = he[x];
    to[cnt] = y;
    he[x] = cnt;
    cnt++;
    ne[cnt] = he[y];
    to[cnt] = x;
    he[y] = cnt;
  }
  did1(1, 0, 1);
  cnt = 0;
  did2(1, 1);
  build(1, 1, n);
  scanf("%lld", &m);
  while (m--) {
    scanf("%lld", &q);
    if (q == 1) {
      scanf("%lld", &x);
      r1 = to[2 * x];
      p = to[2 * x - 1];
      if (dep[r1] < dep[p])
        jia(1, id[p], id[p], 1);
      else
        jia(1, id[r1], id[r1], 1);
    }
    if (q == 2) {
      scanf("%lld", &x);
      r1 = to[2 * x];
      p = to[2 * x - 1];
      if (dep[r1] < dep[p])
        jia(1, id[p], id[p], 1e11);
      else
        jia(1, id[r1], id[r1], 1e11);
    } else {
      scanf("%lld%lld", &x, &y);
      if (x == y) {
        printf("0\n");
      } else {
        t = quimax(x, y);
        if (t < 1e11)
          printf("%lld\n", t);
        else
          printf("-1\n");
      }
    }
  }
  return 0;
}
