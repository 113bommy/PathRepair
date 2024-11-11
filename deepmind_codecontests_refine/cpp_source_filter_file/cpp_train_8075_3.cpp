#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 5;
long long n;
long long a[maxn];
long long f[maxn][2];
long long ans = 0;
vector<long long> AdjList[maxn];
void dfs(long long s, long long p, long long bit) {
  long long t = a[s] >> bit & 1;
  f[s][t] = 1;
  f[s][1 ^ t] = 0;
  for (long long u : AdjList[s]) {
    if (u == p) continue;
    dfs(u, s, bit);
    ans += (1ll << bit) * (1ll * f[u][0] * f[s][1] + 1ll * f[u][1] * f[s][0]);
    f[s][0] += f[u][0 ^ t];
    f[s][1] += f[u][1 ^ t];
  }
}
signed main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    ans += a[i];
  }
  for (long long i = 1; i < n; i++) {
    long long u, v;
    cin >> u >> v;
    AdjList[u].push_back(v);
    AdjList[v].push_back(u);
  }
  for (long long i = 0; i < 4; i++) {
    dfs(1, 1, i);
  }
  cout << ans;
}
