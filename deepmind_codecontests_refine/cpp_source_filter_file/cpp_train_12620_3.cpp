#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e3 + 7;
const int maxm = 1e6 + 7;
const int mod = 1e9 + 7;
int n;
long long ar[maxn];
long long dp[maxn][maxn];
int st[maxn];
int tot;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> ar[i];
  ar[0] = -inf;
  long long maxx = -inf;
  int pos;
  for (int i = 1; i <= n; i++) {
    long long tmp = ar[i];
    dp[i][i] = ar[i];
    for (int j = i - 1; j >= 1; j--) {
      if (ar[j] <= dp[i][j + 1]) {
        tmp += ar[j];
        dp[i][j] = ar[j];
      } else {
        tmp += dp[i][j + 1];
        dp[i][j] = dp[i][j + 1];
      }
    }
    for (int k = i + 1; k <= n; k++) {
      if (ar[k] <= dp[i][k - 1]) {
        tmp += ar[k];
        dp[i][k] = ar[k];
      } else {
        tmp += dp[i][k - 1];
        dp[i][k] = dp[i][k - 1];
      }
    }
    if (tmp > maxx) {
      maxx = tmp;
      pos = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d%c", dp[pos][i], i == n ? '\n' : ' ');
  }
}
