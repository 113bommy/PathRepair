#include <bits/stdc++.h>
using namespace std;
const long long Mod = 998244353;
long long qpw(long long a, long long b) {
  long long ans = 1;
  a = (a % Mod + Mod) % Mod;
  while (b) {
    if (b & 1) ans = ans * a % Mod;
    a = a * a % Mod;
    b >>= 1;
  }
  return ans;
}
long long w[55], a[55], W0, W1;
long long dp[55][55][55];
void add(long long &x, long long y) {
  x += y;
  if (x >= Mod) x -= Mod;
  if (x < 0) x += Mod;
}
long long inv(long long x) { return qpw(x, Mod - 2); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> w[i];
    if (a[i])
      W1 += w[i];
    else
      W0 += w[i];
  }
  for (int t = 0; t < n; ++t) {
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;
    int tmpW0 = W0, tmpW1 = W1;
    if (a[t])
      tmpW1 -= w[t];
    else
      tmpW0 -= w[t];
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j <= i && j <= tmpW0; j++) {
        for (int k = 0; k + j <= i; k++) {
          if (a[t]) {
            if (j + 1 <= tmpW0)
              add(dp[i + 1][j + 1][k],
                  dp[i][j][k] * (tmpW0 - j) % Mod *
                      inv(tmpW0 - j + tmpW1 + k + w[t] + i - j - k) % Mod);
            add(dp[i + 1][j][k + 1],
                dp[i][j][k] * (tmpW1 + k) % Mod *
                    inv(tmpW0 - j + tmpW1 + k + w[t] + i - j - k) % Mod);
            add(dp[i + 1][j][k],
                dp[i][j][k] * (w[t] + i - j - k) % Mod *
                    inv(tmpW0 - j + tmpW1 + k + w[t] + i - j - k) % Mod);
          } else if (!a[t] && w[t] >= i - j - k) {
            if (j + 1 <= tmpW0)
              add(dp[i + 1][j + 1][k],
                  dp[i][j][k] * (tmpW0 - j) % Mod *
                      inv(tmpW0 - j + tmpW1 + k + w[t] - i + j + k) % Mod);
            add(dp[i + 1][j][k + 1],
                dp[i][j][k] * (tmpW1 + k) % Mod *
                    inv(tmpW0 - j + tmpW1 + k + w[t] - i + j + k) % Mod);
            if (i - j - k + 1 <= w[t])
              add(dp[i + 1][j][k],
                  dp[i][j][k] * (w[t] - i + j + k) *
                      inv(tmpW0 - j + tmpW1 + k + w[t] - i + j + k) % Mod);
          }
        }
      }
    }
    long long ans = 0;
    for (int i = 0; i < 55; i++)
      for (int j = 0; j < 55 && m - i - j >= 0; ++j) {
        if (a[t]) {
          add(ans, dp[m][i][j] * (m - i - j + w[t]) % Mod);
        } else if (!a[t] && m - i - j <= w[t]) {
          add(ans, dp[m][i][j] * (w[t] - m + i + j) % Mod);
        }
      }
    cout << ans << "\n";
  }
  return 0;
}
