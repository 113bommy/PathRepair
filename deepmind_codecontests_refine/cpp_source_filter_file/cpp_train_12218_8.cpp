#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long double PI = acos(-1);
const long long MOD = 1000000007;
const long long FMOD = 998244353;
const long double eps = 1e-9;
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
const long long max1 = (1 << 20) + 3;
long long cnt[2][max1];
long long a[300005];
long long dp[40][40];
signed main() {
  long long n, m;
  cin >> n >> m;
  for (long long i = 1; i < n + 1; i++) {
    for (long long j = 1; j < m + 1; j++) {
      char a;
      cin >> a;
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + (a == '0');
    }
  }
  long long area = 0, per = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      for (long long k = i + 1; k < n + 1; k++) {
        for (long long l = j + 1; l < n + 1; l++) {
          long long res = (dp[k][l] - dp[i][l] - (dp[k][j] - dp[i][j]) ==
                           ((k - i) * (l - j)));
          if (res) {
            per = max(per, 2 * (k - i + l - j));
          }
        }
      }
    }
  }
  cout << per;
}
