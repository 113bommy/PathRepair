#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, mod = 1e9 + 7, L = 31;
int get(int x, int y, int k) {
  if (x == -1 || y == -1) return 0;
  int dp[L + 1][2][2][2], cnt[L + 1][2][2][2];
  memset(dp, 0, sizeof(dp));
  memset(cnt, 0, sizeof(cnt));
  cnt[L][1][1][1] = 1;
  for (int i = L - 1; i >= 0; i--) {
    for (int prex = 0; prex < 2; prex++) {
      for (int prey = 0; prey < 2; prey++) {
        for (int prek = 0; prek < 2; prek++) {
          for (int ix = 0; ix < 2; ix++) {
            for (int iy = 0; iy < 2; iy++) {
              if (prex && ix && !((1 << i) & x)) continue;
              if (prey && iy && !((1 << i) & y)) continue;
              if ((ix ^ iy) && prek && !((1 << i) & k)) continue;
              dp[i][prex & (min(((1 << i) & x), 1) == ix)]
                [prey & (min(((1 << i) & y), 1) == iy)]
                [prek & (min(((1 << i) & k), 1) == (ix ^ iy))] +=
                  (dp[i + 1][prex][prey][prek] +
                   1ll * cnt[i + 1][prex][prey][prek] * (1 << i) * (ix ^ iy) %
                       mod) %
                  mod;
              cnt[i][prex & (min(((1 << i) & x), 1) == ix)]
                 [prey & (min(((1 << i) & y), 1) == iy)]
                 [prek & (min(((1 << i) & k), 1) == (ix ^ iy))] +=
                  cnt[i + 1][prex][prey][prek];
              dp[i][prex & (min(((1 << i) & x), 1) == ix)]
                [prey & (min(((1 << i) & y), 1) == iy)]
                [prek & (min(((1 << i) & k), 1) == (ix ^ iy))] %= mod;
              cnt[i][prex & (min(((1 << i) & x), 1) == ix)]
                 [prey & (min(((1 << i) & y), 1) == iy)]
                 [prek & (min(((1 << i) & k), 1) == (ix ^ iy))] %= mod;
            }
          }
        }
      }
    }
  }
  int ret = 0;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++) {
        ret += (dp[0][i][j][k] + cnt[0][i][j][k]) % mod;
        ret %= mod;
      }
  return ret;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int x, y, z, w, k;
    cin >> x >> y >> z >> w >> k;
    x--;
    y--;
    z--;
    w--;
    k--;
    int ans = (get(z, w, k) - get(z, y - 1, k) - get(x - 1, w, k) +
               get(x - 1, y - 1, k)) %
              mod;
    if (ans < 0) ans += mod;
    cout << ans << "\n";
  }
  return 0;
}
