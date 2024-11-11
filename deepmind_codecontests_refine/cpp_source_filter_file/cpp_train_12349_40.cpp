#include <bits/stdc++.h>
using namespace std;
int N, R, f[51], s[51], p[51];
double dp[52][5002], low = 1, high = 10000000000000000;
int main() {
  cout << fixed << setprecision(16);
  cin >> N >> R;
  for (int i = 1; i <= N; ++i) {
    cin >> f[i] >> s[i] >> p[i];
  }
  for (int i = 0; i < 60; ++i) {
    double mid = (low + high) / 2;
    for (int i = N; i > 0; --i) {
      for (int j = 0; j <= R; ++j) {
        if (j + f[i] <= R) {
          dp[i][j] +=
              (double)p[i] * (min(dp[i + 1][j + f[i]], mid) + f[i]) / 100;
        } else {
          dp[i][j] += (double)p[i] * (mid + f[i]) / 100;
        }
        if (j + s[i] <= R) {
          dp[i][j] +=
              (1 - (double)p[i] / 100) * (min(dp[i + 1][j + s[i]], mid) + s[i]);
        } else {
          dp[i][j] += (1 - (double)p[i] / 100) * (mid + s[i]);
        }
      }
    }
    if (dp[1][0] > mid) {
      low = mid;
    } else {
      high = mid;
    }
    for (int i = 0; i <= N; ++i) {
      for (int j = 0; j <= R; ++j) {
        dp[i][j] = 0;
      }
    }
  }
  cout << (low + high) / 2 << '\n';
}
