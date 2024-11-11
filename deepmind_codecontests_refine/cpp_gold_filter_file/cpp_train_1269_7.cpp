#include <bits/stdc++.h>
using namespace std;
int const N = 1e5 + 5;
int const MOD = 1e9 + 7;
int dp[N], dp2[N];
int add_mod(int x, int y) { return (x + y) % MOD; }
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  dp[0] = dp[1] = 2;
  for (int i = 2; i < N; i++) {
    dp[i] = add_mod(dp[i - 1], dp[i - 2]);
  }
  cout << add_mod(add_mod(dp[m], MOD - 2), dp[n]) << endl;
}
