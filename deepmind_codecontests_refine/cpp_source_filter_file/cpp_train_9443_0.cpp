#include <bits/stdc++.h>
using namespace std;
const int N = 60;
long long s[N], sum[N];
int n, k;
long long get(int i, int j) { return sum[j] - sum[i - 1]; }
bool dp[N][N];
bool test(long long mask) {
  memset(dp, 0, sizeof dp);
  dp[0][0] = true;
  for (int g = 1; g <= k; g++) {
    for (int i = 1; i <= n; i++) {
      for (int j = i; j >= g; j--) {
        long long par_sum = get(j, i);
        if ((par_sum & mask) != mask) continue;
        dp[g][i] |= dp[g - 1][j - 1];
      }
    }
  }
  return dp[k][n];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    sum[i] = sum[i - 1] + s[i];
  }
  long long ans = 0;
  for (int i = 51; i >= 0; i--) {
    if (test(ans | (1LL << i))) {
      ans |= (1LL << i);
    }
  }
  cout << ans << endl;
}
