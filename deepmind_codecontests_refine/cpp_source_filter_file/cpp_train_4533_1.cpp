#include <bits/stdc++.h>
using namespace std;
const int N = 25, M = 1e5 + 5;
int n, col[M], dp[N][(1 << 20)], m;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    for (int j = 1; j <= m; ++j) {
      if (s[j - 1] == '1') col[j] ^= (1 << (i - 1));
    }
  }
  for (int i = 1; i <= m; ++i) {
    dp[0][col[i]] = 1;
  }
  for (int k = 1; k <= n; ++k) {
    for (int mask = 0; mask < (1 << n); ++mask) {
      if (k > 1) dp[k][mask] = (k - 2 - n) * dp[k - 2][mask];
      for (int p = 0; p < n; ++p) dp[k][mask] += dp[k - 1][mask ^ (1 << p)];
      dp[k][mask] /= k;
    }
  }
  int res = (int)1e9;
  for (int mask = 0; mask < (1 << n); ++mask) {
    int tmp = 0;
    for (int k = 0; k <= n; ++k) tmp += dp[k][mask] * min(k, n - k);
    res = min(res, tmp);
  }
  cout << res << endl;
  return 0;
}
