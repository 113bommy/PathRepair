#include <bits/stdc++.h>
using namespace std;
const int mod = 1e8;
int a, b;
long long dp[105][105][2];
long long solve(bool turn, int soldiers, int horses) {
  if (dp[soldiers][horses][turn] != -1) return dp[soldiers][horses][turn];
  if (turn) {
    if (horses == 0) return soldiers == 0;
    long long res = 0;
    for (int i = 1; i <= b && i <= horses; i++) {
      res += solve(0, soldiers, horses - i) % mod;
    }
    return dp[soldiers][horses][turn] = res % mod;
  }
  if (soldiers == 0) return horses == 0;
  long long res = 0;
  for (int i = 1; i <= a && i <= soldiers; i++) {
    res += solve(1, soldiers - i, horses) % mod;
  }
  return dp[soldiers][horses][turn] = res % mod;
}
int main() {
  memset(dp, -1, sizeof(dp));
  int n, m;
  cin >> n >> m >> a >> b;
  long long res = 0;
  for (int i = 0; i <= a && i <= n; i++) {
    res += solve(1, n - i, m) % mod;
  }
  cout << res % mod << '\n';
  return 0;
}
