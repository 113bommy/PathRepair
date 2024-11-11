#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int N1 = 2e3 + 10;
int b[N1];
int C[N1][N1];
int dp[N][N];
int a[N][N];
int x[N1];
int y[N1];
int M = 1e9 + 7;
int n, m, r;
int cnt[N1];
int v(int x) {
  if (x >= N) {
    return N - 1;
  }
  if (x < 0) {
    return 0;
  }
  return x;
}
int main() {
  cin >> n >> m >> r;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> b[i];
    a[x[i]][y[i]] = 1;
  }
  for (int i = 1; i < N; i++) {
    for (int j = 1; j < N; j++) {
      dp[i][j] = a[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
    }
  }
  for (int i = 1; i < N1; i++) {
    C[i][0] = 1;
    C[i][i] = 1;
  }
  for (int i = 1; i < N1; i++) {
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cnt[i] = dp[v(x[i] + r)][v(y[i] + r)] - dp[v(x[i] - r - 1)][v(y[i] + r)] -
             dp[v(x[i] + r)][v(y[i] - r - 1)] +
             dp[v(x[i] - r - 1)][v(y[i] - r - 1)];
    ans = (ans + (long long)(C[n][m] - C[n - cnt[i]][m] + M) % M * b[i] % M *
                     b[i] % M) %
          M;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      int x1 = max(v(x[i] - r - 1), v(x[j] - r - 1));
      int y1 = max(v(y[i] - r - 1), v(y[j] - r - 1));
      int x2 = min(v(x[i] + r), v(x[j] + r));
      int y2 = min(v(y[i] + r), v(y[j] + r));
      int temp = dp[x1][y1] + dp[x2][y2] - dp[x1][y2] - dp[x2][y1];
      if (x1 > x2 || y1 > y2) {
        temp = 0;
      }
      int temp2 =
          (((C[n][m] - C[n - cnt[i]][m] + M) % M - C[n - cnt[j]][m] + M) % M +
           C[n - cnt[i] - cnt[j] + temp][m]) %
          M;
      ans = (ans + 2 * (long long)temp2 * b[i] % M * b[j] % M) % M;
    }
  }
  cout << ans << endl;
}
