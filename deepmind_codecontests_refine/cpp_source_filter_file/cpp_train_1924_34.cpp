#include <bits/stdc++.h>
using namespace std;
const int maxN = 31;
const int maxNN = maxN * maxN;
const int maxK = 205;
double dp[maxK][maxNN];
double a[maxN][maxN];
double b[maxN][maxN];
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  double w = 0.0;
  for (int l = 0; l < n; l++) {
    for (int r = l; r < n; r++) {
      w++;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x = n * i + j;
      if (p[i] > p[j]) {
        dp[0][x] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
          int j2 = (l <= j && j <= r) ? l + r - j : j;
          int i2 = (l <= i && i <= r) ? l + r - i : i;
          int x = i * n + j;
          int y = i2 * n + j2;
          a[x][y] += 1.0 / w;
        }
      }
    }
  }
  for (int ii = 0; ii < k; ii++) {
    for (int i = 0; i < n * n; i++) {
      for (int j = 0; j < n * n; j++) {
        dp[ii + 1][j] += a[i][j] * dp[ii][i];
      }
    }
  }
  double ans = 0.0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ans += dp[k][i * n + j];
    }
  }
  printf("%.15f\n", ans);
  return 0;
}
