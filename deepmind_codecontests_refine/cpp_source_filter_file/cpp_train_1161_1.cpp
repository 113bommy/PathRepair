#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int man = 2e5 + 10;
const long long mod = 1e9 + 7;
vector<int> sp[man];
long long fac[man];
void init(int n) {
  fac[0] = fac[1] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % mod;
}
long long ans = 1;
void dfs(int u, int f) {
  int cnt = (u != 1 ? 1 : 0);
  for (auto v : sp[u]) {
    if (v == f) continue;
    cnt++;
    dfs(v, u);
  }
  ans = ans * fac[cnt] % mod;
}
signed main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    sp[u].push_back(v);
    sp[v].push_back(u);
  }
  init(n);
  dfs(1, 1);
  ans = ans * n % mod;
  printf("%lld\n", ans);
  return 0;
}
