#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000000")
using namespace std;
int n, k;
long long dp[2001][2001], tot[2001];
string st;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k >> st;
  dp[0][0] = 1;
  tot[0] = 1;
  for (int i = 1; i < n + 1; i++)
    for (int j = 0; j < k + 1; j++) {
      dp[i][j] = (1ll * tot[j] * (st[i - 1] - 'a')) % 1000000007;
      for (int p = 0; p < i; p++) {
        int rem = j - ((p + 1) * (n - i + 1));
        if (rem < 0) break;
        dp[i][j] =
            ((dp[i][j] + dp[i - p - 1][rem] * ('z' - st[i - 1]))) % 1000000007;
      }
      tot[j] = (tot[j] + dp[i][j]) % 1000000007;
    }
  cout << tot[k];
  return 0;
}
