#include <bits/stdc++.h>
using namespace std;
const int N = 11;
const int mod = 1e9 + 7;
int n, m, k;
bool g[N][N];
long long dp[1 << N][1 << N];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a][b] = g[b][a] = 1;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      int mask = (1 << i) | (1 << j);
      dp[mask][mask] = 1;
    }
  for (int mask = 0; mask < (1 << n); mask++) {
    if (__builtin_popcount(mask) <= 2) continue;
    for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
      int a = -1;
      for (int i = 0; i < n; i++)
        if ((sub >> i) & 1) {
          a = i;
          break;
        }
      int pmask = mask ^ (1 << a);
      int psub = sub ^ (1 << a);
      for (int i = 0; i < n; i++) {
        if (((pmask >> i) & 1) == 0) continue;
        if ((psub >> i) & 1) continue;
        if (g[a][i]) {
          dp[mask][sub] += dp[pmask][psub | (1 << i)];
          dp[mask][sub] += dp[pmask][psub];
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < (1 << n); i++)
    if (__builtin_popcount(i) == k) ans += dp[(1 << n) - 1][i];
  cout << ans;
  return 0;
}
