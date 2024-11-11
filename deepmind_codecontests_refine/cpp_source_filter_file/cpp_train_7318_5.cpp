#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 20, M = 1000 + 20, inf = 1e9;
vector<int> a[N];
int dp[N][M], sum[N][N];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x;
    for (int j = 0; j < x; j++) {
      cin >> y;
      a[i].push_back(y);
    }
  }
  for (int i = 0; i < n; i++) {
    int sum2 = 0;
    for (auto v : a[i]) sum2 += v;
    sum[i][a[i].size()] = sum2;
    for (int st = 0; st < a[i].size(); st++) {
      int sum3 = 0;
      for (int en = st + 1; en <= a[i].size(); en++) {
        sum3 += a[i][en - 1];
        sum[i][a[i].size() - en + st] =
            max(sum[i][a[i].size() - en + st], sum2 - sum3);
      }
    }
  }
  for (int i = 0; i <= n; i++)
    for (int j = 1; j <= m; j++) dp[i][j] = -inf;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int k = 0; k <= min((int)a[i - 1].size(), j); k++)
        dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + sum[i - 1][k]);
  cout << dp[n][m] << "\n";
  return 0;
}
