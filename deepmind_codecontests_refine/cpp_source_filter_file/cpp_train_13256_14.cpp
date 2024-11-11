#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long infll = 0x3f3f3f3f3f3f3f3f;
const long long mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int maxn = 1e5 + 5;
const int maxm = 1.5e7 + 5;
using namespace std;
int n, l;
int a[230], b[230];
long long dp[3100][230];
long long ans;
int main() {
  cin >> n >> l;
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    dp[a[i]][i]++;
    if (a[i] != b[i]) {
      a[i + n] = b[i];
      b[i + n] = a[i];
      dp[a[i + n]][i + n]++;
    }
  }
  for (int i = 1; i <= l; i++) {
    for (int j = 0; j < 2 * n; j++) {
      if (!dp[i][j]) continue;
      for (int k = 0; k < 2 * n; k++) {
        if (j % n != k % n && b[j] == a[k]) {
          dp[i + a[k]][k] = (dp[i + a[k]][k] + dp[i][j]) % mod;
        }
      }
    }
  }
  for (int i = 0; i < 2 * n; i++) {
    ans = (ans + dp[l][i]) % mod;
  }
  cout << ans << endl;
  return 0;
}
