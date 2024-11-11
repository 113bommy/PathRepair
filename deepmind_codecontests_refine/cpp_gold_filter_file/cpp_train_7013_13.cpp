#include <bits/stdc++.h>
using namespace std;
const int kN = 50 + 1;
int inp[kN], arr[kN];
long long dp[kN][kN][kN];
double f[kN][kN];
long long DP(int n, int k, int s) {
  if (n < 0 || k < 0 || s < 0) return 0;
  if (k == 0) return (s == 0 ? 1 : 0);
  if (dp[n][k][s] == -1) {
    dp[n][k][s] = DP(n - 1, k - 1, s - arr[n - 1]) + DP(n - 1, k, s);
  }
  return dp[n][k][s];
}
void PreCalc(int n) {
  for (int i = 0; i < kN; ++i)
    for (int j = 0; j < kN; ++j) {
      f[i][j] = 1;
      int ind = 0;
      for (int k = 1; k <= i; ++k) {
        f[i][j] *= k;
        if (ind < n) {
          ++ind;
          f[i][j] /= ind;
        }
      }
      for (int k = 1; k <= j; ++k) {
        f[i][j] *= k;
        if (ind < n) {
          ++ind;
          f[i][j] /= ind;
        }
      }
      for (int k = ind + 1; k <= n; ++k) f[i][j] /= k;
    }
}
int main() {
  int n, p;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> inp[i];
  cin >> p;
  PreCalc(n);
  double res = 0;
  for (int i = 0; i < n; ++i) {
    int arr_index = 0;
    for (int j = 0; j < n; ++j)
      if (i != j) arr[arr_index++] = inp[j];
    memset(dp, 255, sizeof(dp));
    for (int s = p - inp[i] + 1; s < p; ++s) {
      for (int k = 1; k <= n - 1; ++k) {
        res += k * f[k][n - k - 1] * DP(n - 1, k, s);
      }
    }
  }
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    arr[i] = inp[i];
    sum += arr[i];
  }
  memset(dp, 255, sizeof(dp));
  for (int k = 1; k < n; ++k) res += k * f[k][n - k] * DP(n, k, p);
  res += n * f[n][0] * DP(n, n, min(sum, p));
  printf("%.9lf", res);
  return 0;
}
