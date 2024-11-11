#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e3 + 10;
long double dp[MAXN][MAXN];
long long p[MAXN];
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  long long n, m;
  cin >> n >> m;
  long double res = 0;
  for (long long i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = i + 1; j <= n; j++) {
      dp[i][j] = (p[j] < p[i]);
    }
  }
  for (long long i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;
    if (a > b) {
      swap(a, b);
    }
    for (long long j = b + 1; j <= n; j++) {
      long double e = (dp[a][j] + dp[b][j]) / 2;
      dp[a][j] = e;
      dp[b][j] = e;
    }
    for (long long j = a - 1; j >= 1; j--) {
      long double e = (dp[j][a] + dp[j][b]) / 2;
      dp[j][a] = e;
      dp[j][b] = e;
    }
    for (long long j = a + 1; j < b; j++) {
      long double e = dp[a][j], f = dp[j][b];
      dp[a][j] = (1 + e - f) / 2;
      dp[j][b] = (1 + f - e) / 2;
    }
    dp[a][b] = (long double)(1) / 2;
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = i + 1; j <= n; j++) {
      res += dp[i][j];
    }
  }
  cout << res;
}
