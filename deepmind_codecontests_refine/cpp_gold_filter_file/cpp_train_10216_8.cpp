#include <bits/stdc++.h>
using namespace std;
const int N = 100005, K = 105, P = 998244353;
using ll = long long;
ll dp[N][K], sum[N], cnt[N][K];
inline bool cmp(int a, int b) { return a == -1 || b == -1 || a == b; }
int n, kk, len, a[N];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> kk >> len;
  if (len == 1) {
    puts("0");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 1; j <= kk; j++) cnt[i][j] = cnt[i - 1][j] + cmp(a[i], j);
  }
  sum[0] = 1;
  if (a[1] == -1) {
    for (int i = 1; i <= kk; i++) dp[1][i] = 1;
    sum[1] = kk;
  } else
    sum[1] = 1, dp[1][a[1]] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= kk; j++)
      if (cmp(a[i], j)) {
        dp[i][j] = sum[i - 1];
        if (i >= len && cnt[i][j] - cnt[i - len][j] == len) {
          dp[i][j] = ((dp[i][j] - sum[i - len] + dp[i - len][j]) % P + P) % P;
        }
        sum[i] = (sum[i] + dp[i][j]) % P;
      }
  cout << sum[n] << endl;
  return 0;
}
