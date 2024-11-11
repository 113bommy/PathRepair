#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2001;
const long long INF = 1e9;
int DELTA = 2001;
int n;
long long price[MAXN], Time[MAXN];
long long dp[MAXN][3 * MAXN];
long long rec(int idx, int remTime) {
  if (remTime >= MAXN) remTime = MAXN - 1;
  if (idx == n) return remTime >= 0 ? 0 : INF;
  long long &ans = dp[idx][remTime + DELTA];
  if (ans != -1) return ans;
  ans = INF;
  ans = min(ans, rec(idx + 1, remTime - 1));
  ans = min(ans, price[idx] + rec(idx + 1, remTime + Time[idx]));
  return ans;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> Time[i] >> price[i];
  memset(dp, -1, sizeof(dp));
  cout << rec(0, 0) << endl;
  return 0;
}
