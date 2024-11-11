#include <bits/stdc++.h>
using namespace std;
function<void(void)> ____ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
};
const int MAXN = 1111;
const int MOD = 1e9 + 7;
vector<int> GS[MAXN], GT[MAXN];
int n, m, fac[20], inv[20], rfac[20],
    prime[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
int ret, sz[20], hax[20], fas[MAXN], fat[20];
set<int> vishash;
void dfss(int u, int par) {
  fas[u] = par;
  for (int v : GS[u])
    if (v != par) dfss(v, u);
}
void dfs(int u, int par) {
  sz[u] = hax[u] = 1;
  fat[u] = par;
  for (int v : GT[u]) {
    if (v == par) continue;
    dfs(v, u);
    sz[u] += sz[v];
    hax[u] = (hax[u] + hax[v] * prime[sz[v]]) % MOD;
  }
}
int f[20][MAXN];
void match(int u) {
  for (int v : GT[u])
    if (v != fat[u]) match(v);
  if ((GT[u].size() == 1 and fat[u]) or GT[u].empty()) {
    for (int i = 1; i <= n; i++) f[u][i] = 1;
    return;
  }
  vector<int> sont;
  map<int, int> cnt;
  for (int v : GT[u])
    if (v != fat[u]) {
      sont.push_back(v);
      cnt[hax[v]]++;
    }
  int ff = 1;
  for (auto p : cnt) ff = (1ll * ff * rfac[p.second]) % MOD;
  for (int x = 1; x <= n; x++) {
    vector<int> sons;
    for (int v : GS[x])
      if (v != fas[x]) sons.push_back(v);
    vector<vector<int> > dp(2, vector<int>(1 << sont.size()));
    dp[0][0] = 1;
    int tag = 1;
    for (int i = 0; i < (int)sons.size(); i++, tag ^= 1) {
      dp[tag] = dp[tag ^ 1];
      for (int msk = 0; msk < (1 << sont.size()); msk++) {
        for (int bit = 0; bit < (int)sont.size(); bit++) {
          if (msk >> bit & 1) continue;
          dp[tag][msk | (1 << bit)] =
              (dp[tag][msk | (1 << bit)] +
               1ll * dp[tag ^ 1][msk] * f[sont[bit]][sons[i]]) %
              MOD;
        }
      }
    }
    f[u][x] = 1ll * dp[tag ^ 1][(1 << sont.size()) - 1] * ff % MOD;
  }
}
void test(int id) {
  dfs(id, 0);
  if (vishash.count(hax[id])) return;
  vishash.insert(hax[id]);
  memset(f, 0, sizeof(f));
  match(id);
  for (int i = 1; i <= n; i++) ret = (ret + f[id][i]) % MOD;
}
void solve() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    GS[u].push_back(v);
    GS[v].push_back(u);
  }
  scanf("%d", &m);
  for (int i = 1; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    GT[u].push_back(v);
    GT[v].push_back(u);
  }
  dfss(1, 0);
  for (int i = 1; i <= m; i++) test(i);
  cout << ret << endl;
}
int main() {
  fac[0] = rfac[0] = inv[1] = 1;
  for (int i = 1; i < 20; i++) fac[i] = 1ll * i * fac[i - 1] % MOD;
  for (int i = 2; i < 20; i++)
    inv[i] = 1ll * (MOD - MOD / i) * inv[MOD % i] % MOD;
  for (int i = 1; i < 20; i++) rfac[i] = 1ll * inv[i] * rfac[i - 1] % MOD;
  solve();
  return 0;
}
