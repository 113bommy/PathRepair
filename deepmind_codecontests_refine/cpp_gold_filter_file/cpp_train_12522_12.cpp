#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  for (; b; a %= b, swap(a, b))
    ;
  return a;
}
const int INF = 987654321;
int n, m;
string a, b;
int dp[5001][5001];
int solve(int ai, int bi) {
  if (ai >= n || bi >= m) return 0;
  int& ret = dp[ai][bi];
  if (ret != -INF) return ret;
  ret = 0;
  if (a[ai] == b[bi]) {
    ret = 2;
    int res = solve(ai + 1, bi + 1) + 2;
    ret = max(ret, res);
  }
  int r1 = solve(ai + 1, bi) - 1;
  int r2 = solve(ai, bi + 1) - 1;
  ret = max(ret, r1);
  ret = max(ret, r2);
  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  fill(&dp[0][0], &dp[5000][5000] + 1, -INF);
  cin >> n >> m;
  cin >> a >> b;
  solve(0, 0);
  int res = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) res = max(res, dp[i][j]);
  cout << res;
}
