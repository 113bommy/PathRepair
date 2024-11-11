#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000 * 1000 * 1000 + 7;
const long long INF = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000;
const int MAXN = 200 * 1000 + 100;
const int MLOG = 17;
const int NMAX = 20;
long long a[MAXN], mn[MAXN][MLOG], aa[MAXN], mx[MAXN][MLOG];
int miin(int l, int r) {
  long long mini = INF;
  for (int i = MLOG - 1; i >= 0; i--)
    if (l + (1 << i) <= r) mini = min(mini, mn[l][i]), l += (1 << i);
  return min(mini, a[r]);
}
int maax(int l, int r) {
  long long maxi = -1;
  for (int i = MLOG - 1; i >= 0; i--)
    if (l + (1 << i) <= r) maxi = max(maxi, mx[l][i]), l += (1 << i);
  return max(maxi, aa[r]);
}
int main() {
  int n, s, l;
  cin >> n >> s >> l;
  for (int i = 0; i < MAXN; i++)
    for (int j = 0; j < MLOG; j++) mn[i][j] = INF, mx[i][j] = -1;
  for (int i = 0; i < n; i++)
    cin >> a[i], mn[i][0] = a[i], aa[i] = a[i], mx[i][0] = a[i];
  for (int i = n; i < MAXN; i++) a[i] = INF, aa[i] = -INF;
  for (int j = 1; j < MLOG; j++)
    for (int i = 0; i < n; i++) {
      mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
      mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
    }
  long long dp[n + 1];
  dp[0] = 0;
  deque<long long> q;
  q.push_back(0);
  for (int i = 1; i <= n; i++) dp[i] = INF;
  for (int i = l - 1; i < n; i++) {
    while ((int)(q.size()) && (maax(q.front(), i) - miin(q.front(), i)) > s)
      q.pop_front();
    if ((int)(q.size())) {
      if (q.front() > 0)
        dp[i + 1] = dp[q.front()] + 1;
      else
        dp[i + 1] = 1;
    } else
      dp[i + 1] = INF;
    int j = i - l + 1;
    while ((int)(q.size()) && dp[q.back()] >= dp[j + 1]) q.pop_back();
    q.push_back(j + 1);
  }
  if (dp[n] >= INF) dp[n] = -1;
  cout << dp[n];
}
