#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_N = 100;
int dp[1 + MAX_N][1 + MAX_N];
int comb[1 + MAX_N][1 + MAX_N];
int n, m, k, p;
void prec_comb(int n) {
  for (int i = 0; i <= n; i++) {
    comb[i][0] = 1;
    for (int j = 1; j <= i; j++)
      comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % p;
  }
}
void solve_test() {
  cin >> n >> m >> k >> p;
  prec_comb(2 * n);
  dp[0][0] = dp[1][1] = 1;
  for (int i = 2; i <= n; i++) dp[i][1] = 1ll * dp[i - 1][1] * i % p;
  for (int it = 2; it <= m; it++) {
    for (int a = n; a > 0; a--) {
      for (int b = 0; b <= min(k, a); b++) {
        int offset = 0;
        if (b == 0 || it + b <= a + 1) {
          for (int x = 0; x < a; x++) {
            int cnt = 0;
            for (int y = max(0, b - a + 1 + x); y <= min(x, b); y++) {
              int to_add = 1ll * dp[x][y] * dp[a - x - 1][b - y] % p;
              cnt += to_add;
              if (cnt >= p) cnt -= p;
            }
            int to_add = 1ll * cnt * comb[a - 1][x] % p;
            offset += to_add;
            if (offset >= p) offset -= p;
          }
        }
        dp[a][b] = offset;
      }
    }
  }
  if (m + k <= n + 1)
    cout << dp[n][k] << "\n";
  else
    cout << "0\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve_test();
  return 0;
}
