#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll r, g, b;
ll ar[200], br[200], cr[200];
ll dp[200][200][200];
ll solve(int x, int y, int z) {
  if (x > r || y > g || z > b) {
    return -1e9;
  }
  if ((x == r) + (y == g) + (z == b) >= 2) return 0;
  ll &val = dp[x][y][z];
  if (val != -1) return val;
  return dp[x][y][z] = max(ar[x] * br[y] + solve(x + 1, y + 1, z),
                           max(cr[z] * br[y] + solve(x, y + 1, z + 1),
                               ar[x] * cr[z] + solve(x + 1, y, z + 1)));
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> r >> g >> b;
  for (auto &x : dp)
    for (auto &y : x)
      for (auto &z : y) z = -1;
  for (int i = 0; i < r; ++i) cin >> ar[i];
  for (int i = 0; i < g; ++i) cin >> br[i];
  for (int i = 0; i < b; ++i) cin >> cr[i];
  sort(ar, ar + r, greater<ll>());
  sort(br, br + g, greater<ll>());
  sort(cr, cr + b, greater<ll>());
  cout << solve(0, 0, 0) << endl;
  return 0;
}
