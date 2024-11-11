#include <bits/stdc++.h>
using namespace std;
const int max_N = 150000 + 10;
const int max_M = 300 + 10;
const long long inf = -1e18;
long long n, m, d, a[max_M], b[max_M], t[max_M], dp[2][max_N];
deque<int> q;
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> d;
  for (int i = 0; i < m; i++) cin >> a[i] >> b[i] >> t[i];
  for (int i = m - 1; i >= 0; i--) {
    int o = 1 - (i & 1);
    long long tmp = (i == m - 1) ? 0 : (t[i + 1] - t[i]) * d;
    q.clear();
    for (int j = 0; j <= min((long long)n - 1, tmp); j++) {
      while (!q.empty() && dp[o][q.back()] < dp[o][j]) q.pop_back();
      q.push_back(j);
    }
    for (int j = 0; j < n; j++) {
      while (!q.empty() && q.front() < j - tmp) q.pop_front();
      while (!q.empty() && j + tmp < n && dp[o][q.back()] < dp[o][j + tmp])
        q.pop_back();
      if (j + tmp < n) q.push_back(j + tmp);
      dp[i & 1][j] = b[i] - abs(a[i] - j - 1) + dp[o][q.front()];
    }
  }
  long long ans(inf);
  for (int i = 0; i < n; i++) ans = max(ans, dp[0][i]);
  cout << ans << "\n";
  return 0;
}
