#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, a[5000], num_under[5000], dp[5000][5000], ps[5001][5001];
int mul(int x, int y) { return ((long long)x * y) % mod; }
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 1; i < n; i++) {
    num_under[i] = num_under[i - 1];
    while (2 * a[num_under[i]] <= a[i]) {
      ++num_under[i];
    }
  }
  for (int i = 0; i < n; i++) {
    dp[0][i] = 1;
    ps[0][i + 1] = i + 1;
  }
  for (int i = 1; i < n; i++) {
    for (int j = i; j < n; j++) {
      dp[i][j] =
          (ps[i - 1][num_under[j]] + mul(dp[i - 1][j], num_under[j] - i + 1)) %
          mod;
    }
    for (int j = 0; j < n; j++) {
      ps[i][j + 1] = (ps[i][j] + dp[i][j]) % mod;
    }
  }
  cout << dp[n - 1][n - 1] << endl;
}
