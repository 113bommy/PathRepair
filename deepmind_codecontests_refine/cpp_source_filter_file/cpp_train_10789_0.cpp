#include <bits/stdc++.h>
using namespace std;
long long tot, n, w, b, x;
deque<pair<long long, long long> > maxq;
void add(long long val, long long pos) {
  while (maxq.size() > 0 && maxq.back().first <= val) maxq.pop_back();
  maxq.push_back({val, pos});
}
long long query() { return maxq.front().first; }
void erase(long long pos) {
  while (maxq.size() > 0 && maxq.front().second < pos) maxq.pop_front();
}
int main() {
  cin >> n >> w >> b >> x;
  long long c[n], cost[n];
  for (int i = 0; i < n; i++) cin >> c[i];
  for (int j = 0; j < n; j++) cin >> cost[j];
  long long dp[n][10005], temp;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 10005; j++) dp[i][j] = -1000000000000ll * n;
  for (long long j = 0; j < 10001; j++) {
    if (j <= c[0]) {
      if (w - cost[0] * j < 0)
        dp[0][j] = -1000000000000ll * n;
      else
        dp[0][j] = min(w + b * j, w - cost[0] * j + x);
    } else
      dp[0][j] = -1000000000000ll * n;
  }
  for (int i = 1; i < n; i++) {
    maxq.clear();
    tot = 0;
    for (long long j = 0; j < 10001; j++) {
      add(dp[i - 1][j] + x - tot, j);
      temp = query() + tot;
      if (temp < 0)
        dp[i][j] = -1000000000000ll * n;
      else
        dp[i][j] = min(w + b * j, temp);
      tot -= cost[i];
      erase(j - c[i] + 1);
    }
  }
  for (int i = 10000; i >= 0; i--) {
    if (dp[n - 1][i] > 0) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
