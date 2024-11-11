#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
const long long mod = 1e9 + 7;
vector<int> g[maxn], cpt[maxn];
int d[maxn];
int dfn[maxn], low[maxn], cnt, clk;
bool vis[maxn];
stack<int> q;
long long tot = 0;
long long inv[17], binv[maxn], sum[maxn];
long long qpow(long long x, long long p) {
  long long y = 1;
  while (p) {
    if (p & 1) y = y * x % mod;
    x = x * x % mod, p >>= 1;
  }
  return y;
}
void Mod(long long &x) {
  if (x < 0) x += mod;
  if (x > mod) x -= mod;
}
void tarjan(int x) {
  dfn[x] = low[x] = ++clk;
  q.push(x);
  vis[x] = 1;
  for (auto to : g[x])
    if (!dfn[to]) {
      tarjan(to);
      low[x] = min(low[x], low[to]);
      if (low[to] >= dfn[x]) {
        cnt++;
        int cur;
        do {
          cur = q.top();
          q.pop();
          cpt[cnt].push_back(cur);
        } while (cur != to);
        cpt[cnt].push_back(x);
        int sz = cpt[cnt].size();
        if (sz > 2) {
          for (int j : cpt[cnt]) sum[j] = (sum[j] + binv[sz]) % mod;
          Mod(tot += binv[sz]);
        }
      }
    } else
      low[x] = min(low[x], dfn[to]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  binv[0] = 1;
  for (int i = 1; i <= 16; i++) inv[i] = qpow(i, mod - 2);
  for (int i = 1; i < maxn; i++) binv[i] = binv[i - 1] * inv[2] % mod;
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    d[x]++, d[y]++;
  }
  if (n == 1) {
    cout << inv[4] << '\n';
    return 0;
  }
  tarjan(1);
  long long ans = 1ll * n * (n + 1) % mod * inv[4] % mod;
  for (int i = 1; i <= n; i++)
    for (auto j : g[i]) {
      if (i < j) continue;
      int num = d[i] + d[j] - 2;
      ans += inv[16] * (m - num - 1) + inv[8] * num + inv[4];
      ans %= mod;
    }
  long long ab = (inv[8] * (n - 2) % mod * m % mod + m * inv[2] % mod) % mod,
            ac = 0, bc = 0;
  for (int i = 1; i <= cnt; i++) {
    int sz = cpt[i].size();
    if (sz <= 2) continue;
    long long now = 0, tmp = 0;
    for (auto j : cpt[i]) now += sum[j] - binv[sz], tmp += d[j] - 2;
    Mod(now %= mod);
    ans += binv[sz] * (tot - binv[sz] + now + 1);
    ans %= mod;
    ac += binv[sz] * (n - sz) % mod * inv[2] % mod + binv[sz] * sz % mod;
    ac %= mod;
    bc += binv[sz] * (m - tmp - sz) % mod * inv[4] +
          binv[sz] * tmp % mod * inv[2] + binv[sz] * sz % mod;
    bc %= mod;
  }
  ans = ans - 2 * ab - 2 * bc + 2 * ac;
  ans %= mod;
  long long E = (n * inv[2] - m * inv[4] + tot) % mod;
  ans = ans - E * E;
  Mod(ans %= mod);
  cout << ans << '\n';
  return 0;
}
