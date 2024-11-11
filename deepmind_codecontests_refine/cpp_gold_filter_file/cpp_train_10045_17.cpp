#include <bits/stdc++.h>
using namespace std;
int N;
long long K;
long long dp[55];
int main() {
  while (cin >> N >> K) {
    dp[N] = 1;
    dp[N - 1] = 2;
    for (int i = N - 2; i >= 1; i--) dp[i] = dp[i + 1] + dp[i + 2];
    for (int i = 1; i <= N; i++)
      if (K > dp[i + 1] && i < N) {
        K -= dp[i + 1];
        printf("%d %d ", i + 1, i);
        i += 1;
      } else
        printf("%d ", i);
    printf("\n");
  }
  return 0;
}
