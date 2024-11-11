#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f * x;
}
const long long MAXN = 5500;
long long n, m, k;
long long a[MAXN];
long long dp[MAXN][MAXN];
deque<long long> q[MAXN];
long long get(long long i, long long j) {
  if (q[j].empty() || q[j].front() == 0 || j == 0) {
    if (i > k)
      return -1;
    else
      return 0;
  }
  return q[j].front();
}
signed main() {
  memset(dp, -1, sizeof(dp));
  n = read();
  k = read();
  m = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  if (m * (k * 2 - 1) < n) {
    cout << -1 << endl;
    return 0;
  }
  dp[0][0] = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= min(i, m); j++) {
      while (!q[j - 1].empty() && q[j - 1].front() < i - k)
        q[j - 1].pop_front();
      if (!q[j - 1].empty() && dp[q[j - 1].front()][j - 1] == -1) continue;
      if (i > k && j == 1) continue;
      if (q[j - 1].empty())
        dp[i][j] = a[i];
      else
        dp[i][j] = dp[q[j - 1].front()][j - 1] + a[i];
    }
    for (long long j = 1; j <= min(i, m); j++) {
      while (!q[j].empty() && dp[q[j].back()][j] < dp[i][j]) q[j].pop_back();
      q[j].push_back(i);
    }
  }
  long long ans = 0;
  for (long long i = n - k + 1; i <= n; i++) ans = max(ans, dp[i][m]);
  cout << ans << endl;
  return 0;
}
