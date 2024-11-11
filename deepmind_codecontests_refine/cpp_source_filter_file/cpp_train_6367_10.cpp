#include <bits/stdc++.h>
using namespace std;
int n, m = 1e9 + 7, dp[1000002][20][1], p1[20], p2[5];
int solve1(int x, int y) { return n / (p1[x] * p2[y]); }
int solve(int i, int x, int y) {
  if (i + x + y == 0) return 1;
  int &ans = dp[i][x][y];
  if (ans != -1) return ans;
  if (x + y == 1) {
    if (y)
      ans = solve(i + solve1(x, y - 1) - solve1(x, y), 0, 0);
    else
      ans = solve(i + solve1(x - 1, y) - solve1(x, y), 0, 0);
    return ans;
  }
  ans = 0;
  if (i) ans = (1LL * i * solve(i - 1, x, y) + ans) % m;
  if (x) {
    long long cnt = solve1(x - 1, y) - solve1(x, y);
    ans = (1LL * cnt * solve(cnt - 1 + i, x - 1, y) + ans) % m;
  }
  if (y) {
    long long cnt = solve1(x, y - 1) - solve1(x, y);
    ans = (1LL * cnt * solve(cnt - 1 + i, x, y - 1) + ans) % m;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  p1[0] = p2[0] = 1;
  for (int i = 1; i <= 19; i++) p1[i] = 2 * p1[i - 1];
  p2[1] = 3;
  memset(dp, -1, sizeof dp);
  cin >> n;
  int x = log2(n), y = 0;
  long long ans = solve(0, x, y);
  memset(dp, -1, sizeof dp);
  if (p1[x - 1] * 3 <= n) ans += solve(0, x - 1, 1);
  ans %= m;
  cout << ans;
}
