#include <bits/stdc++.h>
using namespace std;
long long res = 0LL;
int n, T, t[16], g[16];
long long dp[16][16][16][4];
const long long M = 1000000007LL;
long long C(int v1, int v2, int v3, int last) {
  if (v1 < 0 || v2 < 0 || v3 < 0) return 0LL;
  if (dp[v1][v2][v3][last] != -1 * 1LL) return dp[v1][v2][v3][last];
  if (v1 == 1 && v2 == 0 && v3 == 0 && last == 1) return 1LL;
  if (v1 == 0 && v2 == 1 && v3 == 0 && last == 2) return 1LL;
  if (v1 == 0 && v2 == 0 && v3 == 1 && last == 3) return 1LL;
  if (v1 == 0 && last == 1) return dp[v1][v2][v3][last] = 0LL;
  if (v2 == 0 && last == 2) return dp[v1][v2][v3][last] = 0LL;
  if (v3 == 0 && last == 3) return dp[v1][v2][v3][last] = 0LL;
  if (last == 1)
    return dp[v1][v2][v3][last] =
               (v1 * ((C(v1 - 1, v2, v3, 2) + C(v1 - 1, v2, v3, 3)) % M)) % M;
  else if (last == 2)
    return dp[v1][v2][v3][last] =
               (v2 * ((C(v1, v2 - 1, v3, 1) + C(v1, v2 - 1, v3, 3)) % M)) % M;
  else
    return dp[v1][v2][v3][last] =
               (v3 * ((C(v1, v2, v3 - 1, 1) + C(v1, v2, v3 - 1, 2)) % M)) % M;
}
int main() {
  cin >> n >> T;
  memset(dp, -1 * 1LL, sizeof dp);
  for (int i = 0; i < n; i++) cin >> t[i] >> g[i];
  for (int i = 1; i < (1 << n); i++) {
    int u = i;
    int cnt = 0, s = 0;
    int n[4] = {0, 0, 0, 0};
    while (u) {
      if (u % 2) {
        s += t[cnt];
        n[g[cnt]]++;
        if (s > T) break;
      }
      cnt++;
      u /= 2;
    }
    if (s == T) {
      res = (res + C(n[1], n[2], n[3], 1)) % M;
      res = (res + C(n[1], n[2], n[3], 2)) % M;
      res = (res + C(n[1], n[2], n[3], 3)) % M;
    }
  }
  cout << res << endl;
  return 0;
}
