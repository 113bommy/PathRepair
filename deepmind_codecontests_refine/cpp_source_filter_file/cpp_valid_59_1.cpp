#include <bits/stdc++.h>
using namespace std;
long long n, m, a[2005], b[2005], inset[2005], from[2005], vis[2005];
long long dt;
vector<long long> e[2005], vec;
void fuck(long long x) {
  while (!inset[x]) {
    dt += b[x];
    vec.push_back(x);
    inset[x] = 1;
    x = from[x];
  }
}
bool dfs(long long u, long long pw) {
  vis[u] = 1;
  for (auto v : e[u]) {
    if (pw <= a[v]) continue;
    if (inset[u] && inset[v]) continue;
    if (v == from[u]) continue;
    if (vis[v]) {
      fuck(v);
      fuck(u);
      return 1;
    } else {
      from[v] = u;
      if (dfs(v, pw + b[v])) return 1;
    }
  }
  return 0;
}
bool check(long long p) {
  vec.clear();
  for (long long i = (1); i <= (n); i++) inset[i] = 0;
  vec.push_back(1);
  inset[1] = 1;
  for (long long i = (1); i <= (n); i++) {
    for (long long j = (1); j <= (n); j++) from[j] = j, vis[j] = inset[j];
    dt = 0;
    for (auto x : vec) {
      if (dfs(x, p)) {
        break;
      }
    }
    p += dt;
  }
  return ((long long)vec.size()) == n;
}
void solve() {
  scanf("%lld%lld", &n, &m);
  for (long long i = (2); i <= (n); i++) scanf("%lld", &a[i]);
  for (long long i = (2); i <= (n); i++) scanf("%lld", &b[i]);
  for (long long i = (1); i <= (n); i++) e[i].clear();
  for (long long i = (1); i <= (m); i++) {
    long long u, v;
    scanf("%lld%lld", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  long long l = 1, r = 1e9, ans = 0;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%lld\n", ans);
}
signed main() {
  long long T;
  scanf("%lld", &T);
  while (T-- > 0) solve();
  return 0;
}
