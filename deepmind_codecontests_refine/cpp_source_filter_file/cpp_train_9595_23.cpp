#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
const int M = 1e5 + 10;
const int MOD = ((7 * 17) << 23) + 1;
int n, k, a[N], jump[N], dp[N][N];
void add(int &x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < (int)(n); i++) cin >> a[i + 1];
  a[0] = -1e9;
  sort(a, a + n + 1);
  iota(jump, jump + n + 1, 0);
  long long int ans = 0;
  for (int d = 1; d * k <= M; d++) {
    for (int i = 0; i < (int)(n + 1); i++) {
      for (int j = 0; j < (int)(min(k + 1, i + 1)); j++) {
        if (i == 0)
          dp[i][j] = j == 0;
        else {
          dp[i][j] = dp[i - 1][j];
          while (a[i] - a[jump[i]] < d) --jump[i];
          if (j) add(dp[i][j], dp[jump[i]][j - 1]);
        }
      }
    }
    ans += dp[n][k];
  }
  cout << ans % MOD << endl;
  return 0;
}
