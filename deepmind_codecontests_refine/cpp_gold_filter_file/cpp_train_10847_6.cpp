#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const double eps = 1e-10;
const double pi = acos(-1.0);
const int maxn = 1e5 + 10;
const long long inf = 0x3f3f3f3f;
int L, R;
long long dp[40][2][2];
long long dfs(int p, bool lx, bool ly) {
  if (p == -1) return 1;
  long long &g = dp[p][lx][ly];
  if (g != -1) return g;
  g = 0;
  int mx = lx ? (L >> p) & 1 : 1, my = ly ? (R >> p) & 1 : 1;
  for (int i = 0; i <= mx; i++)
    for (int j = 0; j <= my; j++)
      if (!(i & j)) g += dfs(p - 1, mx == i && lx, ly && my == j);
  return g;
}
inline long long f(int l, int r) {
  if (l < 0) return 0;
  memset(dp, -1, sizeof dp);
  L = l, R = r;
  return dfs(log2(R + 1) + 1, 1, 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    cout << f(r, r) - 2 * f(l - 1, r) + f(l - 1, l - 1) << '\n';
  }
}
