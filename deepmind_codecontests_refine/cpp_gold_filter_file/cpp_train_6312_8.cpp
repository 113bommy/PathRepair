#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 10;
const long long INF = 1e18;
const long long mod = 1e9 + 7;
long long pw(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long k = pw(a, b / 2);
  k = (k * k) % mod;
  if (b & 1) k = (k * a) % mod;
  return k;
}
map<long long, long long> dp;
vector<long long> v;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long x, y;
  cin >> x >> y;
  if (y % x) return cout << 0, 0;
  long long S = y / x;
  for (long long i = 1; i < sqrt(S); i++)
    if (S % i == 0) {
      v.push_back(i);
      v.push_back(S / i);
    }
  x = sqrt(S);
  if ((x * x) == S) v.push_back(x);
  sort(v.begin(), v.end());
  dp[1] = 1;
  for (long long i = 1; i < v.size(); i++) {
    long long s = v[i];
    dp[s] = pw(2, s - 1);
    dp[s] = (dp[s] - dp[1] + mod) % mod;
    for (long long j = 2; j < sqrt(s); j++)
      if (s % j == 0) dp[s] = (dp[s] - dp[j] - dp[s / j] + mod + mod) % mod;
    long long x = sqrt(s);
    if (x * x == s) dp[s] = (dp[s] - dp[x] + mod) % mod;
  }
  cout << dp[S];
}
