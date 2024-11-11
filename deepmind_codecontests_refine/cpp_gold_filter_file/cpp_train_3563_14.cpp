#include <bits/stdc++.h>
using namespace std;
mt19937 randint(chrono::steady_clock::now().time_since_epoch().count());
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, k;
  cin >> n >> k;
  vector<vector<long long>> a(n, vector<long long>(n));
  for (auto& row : a)
    for (auto& x : row) cin >> x;
  long long out = 1000000000000000000ll;
  vector<int> c(n, -1);
  vector<vector<long long>> dp(k + 1, vector<long long>(n));
  for (int t = 0; t < 4000; t++) {
    for (int i = 0; i < n; i++) c[i] = randint() % 2;
    for (int x = 0; x <= k; x++)
      for (int i = 0; i < n; i++) dp[x][i] = 1000000000000000000ll;
    dp[0][0] = 0;
    for (int x = 1; x <= k; x++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          if (c[i] != c[j]) {
            dp[x][i] = min(dp[x][i], dp[x - 1][j] + a[j][i]);
            dp[x][j] = min(dp[x][j], dp[x - 1][i] + a[i][j]);
          }
    out = min(out, dp[k][0]);
  }
  cout << out << "\n";
}
