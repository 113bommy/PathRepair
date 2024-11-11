#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
const long double EPS = 1e-9;
const int N = 31;
const int K = 51;
int dp[N][N][K];
void init_dp() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < K; ++k) dp[i][j][k] = 1e8 + 1e8;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  srand(time(NULL));
  cout << fixed << setprecision(7);
  init_dp();
  for (int n = 0; n < N; ++n) {
    for (int m = 0; m < N; ++m) {
      for (int k = 0; k < K; ++k) {
        if (k == 0 || k == n * m) dp[n][m][k] = 0;
        for (int a = 0; a <= n / 2; ++a) {
          for (int dk = 0; dk <= k; ++dk) {
            dp[n][m][k] = min(
                dp[n][m][k], dp[a][m][dk] + dp[n - a][m][k - dk] + ((m) * (m)));
          }
        }
        for (int b = 0; b <= m / 2; ++b) {
          for (int dk = 0; dk <= k; ++dk) {
            dp[n][m][k] = min(
                dp[n][m][k], dp[n][b][dk] + dp[n][m - b][k - dk] + ((n) * (n)));
          }
        }
      }
    }
  }
  int test;
  cin >> test;
  for (int u = 0; u < test; ++u) {
    int n, m, k;
    cin >> n >> m >> k;
    cout << dp[n][m][k] << endl;
  }
  return 0;
}
