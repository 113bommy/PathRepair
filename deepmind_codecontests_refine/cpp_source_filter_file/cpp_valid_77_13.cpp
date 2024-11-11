#include <bits/stdc++.h>
bool getbit(long first, long second) { return (first >> second) & 1; }
using namespace std;
const long N = 4e6 + 5;
long n, M, dp[N], sum[N], l, r;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> M;
  dp[n] = 1;
  sum[n] = 1;
  for (long i = n - 1; i >= 1; i--) {
    dp[i] = sum[i + 1];
    for (long j = 2; j <= n / i; j++) {
      l = min(j * (i + 1) - 1, n);
      dp[i] = (dp[i] + sum[j * i] - sum[l + 1] + M) % M;
    }
    sum[i] = (sum[i + 1] + dp[i]) % M;
  }
  cout << dp[1] << '\n';
}
