#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  vector<long long> dp(100, 0);
  cin >> n;
  n--;
  dp[1] = 1;
  dp[0] = 0;
  long long C = 1;
  for (int i = 2; i < 45; i++) {
    C *= 2;
    dp[i] = C + dp[i - 1] * 2;
  }
  long long p = 1;
  int t = 0;
  while (p <= n) {
    p <<= 1;
    t++;
  }
  p >>= 1;
  t--;
  long long ans = 0;
  while (p > 0) {
    if (p & n) ans += dp[t] + p;
    p >>= 1;
    t--;
  }
  cout << ans;
  return 0;
}
