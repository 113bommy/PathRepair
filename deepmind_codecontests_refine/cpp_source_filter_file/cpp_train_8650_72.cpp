#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 10, mod = 1e9 + 9;
int dp[3][N * N][N], w[N], n, ans, cnt[N], ch[N][N], cnt_val;
void Pre() {
  for (int i = 0; i < n; i++) ch[i][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++)
      ch[i][j] = (ch[i - 1][j - 1] + ch[i - 1][j]) % mod;
}
int main() {
  cin >> n;
  Pre();
  for (int i = 0; i < n; i++)
    cin >> w[i], cnt_val += (cnt[w[i]] == 0), cnt[w[i]]++;
  if (cnt_val <= 2) {
    cout << n;
    return 0;
  }
  dp[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 12; j++) {
      dp[(i % 2)][j][0] = dp[1 - i % 2][j][0];
      for (int k = 1; k <= n; k++) {
        dp[i % 2][j][k] = dp[1 - i % 2][j][k];
        if (j >= w[i - 1])
          dp[i % 2][j][k] =
              (dp[i % 2][j][k] + dp[1 - i % 2][j - w[i - 1]][k - 1]) % mod;
      }
    }
  }
  for (int i = 0; i < N; i++)
    for (int j = 1; j <= cnt[i]; j++)
      if (dp[n % 2][j * i][j] == ch[cnt[i]][j]) ans = max(ans, j);
  cout << ans;
  return 0;
}
