#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 3e5 + 5;
long long n, m, head[MAXN], to[MAXN << 1], nxt[MAXN << 1], cnt = -1;
void add(long long u, long long v) {
  nxt[++cnt] = head[u];
  head[u] = cnt;
  to[cnt] = v;
}
long long dfn[MAXN], tot, pos[MAXN << 1], siz[MAXN << 1], cir;
pair<long long, long long> fa[MAXN];
void get(long long x, long long y) {
  siz[++cir] = 0;
  while (x != y) {
    pos[fa[x].second] = pos[fa[x].second ^ 1] = cir;
    siz[cir] += 2;
    x = fa[x].first;
  }
}
void dfs(long long x, long long f) {
  dfn[x] = ++tot;
  for (long long i = head[x]; i != -1; i = nxt[i]) {
    if (to[i] == f) continue;
    if (!dfn[to[i]]) {
      fa[to[i]] = make_pair(x, i);
      dfs(to[i], x);
    } else if (dfn[to[i]] < dfn[x]) {
      get(x, to[i]);
      siz[cir] += 2;
      pos[i] = pos[i ^ 1] = cir;
    }
  }
}
long long f[MAXN], now[MAXN];
void Del(long long x) {
  for (long long i = head[x]; i != -1; i = nxt[i]) now[pos[i]]--;
}
bool Add(long long x) {
  bool f = 1;
  for (long long i = head[x]; i != -1; i = nxt[i]) {
    now[pos[i]]++;
    if (now[pos[i]] >= siz[pos[i]]) f = 0;
  }
  return f;
}
long long _sum[MAXN];
signed main() {
  memset(head, -1, sizeof head);
  scanf("%lld %lld", &n, &m);
  for (long long i = 1; i <= m; ++i) {
    long long u, v;
    scanf("%lld %lld", &u, &v);
    add(u, v);
    add(v, u);
  }
  for (long long i = 1; i <= n; ++i)
    if (!dfn[i]) dfs(i, 0);
  f[0] = 0;
  siz[0] = 1e9;
  for (long long i = 1; i <= n; ++i) {
    f[i] = f[i - 1];
    Del(i - 1);
    while (f[i] <= n && Add(f[i] + 1)) f[i]++;
    Del(f[i] + 1);
    if (f[i] > n) f[i]--;
    _sum[i] = _sum[i - 1] + (f[i] - i + 1);
  }
  long long Q;
  scanf("%lld", &Q);
  while (Q-- > 0) {
    long long L, R;
    scanf("%lld %lld", &L, &R);
    long long x = upper_bound(f + 1, f + 1 + n, R) - f;
    if (x < L)
      printf("%lld\n", (R - L + 1ll) * (R - x + 2ll) / 2ll);
    else if (x <= R)
      printf("%lld\n",
             _sum[x - 1] - _sum[L - 1] + (R - x + 1ll) * (R - x + 2ll) / 2ll);
    else
      printf("%lld\n", _sum[R] - _sum[L - 1]);
  }
  return 0;
}
