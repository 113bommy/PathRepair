#include <bits/stdc++.h>
using namespace std;
const int MAX = 105;
const long long MOD = 1000000007LL;
long long C[MAX][MAX];
long long dp[MAX][MAX * MAX];
long long val[MAX][MAX];
int N, K;
long long M;
long long powmod(long long x, long long n) {
  if (n == 0) return 1;
  long long ret = powmod(x, n >> 1);
  ret = ret * ret % MOD;
  if (n & 1) ret = ret * x % MOD;
  return ret;
}
int main() {
  for (int i = 0; i < MAX; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
  }
  cin >> N >> M >> K;
  dp[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    long long ccount = M / N;
    if ((i % N != 0) && (i % N <= M % N)) ccount++;
    for (int j = 0; j <= N; j++) val[i][j] = powmod(C[N][j], ccount);
  }
  for (int i = 1; i <= N; i++) {
    int a = min(K, i * N);
    for (int j = 0; j <= a; j++) {
      int b = min(j, N);
      for (int k = 0; k <= b; k++) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j - k] * val[i][k]) % MOD;
      }
    }
  }
  cout << dp[N][K] << endl;
  return 0;
}
