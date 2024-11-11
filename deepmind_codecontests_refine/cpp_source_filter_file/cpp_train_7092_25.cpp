#include <bits/stdc++.h>
const int N = 3e5 + 10;
const int mod = 998244353;
using namespace std;
template <typename T1, typename T2>
void ckmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
void ckmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
template <typename T1, typename T2>
void addmo(T1 &a, T2 b) {
  a += b;
  if (a >= mod) a -= mod;
}
int n, f[N], sz[N];
long long ans;
vector<pair<int, int> > g[N];
int ok(int x) {
  while (x) {
    if (x % 10 != 4 && x % 10 != 7) return 0;
    x /= 10;
  }
  return 1;
}
void dfs(int x, int pre) {
  sz[x] = 1;
  for (pair<int, int> i : g[x])
    if (i.first ^ pre) {
      dfs(i.first, x);
      sz[x] += sz[i.first];
      if (ok(i.second))
        f[x] += sz[i.first];
      else
        f[x] += f[i.first];
    }
}
void Dfs(int x, int pre) {
  for (pair<int, int> i : g[x])
    if (i.first ^ pre) {
      if (ok(i.second))
        f[i.first] += sz[x] - sz[i.first];
      else
        f[i.first] = f[x];
      Dfs(i.first, x);
    }
  if (f[x] >= 2) ans += 1ll * f[x] * (f[x] - 1);
}
void Solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) g[i].clear();
  for (int i = 1, x, y, z; i < n; i++) {
    scanf("%d%d%d", &x, &y, &z);
    g[x].push_back({y, z}), g[y].push_back({x, z});
  }
  dfs(1, 0), Dfs(1, 0);
  printf("%lld\n", ans);
}
signed main() {
  int T = 1;
  while (T--) Solve();
  return 0;
}
