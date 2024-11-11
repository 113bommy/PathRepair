#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100001;
const long long MOD = 1000000007;
const long long INF = 1e18;
long long add(long long a, long long b) { return (a + b) % MOD; }
long long sub(long long a, long long b) { return (a - b + MOD) % MOD; }
long long mul(long long a, long long b) { return (a * b) % MOD; }
long long ADD(long long &a, long long b) { return a = add(a, b); }
long long SUB(long long &a, long long b) { return a = sub(a, b); }
long long MUL(long long &a, long long b) { return a = mul(a, b); }
long long n, m;
vector<vector<int>> grid;
long long dp[1 << 15][2][2], temp[1 << 15][2][2];
int main(int argc, const char *argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  if (n <= m) {
    grid = vector<vector<int>>(n, vector<int>(m, 0));
    for (int i = (0); i < (n); i++)
      for (int j = (0); j < (m); j++) {
        char x;
        cin >> x;
        if (x == 'x') grid[i][j] = 1;
      }
  } else {
    grid = vector<vector<int>>(m, vector<int>(n, 0));
    for (int j = (0); j < (n); j++)
      for (int i = (0); i < (m); i++) {
        char x;
        cin >> x;
        if (x == 'x') grid[i][j] = 1;
      }
    swap(n, m);
  }
  for (int j = (0); j < (m); j++) {
    for (int i = (0); i < (n); i++) {
      if (!i && !j) {
        if (!grid[i][j]) {
          dp[1][1][0] = 1;
          dp[0][0][1] = 1;
        } else
          dp[0][0][0] = 1;
        continue;
      }
      if (grid[i][j]) {
        for (int mask = (0); mask < (1 << n); mask++)
          for (int k1 = (0); k1 < (2); k1++)
            for (int k2 = (0); k2 < (2); k2++)
              ADD(temp[mask & (~(1 << i))][0][k2], dp[mask][k1][k2]);
        for (int mask = (0); mask < (1 << n); mask++)
          for (int k1 = (0); k1 < (2); k1++)
            for (int k2 = (0); k2 < (2); k2++)
              dp[mask][k1][k2] = temp[mask][k1][k2], temp[mask][k1][k2] = 0;
        continue;
      }
      for (int mask = (0); mask < (1 << n); mask++)
        for (int k1 = (0); k1 < (2); k1++) {
          if (k1 || mask & (1 << i)) {
            ADD(temp[mask][k1][0], dp[mask][k1][0]);
            ADD(temp[mask][k1][1], dp[mask][k1][1]);
          } else
            ADD(temp[mask][k1][1], dp[mask][k1][0]);
        }
      for (int mask = (0); mask < (1 << n); mask++)
        for (int k1 = (0); k1 < (2); k1++)
          for (int k2 = (0); k2 < (2); k2++)
            ADD(temp[mask | (1 << i)][1][k2], dp[mask][k1][k2]);
      for (int mask = (0); mask < (1 << n); mask++)
        for (int k1 = (0); k1 < (2); k1++)
          for (int k2 = (0); k2 < (2); k2++)
            dp[mask][k1][k2] = temp[mask][k1][k2], temp[mask][k1][k2] = 0;
    }
    for (int mask = (0); mask < (1 << n); mask++)
      for (int k2 = (0); k2 < (2); k2++)
        ADD(dp[mask][0][k2], dp[mask][1][k2]), dp[mask][1][k2] = 0;
  }
  long long ans = 0;
  for (int mask = (0); mask < (1 << n); mask++)
    for (int k1 = (0); k1 < (2); k1++)
      for (int k2 = (0); k2 < (2); k2++) ADD(ans, dp[mask][k1][k2]);
  cout << ans << endl;
  return 0;
}
