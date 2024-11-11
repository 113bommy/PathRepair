#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
vector<long long> G[200005];
long long sif[200005][2];
long long val[200005], ans;
void dfs1(long long now, long long pa) {
  sif[now][0] = 1;
  for (long long i : G[now]) {
    if (i == pa) continue;
    dfs1(i, now);
    sif[now][0] += sif[i][1];
    sif[now][1] += sif[i][0];
  }
}
void dfs2(long long now, long long pa, long long up0, long long up1) {
  long long tot0 = up0 + 1, tot1 = up1;
  for (long long i : G[now]) {
    if (i == pa) continue;
    tot0 += sif[i][1];
    tot1 += sif[i][0];
  }
  ans += 1ll * (up0 - up1) * (tot0 + tot1 - up0 - up1) % mod * val[now] % mod;
  ans = (ans % mod + mod) % mod;
  for (long long i : G[now]) {
    if (i == pa) continue;
    ans += 1ll * (sif[i][1] - sif[i][0]) *
           (tot0 + tot1 - sif[i][0] - sif[i][1]) % mod * val[now] % mod;
    ans = (ans % mod + mod) % mod;
  }
  for (long long i : G[now]) {
    if (i == pa) continue;
    dfs2(i, now, tot1 - sif[i][0], tot0 - sif[i][1]);
  }
}
int32_t main() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; ++i) cin >> val[i];
  for (long long i = 1; i <= n; ++i) {
    ans += val[i] * n % mod;
    ans = (ans % mod + mod) % mod;
  }
  for (long long i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs1(1, 1);
  dfs2(1, 1, 0, 0);
  cout << (ans % mod + mod) % mod << endl;
}
