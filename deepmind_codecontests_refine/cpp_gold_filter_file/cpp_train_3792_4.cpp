#include <bits/stdc++.h>
using namespace std;
const long long maxN = 2002;
const long long maxS = 32023;
const long long MOD = 1000000007;
long long dp[2][maxS * 2], a[maxN], n, ans;
long long &f(int i, int s) {
  if (s < 0) return dp[i % 2][s + maxS];
  return dp[i % 2][s];
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    for (int s = -10000; s <= 10000; s++) f(i, s) = 0;
    f(i, a[i]) = f(i, -a[i]) = 1;
    for (int s = -10000; s <= 10000; s++)
      f(i, s) = (f(i, s) + f(i - 1, s - a[i]) + f(i - 1, s + a[i])) % MOD;
    ans = (ans + f(i, 0)) % MOD;
  }
  cout << ans << endl;
  cin >> n;
}
