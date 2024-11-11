#include <bits/stdc++.h>
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;
const int INF = 1e9 + 100;
const long long LINF = 1e18 + 100;
int n, m, q;
pair<int, int> edge[15];
int a[15], b[15], c[15];
long long dp[15][1 << 15];
int check(int m1, int m2, int v) {
  for (int i = (0); i < (q); i++) {
    if (!((m1 >> a[i] & 1 && m2 >> b[i] & 1) ||
          (m1 >> b[i] & 1 && m2 >> a[i] & 1)))
      continue;
    if (c[i] != v) return -2;
  }
  int u = -1;
  for (int i = (0); i < (m); i++) {
    int x = edge[i].first, y = edge[i].second;
    if (!((m1 >> x & 1 && m2 >> y & 1) || (m1 >> y & 1 && m2 >> x & 1)))
      continue;
    if ((x != v && y != v) || u >= 0) return -2;
    u = x ^ y ^ v;
  }
  return u;
}
long long solve(int v, int mask) {
  if (dp[v][mask] >= 0) return dp[v][mask];
  if (!(mask >> v & 1)) return 0;
  if (__builtin_popcount(mask) == 1) return dp[v][mask] = 1;
  mask ^= (1 << v);
  long long res = 0;
  for (int sub = mask; sub; sub = (sub - 1) & mask)
    if ((sub & -sub) == (mask & -mask)) {
      int rem = mask ^ sub;
      rem |= (1 << v);
      int u = check(rem, sub, v);
      if (u == -2) continue;
      if (u == -1) {
        for (int u = (0); u < (n); u++)
          if (u != v && sub >> u & 1) {
            res += solve(v, rem) * solve(u, sub);
          }
      } else {
        if (u != v && sub >> u & 1) res += solve(v, rem) * solve(u, sub);
      }
    }
  return dp[v][mask ^ (1 << v)] = res;
}
int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m >> q;
  for (int i = (0); i < (m); i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    edge[i] = {x, y};
  }
  for (int i = (0); i < (q); i++) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;
    b[i]--;
    c[i]--;
    if (a[i] == b[i] && a[i] != c[i]) return cout << "0\n", 0;
  }
  memset(dp, -1, sizeof(dp));
  cout << solve(0, (1 << n) - 1) << '\n';
  return 0;
}
