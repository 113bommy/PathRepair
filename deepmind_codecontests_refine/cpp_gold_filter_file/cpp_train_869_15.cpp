#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5010;
pair<double, int> x[MAXN];
int dp[MAXN];
int main() {
  int n, m, mx = 1;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> x[i].second >> x[i].first;
  sort(x, x + n);
  dp[0] = 1;
  for (int i = 1; i < n; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++)
      if (x[j].second <= x[i].second) dp[i] = max(dp[i], dp[j] + 1);
    mx = max(mx, dp[i]);
  }
  cout << n - mx << endl;
  return 0;
}
