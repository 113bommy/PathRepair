#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;
const int N = 51;
int n, hei, m;
int ql[N], qr[N], lvl[N], cost[N];
int dp[N][N][N];
int penalty[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> hei >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> ql[i] >> qr[i] >> lvl[i] >> cost[i];
  }
  for (int h = 0; h <= hei; ++h) {
    for (int l = n; l >= 1; --l) {
      for (int r = l; r <= n; ++r) {
        for (int x = l; x <= r; ++x) {
          fill_n(penalty, N, 0);
          for (int i = 1; i <= m; ++i) {
            if (l <= ql[i] && ql[i] <= x && x <= qr[i] && qr[i] <= r) {
              penalty[lvl[i] + 1] += cost[i];
            }
          }
          for (int i = 1; i < N; ++i) {
            penalty[i] += penalty[i - 1];
          }
          for (int mx = 0; mx <= h; ++mx) {
            int cur = mx * mx - penalty[mx];
            dp[h][l][r] =
                max(dp[h][l][r], cur + dp[mx][l][x - 1] + dp[mx][x + 1][r]);
          }
        }
      }
    }
  }
  cout << dp[hei][1][n] << "\n";
  return 0;
}
