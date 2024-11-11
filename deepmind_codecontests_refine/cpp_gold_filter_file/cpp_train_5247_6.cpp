#include <bits/stdc++.h>
const int INF = 1e6;
using namespace std;
const int maxn = 1e5 + 5;
const int ma = 1e9 + 5;
int a[maxn], dp[maxn];
stack<int> s;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, i, ans = 0;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  dp[0] = INF;
  s.push(0);
  for (i = 1; i <= n; i++) {
    dp[i] = 1;
    while (!s.empty() && a[i] > a[s.top()]) {
      dp[i] = max(dp[i], dp[s.top()] + 1);
      s.pop();
    }
    s.push(i);
  }
  for (i = 1; i <= n; i++) {
    if (dp[i] < INF) ans = max(ans, dp[i]);
  }
  cout << ans;
  return 0;
}
