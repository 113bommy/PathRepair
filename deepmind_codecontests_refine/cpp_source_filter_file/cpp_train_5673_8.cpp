#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200 * 1000 + 23, D = 1000 * 1000 * 1000 + 7;
int dp[MAXN], n, up[MAXN];
vector<int> g[MAXN];
bool is[MAXN];
int pw(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1, x = 1ll * x * x % D)
    if (y & 1) ret = 1ll * ret * x % D;
  return ret;
}
inline int bp(int x) { return (is[x] ? 0 : dp[x]); }
void inp();
int dfs(int, int);
void efs(int, int);
int main() {
  inp();
  dfs(0, -1);
  up[0] = 1;
  for (auto v : g[0]) efs(v, 0);
  for (int i = 0; i < n; i++) cout << (1ll * up[i] * dp[i]) % D << ' ';
  return 0;
}
void inp() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    g[--p].push_back(i), g[i].push_back(p);
  }
}
int dfs(int v, int p) {
  dp[v] = 1;
  for (auto u : g[v])
    if (u != p) {
      if ((dfs(u, v) + 1 == D) && !is[v])
        is[v] = true;
      else
        dp[v] = 1ll * dp[v] * (bp(u) + 1) % D;
    }
  return bp(v);
}
void efs(int v, int p) {
  if ((bp(v) + 1) == D)
    up[v] = (1ll * up[p] * dp[p] % D + 1) % D;
  else
    up[v] = (1ll * up[p] * bp(p) % D * pw(bp(v) + 1, D - 2) % D + 1) % D;
  for (auto u : g[v])
    if (u != p) efs(u, v);
}
