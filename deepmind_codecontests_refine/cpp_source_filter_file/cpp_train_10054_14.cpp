#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const long long N = 1e5 + 5, inf = 1e13;
long long n, a[5][N], dp[5][N], vis[5][N];
long long func(long long x, long long y) {
  if (vis[x][y]) return dp[x][y];
  long long ans = -inf;
  if (y == n) {
    if (x == 3)
      ans = a[x][y];
    else
      ans = a[x][y] + func(x + 1, y);
  } else {
    ans = max(ans, func(x, y + 1));
    if (x + 1 <= 3) ans = max(ans, func(x + 1, y + 1) + a[x + 1][y]);
    if (x + 2 <= 3)
      ans = max(ans, func(x + 2, y + 1) + a[x + 1][y] + a[x + 2][y]);
    if (x - 1 >= 1) ans = max(ans, func(x - 1, y + 1) + a[x - 1][y]);
    if (x - 2 >= 1)
      ans = max(ans, func(x - 2, y + 1) + a[x - 1][y] + a[x - 2][y]);
    if (x == 3 && y < n - 1)
      ans = max(ans, func(x - 2, y + 2) + a[x][y + 1] + a[x - 1][y + 1] +
                         a[x - 1][y] + a[x - 2][y] + a[x - 2][y + 1]);
    if (x == 1) {
      if (y == n - 1)
        ans = max(ans, a[x][y + 1] + a[x + 1][y + 1] + a[x + 1][y] +
                           a[x + 2][y] + a[x + 2][y + 1]);
      else
        ans = max(ans, func(x + 2, y + 2) + a[x][y + 1] + a[x + 1][y + 1] +
                           a[x + 1][y] + a[x + 2][y] + a[x + 2][y + 1]);
    }
    ans += a[x][y];
  }
  vis[x][y] = 1;
  return dp[x][y] = ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (long long i = 1; i <= 3; i++)
    for (long long j = 1; j <= n; j++) cin >> a[i][j];
  cout << func(1, 1);
}
