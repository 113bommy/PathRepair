#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, ans = 1, ar[N], dp[N], mark[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> ar[i];
  sort(ar, ar + n, [&](int a, int b) { return a > b; });
  memset(mark, -1, sizeof mark);
  dp[0] = 1;
  mark[ar[0]] = 0;
  for (int i = 1; i < n; i++) {
    dp[i] = 1;
    for (int j = ar[i]; j < N; j += ar[i])
      if (mark[j] != -1) dp[i] = max(dp[i], dp[mark[j]] + 1);
    if (mark[ar[i]] == -1) mark[ar[i]] = i;
    ans = max(ans, dp[i]);
  }
  cout << ans;
}
