#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long dp[N], color[N], x[N], y[N], a, b, n, q, num, num2;
long long solve(int now) {
  dp[now] = b * x[now];
  if (y[num] == y[now])
    dp[now] = max(dp[now], dp[num2] + b * x[now]);
  else
    dp[now] = max(dp[now], dp[num] + b * x[now]);
  if (color[y[now]] != -1)
    dp[now] = max(dp[color[y[now]]] + a * x[now], dp[now]);
  if (color[y[now]] == -1)
    color[y[now]] = now;
  else if (dp[color[y[now]]] < dp[now])
    color[y[now]] = now;
  if (dp[now] > dp[num] || num == 0) {
    if (y[now] != y[num]) num2 = num;
    num = now;
  } else if (y[now] != y[num] && (dp[num2] < dp[now] || num2 == 0))
    num2 = now;
  return dp[now];
}
int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> x[i];
  for (int i = 1; i <= n; i++) cin >> y[i];
  for (int i = 0; i < q; i++) {
    long long ans = -1e18;
    cin >> a >> b;
    num = 0, num2 = 0;
    for (int j = 1; j <= n; j++) dp[j] = -1e18, color[j] = -1;
    for (int j = 1; j <= n; j++) {
      long long lc = solve(j);
      ans = max(ans, lc);
    }
    cout << ans << endl;
  }
  return 0;
}
