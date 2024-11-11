#include <bits/stdc++.h>
using namespace std;
int mod;
int Dp[1005][1005][2];
int powers[1005], powers2[1005], k, n;
int solve(int ind, int rem, bool change) {
  if (rem == 0 && change)
    return (ind != n ? ((powers[n - ind - 1] * 1LL * 9) % mod) : 1);
  if (ind == n || (rem == 0 && change)) return 0;
  int &temp = Dp[ind][rem][change];
  if (temp != -1) return temp;
  temp = 0;
  for (int i = 0; i < 10; i++)
    temp += solve(ind + 1, (rem + (i * 1LL * powers2[ind]) % k) % k,
                  change || i != 0);
  temp %= mod;
  return temp;
}
int main() {
  cin >> n >> k >> mod;
  memset(Dp, -1, sizeof(Dp));
  long long y = 1;
  for (int i = 0; i <= n; i++) {
    powers[i] = y;
    y *= 10;
    y %= mod;
  }
  y = 1;
  for (int i = 0; i <= n; i++) {
    powers2[i] = y;
    y *= 10;
    y %= k;
  }
  cout << solve(0, 0, 0);
  return 0;
}
