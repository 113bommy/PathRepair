#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int N, K;
long long DP[1005][105], M;
long long exp(long long n, int e, long long m) {
  if (e == 0) return 1;
  if (e % 2) return exp(n, e - 1, m) * n;
  long long x = exp(n, e / 2, m);
  return (x * x) % m;
}
int main() {
  cin >> N >> K >> M;
  long long ans = 0;
  for (int i = (1); i <= (N); i++) {
    for (int d = (1); d <= (9); d++) {
      long long m = (exp(10, i - 1, K) * d) % K;
      DP[i][m]++;
    }
    for (int j = (1); j <= (K - 1); j++)
      for (int d = (0); d <= (9); d++) {
        long long m = (exp(10, i, K) * d + j) % K;
        DP[i + 1][m] += DP[i][j];
        DP[i + 1][m] %= M;
      }
    if (i < N)
      ans = (ans + DP[i][0] * exp(10, N - i - 1, M) * 9) % M;
    else
      ans = (ans + DP[i][0]) % M;
  }
  cout << ans;
}
