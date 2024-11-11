#include <bits/stdc++.h>
using namespace std;
const long long int inf = 1e18;
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return ((a * b) / gcd(a, b));
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = ((x % p) * (x % p)) % p;
  }
  return res % p;
}
long long int modInverse(long long int n, long long int p) {
  return power(n, p - 2, p) % p;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  map<long long int, long long int> m;
  for (long long int i = 1; i <= n; i++) {
    long long int x, y;
    cin >> x >> y;
    m[x] = y;
  }
  long long int dp[1000005];
  if (m[0])
    dp[0] = 1;
  else
    dp[0] = 0;
  for (long long int i = 1; i <= 1000000; i++) {
    if (m[i]) {
      if (i - m[i] <= 0)
        dp[i] = 1;
      else
        dp[i] = dp[max(0ll, i - m[i] - 1)] + 1;
    } else
      dp[i] = dp[i - 1];
  }
  long long int ans = -inf;
  for (auto it : m) ans = max(ans, dp[it.first]);
  cout << n - ans;
  return 0;
}
