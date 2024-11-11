#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 20;
int dp[N], a[N];
bool e[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(e, false, sizeof(e));
    memset(dp, 0, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (i == 1)
        dp[i] = a[i];
      else
        dp[i] = dp[i - 1] + a[i];
    }
    int cnt = 0;
    for (int i = 1; i < n; i++)
      for (int j = i + 1; j <= n; j++)
        if (dp[j] - dp[i - 1] <= n) e[dp[j] - dp[i - 1]] = true;
    for (int i = 1; i <= n; i++)
      if (e[a[i]]) cnt++;
    cout << cnt << endl;
  }
}
