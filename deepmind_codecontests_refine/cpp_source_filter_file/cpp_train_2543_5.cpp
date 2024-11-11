#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005], p[1005], n;
long long solve(int pos, int des) {
  if (pos == des) return 0;
  if (dp[pos][des] != -1) return dp[pos][des];
  int t = (solve(pos + 1, des) + 1 + solve(p[pos], pos) + 1) % 10000000007;
  return dp[pos][des] = t;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }
  memset(dp, -1, sizeof(dp));
  cout << solve(0, n);
}
