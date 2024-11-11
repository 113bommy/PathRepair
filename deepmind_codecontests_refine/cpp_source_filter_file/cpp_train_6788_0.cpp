#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 * 1000 + 7;
const long long DELTA = 998244353;
long long fac[MAXN];
void fact() {
  fac[0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    fac[i] = i * fac[i - 1];
    fac[i] %= DELTA;
  }
  return;
}
long long dp[MAXN];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  fact();
  dp[3] = 9;
  for (int i = 4; i <= n; ++i) {
    dp[i] =
        (((i * dp[i - 1]) % DELTA) + (i * (fac[i - 1] - 1) % DELTA)) % DELTA;
  }
  cout << dp[n] << endl;
  return 0;
}
