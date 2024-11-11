#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9;
using namespace std;
const int N = 123;
const int K = 10000 + 1230;
long long pow1[N], pow2[N];
long long dp[N][K];
long long c[N][N];
long long quick_pow(long long a, long long b) {
  long long tmp = a;
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * tmp) % mod;
    tmp = (tmp * tmp) % mod;
    b >>= 1;
  }
  return ans;
}
int main() {
  int n, k;
  long long m;
  cin >> n >> m >> k;
  for (int i = 0; i <= n; i++) c[i][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
  }
  for (int i = 0; i <= n; i++) {
    pow1[i] = quick_pow(c[n][i], m / n);
    pow2[i] = (pow1[i] * c[n][i]) % mod;
  }
  dp[0][0] = 1;
  long long now;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      if (dp[i][j] != 0) {
        for (int p = 0; p <= n && j + p <= k; p++) {
          if (i < m % n)
            now = pow2[p];
          else
            now = pow1[p];
          dp[i + 1][j + p] = (dp[i + 1][j + p] + dp[i][j] * now) % mod;
        }
      }
    }
  }
  cout << dp[n][k] << endl;
  return 0;
}
