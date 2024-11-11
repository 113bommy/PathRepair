#include <bits/stdc++.h>
using namespace std;
int dp[2][2 * 1100][55][55];
int N, M, K;
bool A[1100], B[1100];
int gain[1100][55][55][4];
bool seen[1100];
int ans;
int32_t main() {
  ios_base::sync_with_stdio(false);
  if (fopen("cf796e.in", "r")) {
    freopen("cf796e.in", "r", stdin);
    freopen("cf796e.out", "w", stdout);
  }
  cin >> N >> M >> K;
  M = min(M, 2 * (N / K));
  int spam;
  cin >> spam;
  for (int i = 0; i < spam; i++) {
    int x;
    cin >> x;
    x--;
    A[x] = true;
  }
  cin >> spam;
  for (int i = 0; i < spam; i++) {
    int x;
    cin >> x;
    x--;
    B[x] = true;
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < M; j++) {
      for (int k = 0; k < K; k++) {
        for (int m = 0; m < K; m++) {
          dp[i][j][k][m] = -1000000007;
        }
      }
    }
  }
  dp[0][0][0][0] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < K; j++) {
      for (int k = 0; k < K; k++) {
        for (int m = 0; m < K; m++) {
          if ((!B[i + m] || k <= m) && (j <= m) && A[i + m]) {
            gain[i][j][k][1]++;
          }
          if ((!A[i + m] || j <= m) && (k <= m) && B[i + m]) {
            gain[i][j][k][2]++;
          }
          if ((j <= m || !A[i + m]) && (k <= m || !B[i + m]) &&
              (A[i + m] || B[i + m])) {
            gain[i][j][k][3]++;
          }
        }
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= M; j++) {
      for (int k = 0; k < K; k++) {
        for (int m = 0; m < K; m++) {
          dp[1][j][max(0, k - 1)][max(0, m - 1)] =
              max(dp[1][j][max(0, k - 1)][max(0, m - 1)], dp[0][j][k][m]);
          dp[1][j + 1][K - 1][max(0, m - 1)] =
              max(dp[1][j + 1][K - 1][max(0, m - 1)],
                  dp[0][j][k][m] + gain[i][k][m][1]);
          dp[1][j + 1][max(0, k - 1)][K - 1] =
              max(dp[1][j + 1][max(0, k - 1)][K - 1],
                  dp[0][j][k][m] + gain[i][k][m][2]);
          dp[1][j + 2][K - 1][K - 1] = max(dp[1][j + 2][K - 1][K - 1],
                                           dp[0][j][k][m] + gain[i][k][m][3]);
        }
      }
    }
    for (int j = 0; j <= M; j++) {
      for (int k = 0; k < K; k++) {
        for (int m = 0; m < K; m++) {
          dp[0][j][k][m] = dp[1][j][k][m];
          dp[1][j][k][m] = -1000000007;
        }
      }
    }
  }
  for (int j = 0; j <= M; j++) {
    for (int k = 0; k < K; k++) {
      for (int m = 0; m < K; m++) {
        ans = max(ans, dp[0][j][k][m]);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
