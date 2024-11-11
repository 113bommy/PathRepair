#include <bits/stdc++.h>
using namespace std;
int dp[550001], c[10005];
int main() {
  int n, d;
  cin >> n >> d;
  for (register int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  for (register int i = 1; i <= n; i++) {
    for (register int j = 550000; j >= c[i]; j--) {
      if (dp[j - c[i]] == 1) dp[j] = 1;
    }
  }
  register int now = 0, t = 0;
  for (; t <= n; t++) {
    int e = now + d;
    for (register int i = e; i >= now; i--) {
      if (dp[i] == 1) {
        now = i;
        break;
      }
    }
    if (e == now + d) break;
  }
  cout << now << ' ' << t << endl;
  return 0;
}
