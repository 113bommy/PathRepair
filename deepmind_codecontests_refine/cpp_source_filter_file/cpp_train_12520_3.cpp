#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 5;
const long long MAXM = 6e4 + 5;
const long long MOD = 1e9 + 7;
long long siz[MAXN], cnt[MAXN];
long long prm[MAXM];
vector<long long> adj[MAXN];
long long n, m;
void Dfs(long long u, long long fa) {
  siz[u] = 1;
  for (long long v : adj[u]) {
    if (v != fa) {
      Dfs(v, u);
      siz[u] += siz[v];
    }
  }
  cnt[u] = siz[u] * (n - siz[u]);
}
void Solve() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    adj[i].clear();
  }
  for (long long i = 1; i < n; i++) {
    long long u, v;
    scanf("%lld%lld", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  scanf("%lld", &m);
  for (long long i = 1; i <= m; i++) {
    scanf("%lld", prm + i);
  }
  sort(prm + 1, prm + 1 + m);
  if (m >= n) {
    for (long long i = n; i <= m; i++) {
      prm[n - 1] = prm[n - 1] * prm[i] % MOD;
    }
  } else {
    for (long long i = m + 1; i <= n; i++) {
      prm[i] = 1;
    }
    sort(prm + 1, prm + n);
  }
  Dfs(1, 0);
  sort(cnt + 1, cnt + 1 + n);
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    cnt[i] %= MOD;
    prm[i] %= MOD;
  }
  for (long long i = 2; i <= n; i++) {
    ans = (ans + cnt[i] * prm[i - 1]) % MOD;
  }
  printf("%lld\n", ans);
}
signed main() {
  long long t;
  scanf("%lld", &t);
  while (t--) {
    Solve();
  }
}
