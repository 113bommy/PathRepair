#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f;
const int Max = 5005;
long long pm[Max];
pair<long long, int> h[Max];
long long sum[Max];
long long dp[2][Max];
struct OrderedQueue {
  long long val[Max];
  int id[Max];
  int l, r;
  void init() {
    l = 0;
    r = 0;
  }
  void push(long long v, int i) {
    while (l < r && v < val[r - 1]) {
      r--;
    }
    val[r] = v;
    id[r] = i;
    r++;
  }
  long long front() { return val[l]; }
  void remove(int i) {
    while (l < r && id[l] <= i) {
      l++;
    }
  }
} que;
inline void ckMin(long long &a, long long b) {
  if (a >= b) {
    a = b;
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    cin >> pm[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> h[i].first >> h[i].second;
    tot += h[i].second;
  }
  if (tot < n) {
    cout << -1 << endl;
    return 0;
  }
  sort(pm + 1, pm + n + 1);
  sort(h + 1, h + m + 1);
  int cur = 0;
  int pre = 1;
  for (int i = 0; i < Max; i++) {
    dp[0][i] = dp[1][i] = INF;
  }
  dp[cur][0] = 0;
  dp[pre][0] = 0;
  for (int i = 1; i <= m; i++) {
    swap(cur, pre);
    for (int j = 1; j <= n; j++) {
      sum[j] = sum[j - 1] + abs(h[i].first - pm[j]);
    }
    que.init();
    for (int j = 0; j <= n; j++) {
      que.push(dp[pre][j] - sum[j], j);
      dp[cur][j] = que.front() + sum[j];
      que.remove(j - h[i].second);
    }
  }
  cout << dp[cur][n] << endl;
  return 0;
}
