#include <bits/stdc++.h>
using namespace std;
const double eps(1e-8);
int n, k, m;
long long dp[1010][110][2][2], g[1010];
void Add(long long &a, long long b) {
  a += b;
  a %= m;
  if (a < 0) a += m;
}
int main() {
  cin >> n >> k >> m;
  g[0] = 1;
  for (int i = 1; i <= 1000; i++) g[i] = g[i - 1] * 10LL % k;
  long long ret = 0;
  dp[0][0][0][1] = 1;
  for (int pos = 0; pos < n; pos++) {
    for (int mod = 0; mod < k; mod++) {
      for (int num = 1; num < 10; num++) {
        int nxt = (mod + num * g[pos]) % k;
        if (!nxt) {
          dp[pos + 1][nxt][1][0] +=
              (dp[pos][mod][0][0] + dp[pos][mod][1][0] + dp[pos][mod][0][1]) %
              m;
          dp[pos + 1][nxt][1][0] %= m;
        } else {
          dp[pos + 1][nxt][1][0] += (dp[pos][mod][1][0]) % m;
          dp[pos + 1][nxt][1][0] %= m;
          dp[pos + 1][nxt][0][0] +=
              (dp[pos][mod][0][0] + dp[pos][mod][0][1]) % m;
          dp[pos + 1][nxt][0][0] %= m;
        }
      }
      Add(dp[pos + 1][mod][1][0], dp[pos][mod][1][0]);
      Add(dp[pos + 1][mod][0][0], dp[pos][mod][0][0]);
      Add(dp[pos + 1][mod][0][1], dp[pos][mod][0][1]);
    }
  }
  for (int i = 0; i < k; i++) {
    Add(ret, dp[n][i][1][0]);
    Add(ret, -dp[n - 1][i][1][0]);
  }
  cout << ret << endl;
  return 0;
}
