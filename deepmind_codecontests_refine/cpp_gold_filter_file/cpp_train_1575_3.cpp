#include <bits/stdc++.h>
using namespace std;
long long int dp[2005][2005] = {0};
long long Pow(long long N, long long M) {
  if (M == 0) {
    return N > 0;
  }
  long long t = Pow(N, M / 2);
  t *= t;
  t %= 998244353;
  if (M % 2) t *= N;
  return t % 998244353;
}
long long F(long long N, long long M) {
  if (M == N || M == 0) return 1;
  if (dp[N][M]) return dp[N][M];
  dp[N][M] = F(N - 1, M) + F(N - 1, M - 1);
  dp[N][M] %= 998244353;
  return dp[N][M];
}
int main() {
  long long N, M, K, ans = 1;
  scanf("%lld %lld %lld", &N, &M, &K);
  if (M == 1 && K == 0)
    printf("1\n");
  else {
    ans *= M;
    ans *= Pow(M - 1, K);
    ans %= 998244353;
    ans *= F(N - 1, K);
    ans %= 998244353;
    printf("%lld\n", ans);
  }
  return 0;
}
