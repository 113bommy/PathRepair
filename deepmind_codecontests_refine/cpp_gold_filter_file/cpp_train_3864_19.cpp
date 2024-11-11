#include <bits/stdc++.h>
using namespace std;
void fun() {}
long long int __gcda(long long int a, long long int b) {
  if (b == 0) {
    return a;
  } else if (a == 0) {
    return b;
  } else if (a == b) {
    return a;
  } else if (b > a) {
    return __gcda(a, b % a);
  } else if (a > b) {
    return __gcda(a % b, b);
  }
  return 0;
}
long long int gcdExtended(long long int a, long long int b, long long int *x,
                          long long int *y) {
  if (a == 0) {
    *x = 0;
    *y = 1;
    return b;
  }
  long long int x1, y1;
  long long int gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
long long int md = 998244353;
bool valid(long long int start, long long int end, long long int hashe[],
           long long int dda[][26]) {
  for (long long int i = 0; i < 26; i++) {
    if (dda[end][i] - dda[start - 1][i] > 0) {
      if (hashe[i] < end - start + 1) return false;
    }
  }
  return true;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  fun();
  long long int n, k;
  cin >> n >> k;
  long long int dp[n + 1][k + 1][4];
  if (k == 1) {
    cout << "2\n";
    return 0;
  }
  memset(dp, 0, sizeof(dp));
  dp[1][1][1] = dp[1][1][0] = 1;
  dp[1][1][3] = dp[1][1][2] = 0;
  dp[1][2][0] = dp[1][2][1] = 0;
  dp[1][2][2] = dp[1][2][3] = 1;
  for (long long int i = 2; i <= n; i++) {
    dp[i][1][0] = dp[i][1][1] = 1;
    dp[i][1][2] = dp[i][1][3] = 0;
    for (long long int kk = 2; kk <= min(k, 2 * i); kk++) {
      dp[i][kk][0] = (dp[i - 1][kk - 1][1] + dp[i - 1][kk][2] +
                      dp[i - 1][kk][3] + dp[i - 1][kk][0]) %
                     md;
      dp[i][kk][1] = (dp[i - 1][kk - 1][0] + dp[i - 1][kk][2] +
                      dp[i - 1][kk][3] + dp[i - 1][kk][1]) %
                     md;
      dp[i][kk][2] = (dp[i - 1][kk - 1][0] + dp[i - 1][kk - 1][1] +
                      dp[i - 1][kk - 2][3] + dp[i - 1][kk][2]) %
                     md;
      dp[i][kk][3] = (dp[i - 1][kk - 1][0] + dp[i - 1][kk - 1][1] +
                      dp[i - 1][kk - 2][2] + dp[i - 1][kk][3]) %
                     md;
    }
  }
  cout << (dp[n][k][0] + dp[n][k][1] + dp[n][k][2] + dp[n][k][3]) % md << "\n";
}
