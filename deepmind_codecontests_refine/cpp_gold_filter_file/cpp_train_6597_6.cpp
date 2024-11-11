#include <bits/stdc++.h>
using namespace std;
long long int n, m, ar[1000005], sum, dp[1000005], val[1000005], col[1000005],
    vis[1000005];
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> val[i];
  for (int i = 1; i <= n; i++) cin >> col[i];
  while (m--) {
    long long int a, b;
    cin >> a >> b;
    for (int i = 1; i <= n; i++) dp[i] = -1e15;
    sum = 0;
    long long int mk1 = 0;
    long long int mk2 = 0;
    for (int i = 1; i <= n; i++) {
      long long int c = col[i];
      long long int t1 = max(dp[c] + a * val[i], dp[mk2] + b * val[i]);
      if (c != mk1) {
        t1 = max(t1, dp[mk1] + val[i] * b);
        if (t1 > dp[mk1])
          mk2 = mk1, mk1 = c;
        else if (t1 > dp[mk2])
          mk2 = c;
      }
      dp[c] = max(dp[c], t1);
    }
    cout << dp[mk1] << "\n";
  }
}
