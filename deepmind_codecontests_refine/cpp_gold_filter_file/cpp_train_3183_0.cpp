#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const int inf = 1e9;
int dp[maxn][1 << 8];
int cur[maxn];
int a[maxn], n;
vector<int> in[10];
int can(int L) {
  for (int i = 1; i <= 8; i++) cur[i] = 0;
  memset(dp, 128, sizeof(dp));
  dp[1][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int s = 0; s < (1 << 8); s++) {
      if (dp[i][s] < 0) continue;
      for (int k = 1; k <= 8; k++) {
        if (s & (1 << (k - 1))) continue;
        if (in[k].size() - cur[k] < L - 1) continue;
        dp[in[k][cur[k] + L - 2]][s | (1 << (k - 1))] =
            max(dp[in[k][cur[k] + L - 2]][s | (1 << (k - 1))], dp[i][s]);
        if (in[k].size() - cur[k] < L) continue;
        dp[in[k][cur[k] + L - 1]][s | (1 << (k - 1))] =
            max(dp[in[k][cur[k] + L - 1]][s | (1 << (k - 1))], dp[i][s] + 1);
      }
    }
    cur[a[i]]++;
  }
  int ans = -inf;
  for (int i = 1; i <= n; i++) ans = max(ans, dp[i][(1 << 8) - 1]);
  if (ans <= 0) return 0;
  return ans * L + (8 - ans) * (L - 1);
}
int main() {
  while (cin >> n) {
    for (int i = 1; i <= n; i++) in[i].clear();
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      in[a[i]].push_back(i);
    }
    int left = 2, right = n / 8 + 1, mid, ans = -inf;
    while (left <= right) {
      mid = (left + right) / 2;
      int tmp = can(mid);
      if (tmp > 0) {
        ans = max(ans, tmp);
        left = mid + 1;
      } else
        right = mid - 1;
    }
    if (can(2) == 0) {
      ans = 0;
      for (int i = 1; i <= 8; i++)
        if (in[i].size() > 0) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
