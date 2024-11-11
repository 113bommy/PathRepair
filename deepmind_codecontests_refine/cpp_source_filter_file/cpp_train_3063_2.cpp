#include <bits/stdc++.h>
using namespace std;
const int BUF = 105;
const int ACT = 20;
const int INF = 1 << 20;
int n, m, val[BUF];
pair<char, int> act[ACT];
void read() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> val[i];
  cin >> m;
  for (int i = 0; i < m; ++i) cin >> act[i].first >> act[i].second;
}
int rec(int mask, int dp[1 << ACT]) {
  int &ret = dp[mask];
  if (ret != -1) return ret;
  if (mask == (1 << m) - 1) return ret = 0;
  int idx = __builtin_popcount(mask);
  pair<char, int> curAct = act[idx];
  ret = -INF;
  int maxIdx = -1;
  for (int i = 0; i < m; ++i) {
    if (mask & (1 << i)) continue;
    int next = rec(mask | (1 << i), dp);
    if (idx + 1 < m && act[idx].second != act[idx + 1].second) next *= -1;
    if (curAct.first == 'b' && ret < next) maxIdx = i;
    if (curAct.first == 'p' && ret < val[i] + next) maxIdx = i;
    if (curAct.first == 'b')
      ret = max(ret, next);
    else
      ret = max(ret, val[i] + next);
  }
  return ret;
}
void work() {
  sort(val, val + n, greater<int>());
  static int dp[1 << ACT];
  memset(dp, -1, sizeof(dp));
  cout << (act[0].second == 1 ? 1 : -1) * rec(0, dp) << endl;
}
int main() {
  read();
  work();
  return 0;
}
