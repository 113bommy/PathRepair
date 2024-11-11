#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2000 + 10, maxq = 2e5 + 10, inf = 1e9 + 10,
                radical = 300, mod = 1e9 + 7;
long long dp[maxn][maxn], f[maxn], a[maxn];
bool j[maxn], A[maxn];
inline long long solve(int x, int y) {
  if (x < 0 || y < 0) return 0;
  if (x == 0) return f[y];
  if (dp[x][y] != -1) return dp[x][y];
  return dp[x][y] = solve(x - 2, y + 1) * (x - 1) + solve(x - 1, y) * y;
}
int main() {
  int n;
  cin >> n;
  f[0] = 1;
  memset(dp, -1, sizeof dp);
  for (long long i = 1; i <= n; f[i] = (f[i - 1] * i) % mod, i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    if (a[i] == -1)
      j[i] = 1;
    else
      A[a[i]] = true;
  }
  int x = 0, y = 0;
  for (int i = 1; i <= n; i++)
    if (!A[i]) {
      if (j[i])
        x++;
      else
        y++;
    }
  cout << solve(x, y);
  return 0;
}
