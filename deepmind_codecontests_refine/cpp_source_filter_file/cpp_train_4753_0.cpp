#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, k;
  cin >> n >> m >> k;
  long long dp[n + 2][k + 2];
  for (long long i = 0; i < n + 1; i++) {
    for (long long j = 0; j < k + 1; j++) {
      dp[i][j] = 1000000007;
    }
  }
  dp[0][0] = 0;
  for (long long i = 1; i <= n; i++) {
    string a;
    cin >> a;
    long long sz[k + 1];
    long long net = 0;
    for (long long i = 0; i <= k; i++) sz[i] = 1000000007;
    for (long long i = 0; i < m; i++) {
      if (a[i] == '1') {
        net++;
      }
    }
    if (net <= k) sz[net] = 0;
    for (long long i = 0; i < m; i++) {
      if (a[i] == '1') {
        long long c = net;
        for (long long j = i; j < m; j++)
          if (a[j] == '1') {
            c--;
            if (c <= k) {
              sz[c] = min(sz[c], j - i + 1ll);
            }
          }
      }
    }
    for (long long ia = 0; ia < k + 1; ia++) {
      if (sz[ia] == 1000000007) break;
      for (long long j = 0; j <= k; j++) {
        if (j + ia > k) break;
        dp[i][j + ia] = min(dp[i][j + ia], sz[ia] + dp[i - 1][j]);
      }
    }
  }
  long long f = 1000000007;
  for (long long i = 0; i < k; i++) {
    f = min(dp[n][i], f);
  }
  cout << f << '\n';
}
