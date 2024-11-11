#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int N = 1e5 + 5;
vector<int> v[N];
int fac[N], ifac[N];
map<int, int> mp1, mp2;
int n, mod, k, x, val[N];
int MX, tot, root, sze[N];
int in[N], out[N], vis[N];
void Mul(int &x, int y) { x = 1ll * x * y % mod; }
int mul(int x, int y) { return 1ll * x * y % mod; }
void Dec(int &x, int y) { x = x - y < 0 ? x + mod - y : x - y; }
int dec(int x, int y) { return x - y < 0 ? x + mod - y : x - y; }
void Inc(int &x, int y) { x = x + y >= mod ? x + y - mod : x + y; }
int inc(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
void getroot(int now, int fa = 0) {
  sze[now] = 1;
  int mx = 0;
  for (auto to : v[now]) {
    if (vis[to] or to == fa) continue;
    getroot(to, now);
    sze[now] += sze[to];
    mx = max(mx, sze[to]);
  }
  mx = max(mx, tot - sze[now]);
  if (mx < MX) MX = mx, root = now;
}
void dfs(int now, int dep, int a1, int a2, int fa) {
  a1 = inc(a1, mul(fac[dep], val[now]));
  a2 = inc(mul(a2, k), val[now]);
  in[now] += mp2[a1];
  out[now] += mp1[mul(dec(x, a2), ifac[dep + 1])];
  for (auto to : v[now]) {
    if (to == fa or vis[to]) continue;
    dfs(to, dep + 1, a1, a2, now);
  }
}
void dfs2(int now, int dep, int a1, int a2, int fa) {
  a1 = inc(a1, mul(fac[dep], val[now]));
  a2 = inc(mul(a2, k), val[now]);
  mp1[a1]++;
  mp2[mul(dec(x, a2), ifac[dep + 1])]++;
  for (auto to : v[now]) {
    if (to == fa or vis[to]) continue;
    dfs2(to, dep + 1, a1, a2, now);
  }
}
void solve(int now) {
  vis[now] = 1;
  mp1[val[now]] = 1;
  mp2[mul(dec(x, val[now]), ifac[1])] = 1;
  for (auto to : v[now]) {
    if (vis[to]) continue;
    dfs(to, 0, 0, 0, now);
    dfs2(to, 1, val[now], val[now], now);
  }
  in[now] += mp2[0];
  out[now] += mp1[x];
  mp1.clear(), mp2.clear();
  for (int i = (int)v[now].size() - 1; i >= 0; i--) {
    int to = v[now][i];
    if (vis[to]) continue;
    dfs(to, 0, 0, 0, now);
    dfs2(to, 1, val[now], val[now], now);
  }
  mp1.clear(), mp2.clear();
  for (auto to : v[now]) {
    if (vis[to]) continue;
    tot = sze[to];
    MX = 1e9;
    getroot(to);
    solve(root);
  }
}
int ksm(int a, int b = mod - 2, int ans = 1) {
  while (b) {
    if (b & 1) ans = mul(ans, a);
    a = mul(a, a);
    b >>= 1;
  }
  return ans;
}
signed main() {
  scanf("%d%d%d%d", &n, &mod, &k, &x);
  fac[0] = ifac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = mul(fac[i - 1], k);
  ifac[n] = ksm(fac[n]);
  for (int i = n - 1; i; i--) ifac[i] = mul(ifac[i + 1], k);
  for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
  for (int x, y, i = 1; i < n; i++)
    scanf("%d%d", &x, &y), v[x].push_back(y), v[y].push_back(x);
  tot = n;
  MX = 1e9;
  getroot(1);
  solve(root);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += 2ll * in[i] * (n - in[i]);
    ans += 1ll * in[i] * (n - out[i]);
    ans += 1ll * out[i] * (n - in[i]);
    ans += 2ll * out[i] * (n - out[i]);
  }
  ans = n * n * n - ans / 2;
  printf("%lld\n", ans);
  return 0;
}
