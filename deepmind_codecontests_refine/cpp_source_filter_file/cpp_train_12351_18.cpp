#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long add(long long x, long long y) {
  x += y;
  if (x >= MOD) return x - MOD;
  return x;
}
long long sub(long long x, long long y) {
  x -= y;
  if (x < 0) return x + MOD;
  return x;
}
long long mult(long long x, long long y) { return (x * y) % MOD; }
long long bin_pow(long long x, long long p) {
  if (p == 0) return 1;
  if (p & 1) return mult(x, bin_pow(x, p - 1));
  return bin_pow(mult(x, x), p / 2);
}
long long rev(long long x) { return bin_pow(x, MOD - 2); }
const int N = 2020;
long long pw[2][N];
long long sc[N];
long long dp[N][N];
long long ans[N];
void solve() {
  ans[1] = 0;
  sc[1] = 1;
  dp[1][0] = dp[1][1] = 1;
  for (int n = 2; n < N; n++) {
    for (int k = 0; k < n; k++) {
      dp[n][k] = add(dp[n][k], mult(dp[n - 1][k], pw[0][k]));
      dp[n][k + 1] = add(dp[n][k + 1], mult(dp[n - 1][k], pw[1][n + k + 1]));
    }
    sc[n] = 1;
    for (int m = 1; m < n; m++) {
      sc[n] = sub(sc[n], mult(dp[n][m], sc[m]));
    }
    ans[n] = mult(sc[n], n * (n - 1) / 2);
    for (int m = 1; m < n; m++) {
      long long val = m * (m - 1) / 2 + m * (n - m);
      val = add(val, ans[m]);
      val = add(val, ans[n - m]);
      ans[n] = add(ans[n], mult(val, mult(sc[m], dp[n][m])));
    }
    ans[n] = mult(ans[n], rev(sub(1, sc[n])));
  }
}
int main() {
  int n;
  long long A, B;
  scanf("%d%lld%lld", &n, &A, &B);
  pw[0][0] = pw[1][0] = 1;
  pw[0][1] = mult(A, rev(B));
  pw[1][1] = sub(1, pw[0][1]);
  for (int k = 0; k < 2; k++)
    for (int i = 2; i < N; i++) pw[k][i] = mult(pw[k][i - 1], pw[k][1]);
  solve();
  printf("%lld\n", ans[n]);
  return 0;
}
