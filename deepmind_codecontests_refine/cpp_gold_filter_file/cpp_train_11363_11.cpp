#include <bits/stdc++.h>
using namespace std;
long long dp[501][501];
long long fun(int l, int r) {
  if (l + 2 > r) return 0;
  if (l + 2 == r) return l * (l + 1) * (l + 2);
  if (dp[l][r] != -1) return dp[l][r];
  long long ans = 1000000000009;
  for (int i = l + 1; i < r; i++) {
    ans = min(ans, (l * r * i) + fun(l, i) + fun(i, r));
  }
  return dp[l][r] = ans;
}
int main() {
  memset(dp, -1, sizeof dp);
  int n;
  cin >> n;
  cout << fun(1, n) << endl;
}
