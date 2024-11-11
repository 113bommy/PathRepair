#include <bits/stdc++.h>
using namespace std;
const int N = 40;
const int S = 20;
vector<int> G[N];
int col[N];
bool dfs(int v, int c, int& sz) {
  ++sz;
  col[v] = c;
  bool res = true;
  for (int u : G[v]) {
    if (col[u] == -1)
      res &= dfs(u, c ^ 1, sz);
    else if (col[u] != (col[v] ^ 1))
      res = false;
  }
  return res;
}
bitset<N> g[N];
bool is[1 << S];
long long dp[1 << S];
long long calc(int n) {
  int a = n / 2, b = n - n / 2;
  is[0] = true;
  for (int mask = 1; mask < (1 << a); ++mask) {
    int bit = 0;
    while (!((mask >> bit) & 1)) ++bit;
    is[mask] = is[mask ^ (1 << bit)];
    for (int bit2 = bit + 1; bit2 < a; ++bit2)
      if ((mask >> bit2) & 1) is[mask] &= g[bit][bit2];
  }
  dp[0] = 1;
  for (int mask = 1; mask < (1 << b); ++mask) {
    int bit = 0;
    while (!((mask >> bit) & 1)) ++bit;
    dp[mask] = dp[mask ^ (1 << bit)];
    for (int bit2 = bit + 1; bit2 < b; ++bit2) {
      if ((mask >> bit2) & 1) {
        if (!g[a + bit][a + bit2]) {
          dp[mask] = 0;
          break;
        }
      }
    }
  }
  for (int i = 0; i < b; ++i)
    for (int mask = 0; mask < (1 << b); ++mask)
      if ((mask >> i) & 1) dp[mask] += dp[mask ^ (1 << i)];
  long long ans = 0;
  bitset<N> cur;
  for (int mask = 0; mask < (1 << a); ++mask) {
    if (!is[mask]) continue;
    for (int i = 0; i < n; ++i) cur[i] = 1;
    for (int bit = 0; bit < a; ++bit) {
      if ((mask >> bit) & 1) cur = cur & g[bit];
    }
    int elon = 0;
    for (int i = 0; i < b; ++i)
      if (cur[i + a]) elon ^= (1 << i);
    ans += dp[elon];
  }
  return ans;
}
long long brute(int n) {
  is[0] = true;
  long long ans = 1;
  for (int mask = 1; mask < (1 << n); ++mask) {
    int bit = 0;
    while (!((mask >> bit) & 1)) ++bit;
    is[mask] = is[mask ^ (1 << bit)];
    for (int bit2 = bit + 1; bit2 < n; ++bit2)
      if ((mask >> bit2) & 1) is[mask] &= g[bit][bit2];
    if (is[mask]) ++ans;
  }
  return ans;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (m < 3) {
    printf("0");
    return 0;
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) g[i][j] = 1;
  while (m--) {
    static int u, v;
    scanf("%d%d", &u, &v);
    --u;
    --v;
    G[u].push_back(v);
    G[v].push_back(u);
    g[u][v] = g[v][u] = 0;
  }
  for (int v = 0; v < n; ++v) col[v] = -1;
  int cntComp = 0;
  int cntCompSz1 = 0;
  bool ok = true;
  for (int v = 0; v < n; ++v) {
    if (col[v] != -1) continue;
    ++cntComp;
    int sz = 0;
    if (!dfs(v, 0, sz)) ok = false;
    if (sz == 1) ++cntCompSz1;
  }
  long long ans = (1LL << n);
  ans -= (1LL << cntComp);
  ans -= 2 * calc(n);
  ans += 2 * (1LL << cntCompSz1);
  if (ok) ans += (1LL << cntComp);
  printf("%lld", ans);
}
