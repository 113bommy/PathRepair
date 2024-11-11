#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long inf = 1e18;
const long long N = 100001;
long long dp[1 << 18][100];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k = 0, m;
  cin >> n >> m;
  long long rem[20], cnt[20];
  memset(rem, 0, sizeof rem);
  memset(cnt, 0, sizeof cnt);
  while (n) {
    rem[k] = n % 10;
    cnt[n % 10]++;
    n = n / 10;
    k++;
  }
  memset(dp, 0, sizeof dp);
  dp[0][0] = 1;
  for (long long i = 1; i < (1 << k); i++) {
    for (long long j = 0; j < k; j++) {
      if (i & (1 << j)) {
        if (rem[j] || i != (1 << j)) {
          long long g = i - (1 << j);
          for (long long p = 0; p < m; p++) {
            dp[i][(p * 10 + rem[j]) % m] += dp[g][p];
          }
        }
      }
    }
  }
  long long ans = dp[-1 + (1 << k)][0];
  for (long long i = 0; i <= 9; i++) {
    for (long long j = 2; j <= cnt[i]; j++) {
      ans /= j;
    }
  }
  cout << ans;
  return 0;
}
