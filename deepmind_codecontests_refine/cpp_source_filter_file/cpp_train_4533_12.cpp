#include <bits/stdc++.h>
using namespace std;
const int N = 20;
const int mod = 1e9 + 7;
int n, m, msk[1 << N], dp[N][1 << N];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string second;
    cin >> second;
    for (int j = 0; j < m; j++) msk[j] |= (1 << j) * (second[j] - '0');
  }
  for (int i = 0; i < m; i++) dp[0][msk[i]]++;
  for (int i = 1; i <= n; i++) {
    for (int mask = 0; mask < (1 << n); mask++) {
      int now = (i > 1 ? (i - 2 - n) * dp[i - 2][mask] : 0);
      for (int p = 0; p < n; p++) now += dp[i - 1][mask ^ (1 << p)];
      dp[i][mask] = now;
    }
  }
  int ans = n * m;
  for (int mask = 0; mask < (1 << n); mask++) {
    int tmp = 0;
    for (int i = 0; i <= n; i++) tmp += min(n - i, i) * dp[i][mask];
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}
