#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 2e5 + 50;
const int M = 4e5 + 50;
const int K = 20;
int n, a[N];
int x, y;
int id[N];
int first[N], nxt[M], go[M], tot;
int sta[M], top;
int dfn[N], idx;
int pos[M][K], lg[M];
int euler[M], fir[M], cnt;
int dis[N];
bitset<M> vis;
int prime[N], mu[N], phi[N], num;
long long F[N], G[N], inv[N];
int k, p[N];
long long res, tmp, sum, ans;
void sieve(int n) {
  vis[1] = mu[1] = phi[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) prime[++num] = i, mu[i] = -1, phi[i] = i - 1;
    for (int j = 1; j <= num && i * prime[j] <= n; j++) {
      vis[i * prime[j]] = 1;
      if (i % prime[j] == 0) {
        mu[i * prime[j]] = 0;
        phi[i * prime[j]] = phi[i] * prime[j];
        break;
      }
      mu[i * prime[j]] = -mu[i];
      phi[i * prime[j]] = phi[i] * (prime[j] - 1);
    }
  }
}
void pre_deal(int n) {
  inv[1] = 1;
  for (int i = 2; i <= n; i++) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j += i)
      G[j] = (G[j] + (long long)i * mu[j / i] % mod * inv[phi[i]] % mod) % mod,
      G[j] = (G[j] + mod) % mod;
}
void add(int u, int v) {
  nxt[++tot] = first[u];
  first[u] = tot;
  go[tot] = v;
}
bool cmp(int x, int y) { return dfn[x] < dfn[y]; }
void dfs1(int x, int fa, int d) {
  dfn[x] = ++idx;
  euler[++cnt] = x;
  fir[x] = cnt;
  for (int i = first[x]; i; i = nxt[i])
    if (go[i] != fa)
      dis[go[i]] = dis[x] + 1, dfs1(go[i], x, d + 1), euler[++cnt] = x;
}
void init() {
  lg[1] = 0;
  for (int i = 2; i <= M - 50; i++) lg[i] = lg[i / 2] + 1;
  for (int i = 1; i <= cnt; i++) pos[i][0] = euler[i];
  for (int i = 1; (1 << i) <= cnt; i++)
    for (int j = 1; j <= cnt - (1 << i) + 1; j++)
      if (dis[pos[j][i - 1]] < dis[pos[j + (1 << (i - 1))][i - 1]])
        pos[j][i] = pos[j][i - 1];
      else
        pos[j][i] = pos[j + (1 << (i - 1))][i - 1];
}
int lca(int u, int v) {
  if (fir[u] > fir[v]) swap(u, v);
  int bit = lg[fir[v] - fir[u] + 1];
  if (dis[pos[fir[u]][bit]] < dis[pos[fir[v] - (1 << bit) + 1][bit]])
    return pos[fir[u]][bit];
  else
    return pos[fir[v] - (1 << bit) + 1][bit];
}
void ins(int x) {
  if (!top) {
    sta[++top] = x;
    return;
  }
  int p = lca(sta[top], x);
  while (top > 1 && dis[sta[top - 1]] > dis[p])
    add(sta[top - 1], sta[top]), top--;
  if (dis[sta[top]] > dis[p]) add(p, sta[top]), top--;
  if ((!top) || (sta[top] != p)) sta[++top] = p;
  sta[++top] = x;
}
void build() {
  tot = 0;
  sort(p + 1, p + k + 1, cmp);
  if (p[1] != 1) sta[++top] = 1;
  for (int i = 1; i <= k; i++) ins(p[i]);
  while (top > 1) add(sta[top - 1], sta[top]), top--;
  top = k = 0;
}
void dfs2(int x, int fa) {
  for (int i = first[x]; i; i = nxt[i]) {
    int y = go[i];
    if (y == fa) continue;
    dfs2(y, x);
    tmp = (tmp + 4 * F[x] * F[y] % mod * dis[x] % mod) % mod;
    F[x] = (F[x] + F[y]) % mod;
  }
}
void clear(int x, int fa) {
  for (int i = first[x]; i; i = nxt[i])
    if (go[i] != fa) clear(go[i], x);
  first[x] = F[x] = 0;
}
void solve() {
  memset(first, 0, sizeof first);
  for (int i = 1; i <= n; i++) {
    if (2 * i > n) break;
    res = tmp = sum = 0;
    for (int j = i; j <= n; j += i) sum = (sum + (long long)phi[j]) % mod;
    for (int j = i; j <= n; j += i) {
      x = id[j];
      p[++k] = x;
      F[x] = phi[j];
      res = (res + (long long)2 * phi[j] * dis[x] % mod * sum % mod) % mod;
      tmp = (tmp + (long long)2 * phi[j] * phi[j] % mod * dis[x] % mod) % mod;
    }
    build();
    dfs2(1, 0);
    ans = (ans + G[i] * res % mod) % mod;
    ans = (ans - G[i] * tmp % mod + mod) % mod;
    clear(1, 0);
  }
  ans = ans * inv[n] % mod * inv[n - 1] % mod;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), id[a[i]] = i;
  for (int i = 1; i < n; i++) scanf("%d%d", &x, &y), add(x, y), add(y, x);
  sieve(n);
  pre_deal(n);
  dfs1(1, 0, 1);
  init();
  solve();
  printf("%lld\n", ans);
  return 0;
}
