#include <bits/stdc++.h>
using namespace std;
long long dp[405][405], S[405], f[405], mod;
int main() {
  int T, n;
  cin >> T >> mod;
  int N = 400;
  f[0] = 1;
  for (long long i = 1; i <= N; ++i) f[i] = i * f[i - 1] % mod;
  for (int i = 1; i <= N; ++i) dp[1][i] = f[i];
  for (int i = 2; i <= N; ++i)
    for (int j = i; j <= N; ++j) {
      long long sum = 0;
      for (long long k = 1; k <= j; ++k)
        sum = (sum + f[k] * dp[i - 1][j - k] % mod) % mod;
      dp[i][j] = sum;
    }
  S[1] = 1;
  for (int i = 2; i <= N; ++i) {
    long long sum = f[i];
    for (int k = 2; k < i; ++k) {
      sum = (sum - S[k] * dp[k][i] % mod) % mod;
    }
    S[i] = sum;
  }
  for (int i = 3; i <= N; ++i) {
    if (i % 2 == 0)
      S[i] = (S[i] - 2) % mod;
    else
      S[i] = (S[i] + 2) % mod;
  }
  while (T--) {
    scanf("%d", &n);
    printf("%lld\n", (S[n] + mod) % mod);
  }
}
