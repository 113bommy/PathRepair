#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const double PI = acos(-1.0);
const int N = 1e6 + 7;
long long fib[101];
int a[101];
int tot = 0;
long long dp[101][2];
int main() {
  fib[1] = 1;
  fib[2] = 2;
  for (int i = int(3); i <= int(100); ++i) {
    if (fib[i - 1] > 1e18 - fib[i - 2]) {
      tot = i - 1;
      break;
    }
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  int T;
  cin >> T;
  while (T--) {
    memset(a, 0, sizeof(a));
    memset(dp, 0, sizeof(dp));
    long long n;
    cin >> n;
    if (n == 1) {
      cout << 1 << endl;
      continue;
    }
    int k = 0;
    for (int i = int(n); i >= int(1); --i) {
      if (n >= fib[i]) {
        k = max(k, i);
        a[i] = 1;
        n -= fib[i];
      }
    }
    int last = 0, n0 = 0;
    dp[0][0] = 1;
    for (int i = int(1); i <= int(k); ++i) {
      if (a[i] == 1) {
        dp[i][0] = dp[last][0] + dp[last][1];
        dp[i][1] = (n0 / 2) * dp[last][0] + ((n0 + 1) / 2) * dp[last][1];
        last = i;
        n0 = 0;
      } else
        n0++;
    }
    cout << dp[k][0] + dp[k][1] << endl;
  }
}
