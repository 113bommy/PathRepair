#include <bits/stdc++.h>
using namespace std;
const int N = 105, M = 2505, mod = 1e9 + 7;
int t, n, m, dp[N][M];
string second;
int sum() {
  int ret = 0;
  for (auto i : second) ret += i - 'a' + 1;
  return ret;
}
int solve(int i, int sm) {
  if (i == n) return (sm == 0);
  int &x = dp[i][sm];
  if (x != -1) return x;
  x = 0;
  for (int j = 1; j <= min(sm, 26); j++) x = (x + solve(i + 1, sm - j)) % mod;
  return x;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memset(dp, -1, sizeof dp);
  cin >> t;
  while (t--) {
    cin >> second;
    n = second.size();
    m = sum();
    cout << (solve(0, m) - 1 + mod) % mod << '\n';
  }
}
