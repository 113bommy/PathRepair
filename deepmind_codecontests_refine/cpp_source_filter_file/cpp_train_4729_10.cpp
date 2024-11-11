#include <bits/stdc++.h>
using namespace std;
const int N = 55, M = 1e9 + 7;
long long dp[N][N][2];
int power(int a, int p) {
  if (p == 0) return 1;
  int ans = power(a, p / 2);
  ans = (1LL * ans * ans) % M;
  if (p % 2) ans = (1LL * ans * a) % M;
  return ans;
}
int fac[N], invfac[N], inv[N];
void pre() {
  fac[0] = 1;
  for (int i = 1; i < N; i++) fac[i] = (1LL * i * fac[i - 1]) % M;
  invfac[N - 1] = power(fac[N - 1], M - 2);
  for (int i = N - 2; i >= 0; i--)
    invfac[i] = (1LL * invfac[i + 1] * (i + 1)) % M;
  for (int i = 1; i < N; i++) inv[i] = (1LL * invfac[i] * fac[i - 1]) % M;
}
int C(int n, int r) {
  if (r < 0 || r > n) return 0;
  int denom = (1LL * invfac[r] * invfac[n - r]) % M;
  return (1LL * fac[n] * denom) % M;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  pre();
  dp[1][0][1] = 1;
  for (int i = 2; i < N; i++) {
    for (int k = 0; k <= i / 2; k++) {
      dp[i][k][1] = (dp[i][k][1] + i * dp[i - 1][k][0]) % M;
      dp[i][k][0] = (dp[i][k][0] + i * dp[i - 1][k - 1][1]) % M;
      for (int l = 1; l < i - 1; l++) {
        int r = i - 1 - l;
        if (l > r) break;
        long long ww = (i * C(i - 1, l)) % M;
        if (l == r) ww = (ww * inv[2]) % M;
        for (int lk = 0; lk <= k; lk++) {
          int rk = k - lk;
          long long notake = (dp[l][lk][0] * dp[r][rk][0]) % M;
          long long rightttake =
              (rk ? (dp[l][lk][0] * dp[r][rk - 1][1]) % M : 0);
          long long lefttake =
              (lk ? (dp[l][lk - 1][1] * (dp[r][rk][0] + dp[r][rk][1])) % M : 0);
          dp[i][k][1] = (dp[i][k][1] + ww * notake) % M;
          dp[i][k][0] = (dp[i][k][0] + ww * (lefttake + rightttake)) % M;
        }
      }
    }
  }
  int n, k;
  cin >> n >> k;
  cout << ((dp[n][k][0] + dp[n][k][1]) * inv[n]) % M << endl;
}
