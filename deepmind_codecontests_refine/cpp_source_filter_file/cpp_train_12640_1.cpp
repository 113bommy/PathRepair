#include <bits/stdc++.h>
using namespace std;
void boost() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int N = 1e6;
const long long inf = 1e9 + 7;
const long double PI = acos(-1);
long long bin_pow(long long x, long long y) {
  long long res = 1, base = x;
  while (y) {
    if (y & 1) {
      res *= base;
      res %= inf;
    }
    base *= base;
    base %= inf;
    y /= 2;
  }
  return res;
}
int n;
long long a[105], b[105];
long long cnk[1005][1005];
long long dp[105][1005];
int main() {
  boost();
  for (int i = 0; i <= 1000; i++) {
    cnk[i][0] = cnk[i][i] = 1;
    for (int j = 1; j < i; j++) {
      cnk[i][j] = (cnk[i - 1][j - 1] + cnk[i][j - 1]) % inf;
    }
  }
  cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int j = 1; j <= n; j++) {
    cin >> b[j];
  }
  for (int i = 1; i <= n; i++) {
    sum += a[i];
  }
  long long ans = 1;
  for (int i = n, t = sum; i >= 1; i--) {
    ans = ans * cnk[t][a[i]] % inf;
    t -= a[i];
  }
  dp[0][0] = 1;
  int cursum = 0;
  for (int i = 0; i < n; i++) {
    cursum += a[i];
    for (int j = 0; j <= cursum; j++) {
      for (int k = j; k <= cursum + a[i + 1] && k - j <= b[i + 1]; k++) {
        dp[i + 1][k] =
            (dp[i + 1][k] + dp[i][j] * cnk[cursum + a[i + 1] - j][k - j]) % inf;
      }
    }
  }
  ans *= dp[n][sum];
  ans %= inf;
  cout << ans;
}
