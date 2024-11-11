#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  int c = -1;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<int> b(0);
  b.push_back(v[0]);
  for (int i = 1; i < n; i++) {
    if (v[i] != v[i - 1]) b.push_back(v[i]);
  }
  int dp[n][n][2];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < 2; k++) {
        if (i == j)
          dp[i][j][k] = 0;
        else
          dp[i][j][k] = 1000000;
      }
    }
  }
  for (int r = 0; r < n; r++) {
    for (int l = r + 1 - 1; l >= 0; l--) {
      for (int k = 0; k < 2; k++) {
        if (k)
          c = v[r];
        else
          c = v[l];
        if (l - 1 >= 0) {
          dp[l - 1][r][k] =
              min(dp[l - 1][r][k], dp[l][r][k] + int(v[l - 1] != c));
        }
        if (r + 1 <= n - 1) {
          dp[l][r + 1][k] =
              min(dp[l][r + 1][k], dp[l][r][k] + int(v[r + 1] != c));
        }
      }
    }
  }
  cout << min(dp[0][n - 1][1], dp[0][n - 1][0]);
  return 0;
}
