#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const long double pi = acos(-1);
const int MOD = 1e9 + 7;
int g[22];
int n, m;
int dp[1 << 22];
int MAXI;
int solve(int mask) {
  if (mask == MAXI) return 0;
  if (dp[mask] != -1) return dp[mask];
  int ret = INF;
  for (int i = 0; i < n; i++) {
    if ((1 << i) & mask) {
      int nmask = mask | g[i];
      if (nmask != mask) ret = min(ret, solve(nmask) + 1);
    }
  }
  return dp[mask] = ret;
}
vector<int> r;
void rec(int mask) {
  for (int i = 0; i < n; i++) {
    if ((1 << i) & mask) {
      int nmask = mask | g[i];
      if (nmask != mask and solve(nmask) + 1 == solve(mask)) {
        r.push_back(i + 1);
        rec(nmask);
        return;
      }
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  MAXI = (1 << n) - 1;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--, v--;
    g[u] |= (1 << v);
    g[v] |= (1 << u);
  }
  for (int i = 0; i < n; i++) g[i] |= (1 << i);
  memset(dp, -1, sizeof(dp));
  int resp = INF;
  if (2 * m == (n * (n - 1))) {
    printf("%d\n", 0);
    return 0;
  }
  int idx = -1;
  for (int i = 0; i < n; i++)
    if (solve(1 << i) < resp) resp = solve(1 << i), idx = i;
  printf("%d\n", resp);
  rec(1 << idx);
  for (int x : r) printf("%d\n", x);
  return 0;
}
