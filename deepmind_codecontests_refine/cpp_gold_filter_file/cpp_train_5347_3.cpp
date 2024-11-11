#include <bits/stdc++.h>
using namespace std;
long long n, m, k, lp, i, j, mp;
long long CNM[120][12000];
long long dp[120][10];
long long ans[120][12000];
long long xar(long long now) {
  if (now == 0) return 1;
  if (now == 1) return CNM[n][i];
  long long ans = xar(now % 2);
  long long res = xar(now / 2);
  return (((res * res) % 1000000007) * ans) % 1000000007;
}
void init() {
  for (i = 0; i <= n; i++) {
    CNM[i][0] = 1;
    for (j = 1; j <= i; j++)
      CNM[i][j] = (CNM[i - 1][j - 1] + CNM[i - 1][j]) % 1000000007;
  }
  for (i = 0; i <= n; i++)
    dp[i][1] = xar(lp), dp[i][2] = (dp[i][1] * CNM[n][i]) % 1000000007;
}
long long DP(long long N, long long K) {
  if (N == 0 && K == 0) return 1;
  if (N != n || K != k) return ans[N][K] % 1000000007;
  int a1, a2, a3;
  for (a1 = 0; a1 < N; a1++)
    for (a2 = 0; a2 <= K; a2++)
      if (DP(a1, a2))
        for (a3 = 0; a3 <= min(N, K - a2); a3++)
          if (mp > a1)
            ans[a1 + 1][a2 + a3] += (DP(a1, a2) * dp[a3][2]) % 1000000007;
          else
            ans[a1 + 1][a2 + a3] += (DP(a1, a2) * dp[a3][1]) % 1000000007;
  return ans[N][K];
}
int main() {
  ans[0][0] = 1;
  cin >> n >> m >> k;
  lp = m / n;
  mp = m % n;
  init();
  cout << DP(n, k) % 1000000007 << endl;
}
