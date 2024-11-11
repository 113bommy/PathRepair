#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
const int BASE = 1e9 + 7;
int n, m;
int dp[N][N];
void Add(int &a, int b) {
  a = (a + b) % BASE;
  if (a >= BASE) a -= BASE;
  if (a < 0) a += BASE;
}
int Mul(int a, int b) { return 1LL * a * b % BASE; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  if (m <= 1) {
    cout << 0;
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    int p = 0, q = 0;
    for (int j = 2; j <= m; ++j) {
      Add(p, dp[i - 1][j]);
      Add(q, Mul(dp[i - 1][j], j));
      dp[i][j] = 1 + Mul(p, j + 1) - q;
      Add(dp[i][j], 0);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 2; j <= m; ++j) {
      int w = Mul(dp[i][j], dp[n - i + 1][j]);
      w = Mul(w, m - j + 1);
      Add(ans, w);
      if (i < n) {
        w = Mul(dp[i][j], dp[n - i][j]);
        w = Mul(w, m - j + 1);
        Add(ans, -w);
      }
    }
  cout << ans << '\n';
  return 0;
}
