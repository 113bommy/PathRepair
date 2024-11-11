#include <bits/stdc++.h>
using namespace std;
int dd[100005], dp[100005], n, m, i, a[100005], b[100005], pos, mx, l, r, mid,
    c[100005], s[100005];
inline bool check(int x) {
  if (c[1] > x) return 0;
  dp[0] = 1;
  if (c[1] == 1) {
    dp[1] = x;
  } else
    dp[1] = c[1];
  for (i = 2; i < n; ++i) {
    dp[i] = -1e9;
    if (dp[i - 1] >= s[i] - 1) {
      dp[i] = s[i] + x - 1;
    }
    if (dp[i - 1] >= s[i] - x) {
      dp[i] = max(dp[i], s[i]);
    }
    if (dp[i - 2] >= s[i] - x + 1) {
      dp[i] = max(dp[i], s[i - 1] + x - 1);
    }
  }
  if (dp[n - 1] >= m - x) return 1;
  dp[0] = dp[1] = x - 1;
  for (i = 2; i < n; ++i) {
    dp[i] = -1e9;
    if (dp[i - 1] >= s[i] - 1) {
      dp[i] = s[i] + x - 1;
    }
    if (dp[i - 1] >= s[i] - x) {
      dp[i] = max(dp[i], s[i]);
    }
    if (dp[i - 2] >= s[i] - x) {
      dp[i] = max(dp[i], s[i - 1] + x - 1);
    }
  }
  if (dp[n - 1] >= m - x + c[1]) return 1;
  return 0;
}
int main() {
  cin >> m >> n;
  for (i = 1; i <= n; ++i) cin >> a[i];
  if (n == 1) return cout << m - 1, 0;
  a[n + 1] = m + a[1];
  for (i = 1; i <= n; ++i) b[i] = a[i + 1] - a[i];
  for (i = 1; i <= n; ++i)
    if (b[i] > mx) mx = b[i], pos = i;
  for (i = pos + 1; i <= n; ++i) c[i - pos] = b[i];
  for (i = 1; i < pos; ++i) c[i + n - pos] = b[i];
  for (i = 1; i <= n; ++i) s[i] = c[i] + s[i - 1];
  l = 1;
  r = mx;
  while (l < r) {
    mid = (l + r >> 1);
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  cout << l - 1;
}
