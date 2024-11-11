#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
long double dp[N][N];
bool mp[2][N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int ci = n, cj = n;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    ci -= mp[0][x] == 0;
    cj -= mp[1][y] == 0;
    mp[0][x] = mp[1][y] = 1;
  }
  long double dv = n * n;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) {
      if (i == 0 && j == 0) continue;
      long double p1 = (n - j) * i / dv;
      long double p2 = (n - i) * j / dv;
      long double p3 = i * j / dv;
      long double p4 = 1 - (p1 + p2 + p3);
      if (i > 0) dp[i][j] += (1 + dp[i - 1][j]) * p1;
      if (j > 0) dp[i][j] += (1 + dp[i][j - 1]) * p2;
      if (i > 0 && j > 0) dp[i][j] += (1 + dp[i - 1][j - 1]) * p3;
      dp[i][j] += p4;
      p4 = 1 - p4;
      if (p4 > 0) dp[i][j] /= p4;
    }
  cout << fixed << setprecision(9) << dp[ci][cj] << "\n";
}
