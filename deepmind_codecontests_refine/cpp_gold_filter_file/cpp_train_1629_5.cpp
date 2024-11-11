#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 5;
long long n, sum, mx, e, rt;
char c[N];
long long vis[N], siz[N], fa[N];
long long ans[N], s[N];
long long t[(1 << 22) + 5], q[N];
long long nex[N], to[N], h[N], a[N];
void add(long long f, long long t) { nex[++e] = h[f], to[e] = t, h[f] = e; }
void get_root(long long x, long long f) {
  long long son = 0;
  fa[x] = f, siz[x] = 1;
  for (long long i = h[x]; i; i = nex[i]) {
    if (to[i] == f || vis[to[i]]) continue;
    get_root(to[i], x), siz[x] += siz[to[i]];
    son = max(son, siz[to[i]]);
  }
  son = max(son, sum - siz[x]);
  if (son < mx) rt = x, mx = son;
}
void ins(long long x, long long f, long long d) {
  d ^= a[x], t[d]++;
  for (long long i = h[x]; i; i = nex[i]) {
    if (to[i] == f || vis[to[i]]) continue;
    ins(to[i], x, d);
  }
}
void ask(long long x, long long f, long long d) {
  d ^= a[x], s[x] = t[d];
  for (long long i = 0; i <= 20; ++i) s[x] += t[d ^ (1 << i)];
  for (long long i = h[x]; i; i = nex[i]) {
    if (to[i] == f || vis[to[i]]) continue;
    ask(to[i], x, d), s[x] += s[to[i]];
  }
  ans[x] += s[x];
}
void del(long long x, long long f, long long d) {
  d ^= a[x], t[d]--;
  for (long long i = h[x]; i; i = nex[i]) {
    if (to[i] == f || vis[to[i]]) continue;
    del(to[i], x, d);
  }
}
void solve(long long x) {
  vis[x] = 1;
  long long top = 0;
  for (long long i = h[x]; i; i = nex[i])
    if (!vis[to[i]]) q[++top] = to[i];
  t[a[x]] = 1;
  for (long long i = 1; i <= top; ++i) ask(q[i], x, 0), ins(q[i], x, a[x]);
  for (long long i = 1; i <= top; ++i) ans[x] += s[q[i]];
  for (long long i = 1; i <= top; ++i) del(q[i], x, a[x]);
  t[a[x]] = 0;
  for (long long i = top; i >= 1; --i) ask(q[i], x, 0), ins(q[i], x, a[x]);
  for (long long i = top; i >= 1; --i) del(q[i], x, a[x]);
  for (long long i = h[x]; i; i = nex[i]) {
    if (vis[to[i]]) continue;
    mx = sum = siz[to[i]], rt = 0;
    get_root(to[i], x), solve(rt);
  }
}
signed main() {
  long long x, y;
  scanf("%lld", &n), mx = sum = n;
  for (long long i = 1; i < n; ++i)
    scanf("%lld%lld", &x, &y), add(x, y), add(y, x);
  scanf("%s", c + 1);
  for (long long i = 1; i <= n; ++i) a[i] = 1 << (c[i] - 'a');
  get_root(1, 0), solve(rt);
  for (long long i = 1; i <= n; ++i) printf("%lld ", ans[i] + 1);
  return 0;
}
