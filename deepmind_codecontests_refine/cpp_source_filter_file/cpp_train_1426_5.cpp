#include <bits/stdc++.h>
using namespace std;
long long pwr(long long a, long long b, long long mod) {
  a %= mod;
  if (a < 0) a += mod;
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b /= 2;
  }
  return ans;
}
long long pwr(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    a *= a;
    b /= 2;
  }
  return ans;
}
long long gcd(long long a, long long b) {
  while (b) {
    long long temp = a;
    a = b;
    b = temp % b;
  }
  return a;
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
string toString(int j) {
  string s = "";
  while (j) {
    int temp = j % 10;
    s += temp + '0';
    j = j / 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
long long modularInverse(long long a, long long m) {
  assert(false);
  return pwr(a, m - 2, m);
}
const int mod = 1000000007;
long long dp[40][40];
long long DP(int n, int h) {
  if (n == 0 && h > 0) return 0;
  if (h == 0 && n > 0) return 0;
  if (n == 0 && h == 0) return 1;
  if (h == 1 && n == 1) return 1;
  if (dp[n][h] != -1) return dp[n][h];
  long long ans1 = 0, ans2 = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= h - 1; j++) {
      ans1 += (DP(i - 1, h - 1) * DP(n - i, j));
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= h - 2; j++) {
      ans2 += (DP(n - i, h - 1) * DP(i - 1, j));
    }
  }
  return dp[n][h] = ans1 + ans2;
}
int main() {
  memset(dp, -1, sizeof(dp));
  int n, h;
  cin >> n >> h;
  int ans = 0;
  for (int i = h; i <= n; i++) ans += DP(n, i);
  cout << ans << endl;
  return 0;
}
