#include <bits/stdc++.h>
using namespace std;
long long modpow(long long a, long long b,
                 long long mod = (long long)(1e9 + 7)) {
  if (!b) return 1;
  a %= mod;
  return modpow(a * a % mod, b / 2, mod) * (b & 1 ? a : 1) % mod;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long double p(long double R, int x0, int y0, int x, int y) {
  R *= R;
  long double D = ((x - x0) * (x - x0)) + ((y - y0) * (y - y0));
  if (D <= R)
    return 1;
  else
    return exp(1 - D / R);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  while (cin >> n) {
    int x[n], y[n];
    int x0, y0, k, epsilon;
    cin >> k >> epsilon;
    cin >> x0 >> y0;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    long double lo = 0, hi = 10000;
    for (int _ = 0; _ < 100; _++) {
      long double mid = (lo + hi) / 2;
      long double dp[n + 1][n + 1];
      for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < n + 1; j++) dp[i][j] = 0;
      dp[0][0] = 1;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++)
          if (dp[i][j]) {
            long double pr = p(mid, x0, y0, x[i], y[i]);
            dp[i + 1][j] += dp[i][j] * (1 - pr);
            dp[i + 1][j + 1] += dp[i][j] * pr;
          }
      }
      long double ans = 0;
      for (int i = 0; i < k; i++) ans += dp[n][i];
      if (ans * 1000 < epsilon)
        hi = mid;
      else
        lo = mid;
    }
    cout << setprecision(12) << lo << endl;
  }
  return 0;
}
