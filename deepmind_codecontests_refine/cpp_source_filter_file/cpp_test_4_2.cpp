#include <bits/stdc++.h>
using namespace std;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vc<vc<T>>;
template <class T>
void mkuni(vector<T> &v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
template <class T>
void print(T x, long long suc = 1) {
  cout << x;
  if (suc == 1)
    cout << '\n';
  else
    cout << ' ';
}
template <class T>
void print(const vector<T> &v, long long suc = 1) {
  for (long long i = 0; i < v.size(); i++)
    print(v[i], i == (long long)(v.size()) - 1 ? suc : 2);
}
const long long maxn = 1e6 + 7;
const long long mod = 1e9 + 7;
void add(long long &x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
}
void sub(long long &x, long long y) {
  x -= y;
  if (x < 0) x += mod;
}
bool ban[maxn];
long long n, k, a[maxn], sz[maxn], ans, cnt[maxn], way[maxn], mx, tc[maxn],
    tw[maxn];
long long scnt[2][maxn], sway[2][maxn];
vector<pair<long long, long long>> G[maxn];
void dfs(long long u, long long fa) {
  sz[u] = 1;
  for (auto e : G[u]) {
    long long v = e.first;
    if (ban[v]) continue;
    if (v == fa) continue;
    dfs(v, u);
    sz[u] += sz[v];
  }
}
void dfs2(long long u, long long fa, long long o, long long sum,
          long long dep) {
  if (dep > k) return;
  mx = max(mx, dep);
  add(way[dep], 1);
  add(cnt[dep], sum);
  for (auto e : G[u]) {
    long long v = e.first;
    if (ban[v] || v == fa) continue;
    dfs2(v, u, e.second, (sum + a[v]) % mod, dep + (e.second ^ o));
  }
}
long long work(long long *cnt, long long *way, long long *cnt2, long long *way2,
               long long val, long long mx, long long k) {
  if (k < 0) return 0;
  mx = min(mx, k);
  for (long long i = 0; i <= mx; ++i) {
    tc[i] = cnt[i];
    tw[i] = way[i];
    if (i) add(tc[i], tc[i - 1]), add(tw[i], tw[i - 1]);
  }
  long long res = 0;
  for (long long i = 0; i <= mx; ++i) {
    long long j = min(mx, k - i);
    add(res, 1ll * val * way2[i] % mod * tw[j] % mod);
    add(res, 1ll * cnt2[i] * tw[j] % mod);
    add(res, 1ll * way2[i] * tc[j] % mod);
  }
  return res;
}
void solve(long long u) {
  dfs(u, 0);
  long long r = u;
  while (1) {
    long long tmp = 0;
    for (auto e : G[u]) {
      long long v = e.first;
      if (ban[v] || sz[v] > sz[u]) continue;
      if (sz[v] * 2 > sz[r]) tmp = v;
    }
    if (!tmp) break;
    u = tmp;
  }
  long long SZ = min(sz[r], k);
  for (long long i = 0; i <= SZ; ++i) {
    scnt[0][i] = scnt[1][i] = 0;
    sway[0][i] = sway[1][i] = 0;
  }
  for (auto e : G[u]) {
    long long v = e.first;
    if (ban[v]) continue;
    long long o = e.second;
    mx = 0;
    dfs2(v, u, o, a[v], 0);
    for (long long i = 0; i <= mx; ++i) {
      add(ans, a[u] * way[i] * 2ll % mod);
      add(ans, cnt[i] * 2ll % mod);
    }
    sub(ans, work(cnt, way, cnt, way, a[u], mx, k));
    for (long long i = 0; i <= mx; ++i) {
      add(scnt[o][i], cnt[i]);
      add(sway[o][i], way[i]);
      cnt[i] = 0;
      way[i] = 0;
    }
  }
  add(ans, work(scnt[0], sway[0], scnt[0], sway[0], a[u], SZ, k));
  add(ans, work(scnt[0], sway[0], scnt[0], sway[0], a[u], SZ, k));
  add(ans, work(scnt[0], sway[0], scnt[1], sway[1], a[u], SZ, k - 1));
  add(ans, work(scnt[0], sway[0], scnt[1], sway[1], a[u], SZ, k - 1));
  ban[u] = 1;
  for (auto e : G[u]) {
    long long v = e.first;
    if (ban[v]) continue;
    solve(v);
  }
}
signed main() {
  cin >> n >> k;
  for (long long i = 1; i <= n; ++i) cin >> a[i];
  for (long long i = 1; i < n; ++i) {
    long long u, v, w;
    cin >> u >> v >> w;
    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }
  solve(1);
  ans = 1ll * ans * (mod + 1) / 2 % mod;
  for (long long i = 1; i <= n; ++i) {
    add(ans, a[i]);
  }
  cout << ans << endl;
}
