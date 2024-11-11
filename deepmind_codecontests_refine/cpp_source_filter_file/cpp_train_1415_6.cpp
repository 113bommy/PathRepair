#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long t = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c <= '9' && c >= '0') t = t * 10LL + c - 48LL, c = getchar();
  return t * f;
}
long long mo = 1e9 + 7;
long long f[200001], a[200001], L[200001], R[200001], ans, now[200001];
long long n;
struct poi {
  long long a, c, ab, bc, abc, cnt;
} tr[3000001];
long long lson[3000001], rson[3000001], rt[200001], tot;
inline void add(long long x, long long v) {
  for (; x <= 5; x += x & -x) f[x] += v;
}
inline long long get(long long x) {
  long long sum = 0;
  for (; x; x -= x & -x) sum += f[x];
  return sum;
}
inline void up(long long x) {
  if (!lson[x]) tr[x] = tr[rson[x]];
  if (!rson[x]) tr[x] = tr[lson[x]];
  tr[x].a = tr[lson[x]].a + tr[rson[x]].a;
  tr[x].c = tr[lson[x]].c + tr[rson[x]].c;
  tr[x].cnt = tr[lson[x]].cnt + tr[rson[x]].cnt;
  tr[x].ab = tr[lson[x]].ab + tr[rson[x]].ab + tr[lson[x]].a * tr[rson[x]].cnt;
  tr[x].bc = tr[lson[x]].bc + tr[rson[x]].bc + tr[lson[x]].cnt * tr[rson[x]].c;
  tr[x].abc = tr[lson[x]].abc + tr[rson[x]].abc +
              tr[lson[x]].ab * tr[rson[x]].c + tr[lson[x]].a * tr[rson[x]].bc;
  tr[x].a %= mo;
  tr[x].c %= mo;
  tr[x].ab %= mo;
  tr[x].bc %= mo;
  tr[x].abc %= mo;
  tr[x].cnt %= mo;
}
inline void upd(long long &x, long long l, long long r, long long to,
                long long kind) {
  if (!x) x = ++tot;
  if (l == r) {
    tr[x].a = L[l] * kind;
    tr[x].c = R[l] * kind;
    tr[x].cnt = kind;
    return;
  }
  long long mid = l + r >> 1;
  if (to <= mid)
    upd(lson[x], l, mid, to, kind);
  else
    upd(rson[x], mid + 1, r, to, kind);
  up(x);
}
long long m, opt, x;
long long q[200001], t_tot;
map<long long, long long> mp;
int main() {
  n = read();
  for (long long i = 1; i <= n; ++i) a[i] = read(), q[i] = a[i];
  sort(q + 1, q + n + 1);
  for (long long i = 1; i <= n; ++i)
    if (q[i] != q[i - 1]) mp[q[i]] = ++t_tot;
  for (long long i = 1; i <= n; ++i) a[i] = mp[a[i]];
  for (long long i = 1; i <= n; ++i) {
    L[i] = get(a[i]);
    add(a[i], 1);
  }
  for (long long i = 0; i <= 200001; ++i) f[i] = 0;
  for (long long i = n; i >= 1; --i) {
    R[i] = get(a[i]);
    add(a[i], 1);
  }
  for (long long i = 1; i <= n; ++i) {
    ans -= tr[rt[a[i]]].abc;
    ans = (ans % mo + mo) % mo;
    upd(rt[a[i]], 1, n, i, 1);
    ans += tr[rt[a[i]]].abc;
    ans %= mo;
  }
  for (long long i = 1; i <= n; ++i) now[i] = 1;
  m = read();
  for (long long i = 1; i <= m; ++i) {
    opt = read();
    x = read();
    if (now[x] == opt - 1) continue;
    ans -= tr[rt[a[x]]].abc;
    ans = (ans % mo + mo) % mo;
    if (opt == 1)
      upd(rt[a[x]], 1, n, x, 0);
    else
      upd(rt[a[x]], 1, n, x, 1);
    now[x] = opt - 1;
    ans += tr[rt[a[x]]].abc;
    ans %= mo;
    printf("%I64d\n", ans);
  }
}
