#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 7;
int dp[MAXN];
int main() {
  int m, n, i, j, k;
  cin >> m >> n;
  dp[0] = 1;
  while (m--) {
    cin >> k;
    for (i = 500000; i >= k; i--) {
      dp[i] |= dp[i - k];
    }
  }
  long long ans = 0, time = 0;
  while (1) {
    for (i = ans + n; i > ans; i--) {
      if (dp[i]) {
        ans = i;
        time++;
        goto l;
      }
    }
    break;
  l:;
  }
  cout << ans << ' ' << time << endl;
}
