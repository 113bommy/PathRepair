#include <bits/stdc++.h>
using namespace std;
int dp[10][1000001];
int f(int i) {
  int k = 1;
  if (i < 10) return i;
  while (i > 0) {
    int d = i % 10;
    if (d != 0) k *= d;
    i /= 10;
  }
  return f(k);
}
void solve() {
  for (int i = 1; i <= 1e6; i++) dp[f(i)][i]++;
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j <= 1e6; j++) dp[i][j] += dp[i][j - 1];
  }
}
int main() {
  solve();
  int t;
  cin >> t;
  while (t-- > 0) {
    int l, r, k;
    cin >> l >> r >> k;
    cout << dp[k][r + 1] - dp[k][l - 1] << "\n";
  }
  return 0;
}
