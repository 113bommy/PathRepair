#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18 + 5;
long long fastPow(long long x, int p) {
  long long answer = 1, current = x;
  while (p != 0) {
    if (p % 2 != 0) {
      if (answer > inf / current + 1) return inf;
      answer *= current;
    }
    p /= 2;
    if (current <= inf / current + 1)
      current *= current;
    else
      current = inf;
  }
  return answer;
}
long long dp[70];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    memset(dp, 0, sizeof(dp));
    dp[1] = n - 1;
    long long lastAns = n;
    for (int p = 2; p < 65; p++) {
      long long l = 1, r = lastAns, mid;
      while (l + 1 < r) {
        mid = (l + r) / 2;
        if (fastPow(mid, p) <= n)
          l = mid;
        else
          r = mid - 1;
      }
      if (fastPow(r, p) <= n)
        lastAns = r;
      else
        lastAns = l;
      dp[p] = lastAns - 1;
    }
    for (int i = 64; i >= 2; i--) {
      for (int d = 1; d * d <= i; d++) {
        if (i % d == 0) {
          dp[d] -= dp[i];
          if (d != 1 && i / d != d) dp[i / d] -= dp[i];
        }
      }
    }
    cout << dp[1] << '\n';
  }
}
