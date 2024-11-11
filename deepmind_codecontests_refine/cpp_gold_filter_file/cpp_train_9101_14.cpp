#include <bits/stdc++.h>
using namespace std;
long long pwr(long long base, long long p, long long mod = (1000000007LL)) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans = (ans * base) % mod;
    base = (base * base) % mod;
    p /= 2;
  }
  return ans;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long invMod(long long val) { return pwr(val, (1000000007LL) - 2); }
int r, c;
long long arr[1002][1002], DP1[1002][1002], DP2[1002][1002], DP3[1002][1002],
    DP4[1002][1002];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> r >> c;
  for (int i = 1; i <= r; i++)
    for (int j = 1; j <= c; j++) cin >> arr[i][j];
  for (int i = 1; i <= r; i++)
    for (int j = 1; j <= c; j++)
      DP1[i][j] = max(DP1[i - 1][j], DP1[i][j - 1]) + arr[i][j];
  for (int i = r; i >= 1; i--)
    for (int j = c; j >= 1; j--)
      DP2[i][j] = max(DP2[i + 1][j], DP2[i][j + 1]) + arr[i][j];
  for (int i = r; i >= 1; i--)
    for (int j = 1; j <= c; j++)
      DP3[i][j] = max(DP3[i + 1][j], DP3[i][j - 1]) + arr[i][j];
  for (int i = 1; i <= r; i++)
    for (int j = c; j >= 1; j--)
      DP4[i][j] = max(DP4[i - 1][j], DP4[i][j + 1]) + arr[i][j];
  long long ans = 0;
  for (int i = 2; i < r; i++)
    for (int j = 2; j < c; j++) {
      ans = max(ans,
                DP1[i][j - 1] + DP3[i + 1][j] + DP2[i][j + 1] + DP4[i - 1][j]);
      ans = max(ans,
                DP1[i - 1][j] + DP3[i][j - 1] + DP2[i + 1][j] + DP4[i][j + 1]);
    }
  cout << ans;
  return 0;
}
