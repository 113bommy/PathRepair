#include <bits/stdc++.h>
using namespace std;
long long a[300010], N, K, dp[5010][5010];
inline long long f(long long L, long long S) {
  return L * (N / K + 1) + S * (N / K);
}
long long solve(long long L, long long S) {
  if (dp[L][S] != -1) return dp[L][S];
  if (S == 0 and L == 0) return dp[L][S] = 0;
  if (S == 0 and L > 0)
    return dp[L][S] = a[f(L, S)] - a[f(L, S) - N / K] + solve(L - 1, S);
  if (S > 0 and L == 0)
    return dp[L][S] = a[f(L, S)] - a[f(L, S) - N / K + 1] + solve(L, S - 1);
  long long e1 = a[f(L, S)] - a[f(L, S) - N / K] + solve(L - 1, S);
  long long e2 = a[f(L, S)] - a[f(L, S) - N / K + 1] + solve(L, S - 1);
  return dp[L][S] = min(e1, e2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  memset(dp, -1, sizeof dp);
  cin >> N >> K;
  for (long long i = 1; i <= N; i++) cin >> a[i];
  sort(a + 1, a + N + 1);
  long long L = N % K;
  long long S = K - L;
  cout << solve(L, S) << '\n';
  return 0;
}
