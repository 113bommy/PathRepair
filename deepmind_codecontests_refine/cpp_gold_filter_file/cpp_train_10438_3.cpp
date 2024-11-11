#include <bits/stdc++.h>
using namespace std;
long long re, gr, bl;
long long r[205], g[205], b[205];
long long dp[205][205][205];
long long ans(long long red, long long green, long long blue) {
  if (dp[red][green][blue] == -1) {
    long long x = r[red] * g[green];
    long long y = r[red] * b[blue];
    long long z = g[green] * b[blue];
    if (re != red && gr != green) x += ans(red + 1, green + 1, blue);
    if (re != red && bl != blue) y += ans(red + 1, green, blue + 1);
    if (gr != green && bl != blue) z += ans(red, green + 1, blue + 1);
    dp[red][green][blue] = max(x, max(y, z));
  }
  return dp[red][green][blue];
}
void solve() {
  cin >> re >> gr >> bl;
  for (long long i = 0; i < re; i++) cin >> r[i];
  for (long long i = 0; i < gr; i++) cin >> g[i];
  for (long long i = 0; i < bl; i++) cin >> b[i];
  sort(r, r + re, greater<long long>());
  sort(g, g + gr, greater<long long>());
  sort(b, b + bl, greater<long long>());
  memset(dp, -1, sizeof(dp));
  cout << ans(0, 0, 0) << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
