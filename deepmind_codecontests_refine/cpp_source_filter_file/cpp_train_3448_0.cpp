#include <bits/stdc++.h>
using namespace std;
long long n;
struct edge {
  long long v, w, next;
} e[300010 << 1];
long long eid, p[300010 << 1];
void insert(long long u, long long v, long long w) {
  e[++eid] = {v, w, p[u]};
  p[u] = eid;
}
long long w[300010];
long long ans = -1e18;
long long dp[300010];
void dfs(long long u, long long f, long long x) {
  long long sum = 0, maxx = -1e18;
  dp[u] = w[u];
  for (long long i = p[u]; i; i = e[i].next) {
    long long v = e[i].v;
    if (v == f) continue;
    dfs(v, u, max((long long)0, x) + w[u] - e[i].w);
    dp[u] = max(dp[u], dp[v] + w[u] - e[i].w);
    sum = max(sum, dp[v] + maxx - e[i].w);
    maxx = max(maxx, w[u] - e[i].w + dp[v]);
  }
  ans = max(ans, max(sum, maxx + max((long long)0, x)));
}
int main() {
  cin >> n;
  for (long long i = 1; i <= n; ++i) cin >> w[i];
  for (long long i = 1; i < n; ++i) {
    long long u, v, w;
    cin >> u >> v >> w;
    insert(u, v, w);
    insert(v, u, w);
  }
  dfs(1, 1, 0);
  cout << ans << endl;
  return 0;
}
