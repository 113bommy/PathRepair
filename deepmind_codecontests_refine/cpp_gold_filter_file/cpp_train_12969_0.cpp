#include <bits/stdc++.h>
using namespace std;
long long int k, q;
long double dp[9001][1001], a[9001], ans[1001][9001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> k >> q;
  cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(12);
  if (k == 1) {
    while (q--) {
      long long int p;
      cin >> p;
      cout << 1 << endl;
    }
    return 0;
  }
  a[1] = 1.0;
  for (long long int i = 2; i <= 9000; ++i) {
    a[i] = 1.0 / (long double)i;
    for (long long int j = 2; j <= i; ++j)
      a[i] = (a[i] * (long double)j) / (long double)i;
  }
  for (long long int j = 2; j <= k; ++j)
    ans[j][1] = 1.0 - (1.0 / (long double)j), ans[j][0] = 1.0;
  for (long long int j = 2; j <= k; ++j)
    for (long long int i = 2; i <= 9000; ++i)
      ans[j][i] = ans[j][i - 1] * (1.0 - (1.0 / (long double)j));
  for (long long int i = 1; i <= 9000; ++i)
    for (long long int j = 1; j <= k; ++j) {
      if (i < j) {
        dp[i][j] = 0.0;
        continue;
      }
      if (i == j) {
        dp[i][j] = a[i];
        continue;
      }
      if (j > 1)
        dp[i][j] = dp[i - 1][j] + (dp[i - 1][j - 1] * ans[j][i - 1]);
      else
        dp[i][j] = 1.0;
    }
  while (q--) {
    long long int p;
    cin >> p;
    long double pr = (long double)p / 2000.0;
    for (long long int i = 1; i <= 9000; ++i) {
      if (abs(dp[i][k] - pr) < 0.00000000000001 || dp[i][k] > pr) {
        cout << i << endl;
        break;
      }
    }
  }
}
