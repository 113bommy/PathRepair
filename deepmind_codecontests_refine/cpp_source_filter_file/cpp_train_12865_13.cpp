#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  int n, m;
  cin >> n >> m;
  long long arr[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  int dp[n];
  dp[0] = 0;
  int memo[n][m];
  for (int i = 0; i < n; i++) {
    memo[0][i] = 0;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] >= arr[i - 1][j]) {
        memo[i][j] = memo[i - 1][j];
      } else {
        memo[i][j] = i;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    dp[i] = *min_element(memo[i], memo[i] + m);
  }
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    if (dp[r] <= l) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
