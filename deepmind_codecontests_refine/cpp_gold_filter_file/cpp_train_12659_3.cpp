#include <bits/stdc++.h>
using namespace std;
long long dp[5000005], p[5000005];
int main() {
  ios::sync_with_stdio(0);
  long long t, l, r, ans = 0, M = 1000000007;
  p[0] = p[1] = 1;
  for (int i = 2; i <= 5000004; i++) {
    if (p[i] == 0) {
      for (int j = 1; j * i <= 5000004; j++)
        if (p[j * i] == 0) p[j * i] = i;
    }
  }
  dp[0] = dp[1] = 0;
  for (int i = 2; i <= 5000004; i++) {
    dp[i] = ((i * (p[i] - 1)) / 2 + dp[i / p[i]]) % M;
  }
  cin >> t >> l >> r;
  long long tt = 1;
  for (int i = l; i <= r; i++) {
    ans = (ans + (tt * dp[i]) % M) % M;
    tt = (tt * t) % M;
  }
  cout << ans;
}
