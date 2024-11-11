#include <bits/stdc++.h>
using namespace std;
const int MAXM = 2501;
const int MAXN = 55;
const int MOD = 1e9 + 7;
int cnt2[MAXN][MAXM] = {0};
int cnt01[MAXN][MAXN][MAXM] = {0};
int kind[MAXN][MAXN][MAXN][4] = {0}, tot[MAXN][MAXN][MAXN] = {0};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, T;
  cin >> n >> T;
  vector<int> fac = {1};
  for (int i = 1; i < 200; ++i) fac.push_back(1ll * fac.back() * i % MOD);
  cnt2[0][0] = cnt01[0][0][0] = 1;
  for (int i = 0; i < n; ++i) {
    int t, g;
    cin >> t >> g;
    --g;
    if (g == 2) {
      for (int i = n; i >= 0; --i) {
        for (int j = T - t; j >= 0; --j) {
          (cnt2[i + 1][j + t] += cnt2[i][j]) %= MOD;
        }
      }
    } else {
      for (int i = n; i >= 0; --i) {
        for (int j = n - i; j >= 0; --j) {
          for (int k = T - t; k >= 0; --k) {
            (cnt01[i + (g == 0)][j + (g == 1)][k + t] += cnt01[i][j][k]) %= MOD;
          }
        }
      }
    }
  }
  kind[0][0][0][3] = 1;
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j + i <= n; ++j)
      for (int k = 0; k + j + i <= n; ++k) {
        for (int a : {0, 1, 2})
          for (int b : {0, 1, 2, 3}) {
            if (a != b) {
              (kind[i + (a == 0)][j + (a == 1)][k + (a == 2)][a] +=
               kind[i][j][k][b]) %= MOD;
            }
          }
      }
  for (int i = n; i >= 0; --i)
    for (int j = n - i; j >= 0; --j)
      for (int k = n - i - j; k >= 0; --k)
        for (int b : {0, 1, 2}) (tot[i][j][k] += kind[i][j][k][b]) %= MOD;
  int ans = 0;
  for (int i = 0; i <= n; ++i)
    for (int j = 0; i + j <= n; ++j) {
      for (int k = 0; i + j + k <= n; ++k) {
        for (int t = 0; t <= T; ++t) {
          (ans += 1ll * tot[i][j][k] * cnt2[k][t] % MOD * cnt01[i][j][T - t] %
                  MOD * fac[i] % MOD * fac[j] % MOD * fac[k] % MOD) %= MOD;
        }
      }
    }
  cout << ans << '\n';
}
