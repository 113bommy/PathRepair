#include <bits/stdc++.h>
using namespace std;
template <class U, class T>
void Max(U &first, T second) {
  if (first < second) first = second;
}
template <class U, class T>
void Min(U &first, T second) {
  if (first > second) first = second;
}
template <class T>
void add(int &a, T b) {
  a = (a + b) % 1000000007;
}
inline int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
inline long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}
int pow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1LL * ans * a % 1000000007;
    a = 1LL * a * a % 1000000007;
    b >>= 1;
  }
  return ans;
}
int pow(int a, int b, int c) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1LL * ans * a % c;
    a = 1LL * a * a % c;
    b >>= 1;
  }
  return ans;
}
vector<int> g[300010];
long long dp[300010], ans;
int a[300010], K;
void dfs(int u, int fa = -1) {
  dp[u] = a[u];
  for (auto &v : g[u]) {
    if (v == fa) continue;
    dfs(v, u);
    dp[u] += max(dp[v], 0LL);
  }
  Max(ans, dp[u]);
}
void dfs1(int u, int fa = -1) {
  dp[u] = a[u];
  for (auto &v : g[u]) {
    if (v == fa) continue;
    dfs1(v, u);
    dp[u] += max(dp[v], 0LL);
  }
  if (dp[u] == ans) K++, dp[u] = 0;
}
int main() {
  int ca = 0, T, k, i, j, m = 0, n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &j, &k);
    j--, k--;
    g[j].push_back(k), g[k].push_back(j);
  }
  ans = -1e18;
  K = 0;
  dfs(0);
  dfs1(0);
  printf("%lld %lld\n", ans * K, K);
}
