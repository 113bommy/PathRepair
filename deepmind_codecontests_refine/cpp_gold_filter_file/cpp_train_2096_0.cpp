#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
long long poww(long long x, long long y) {
  if (y == 0) return 1;
  if (x == 1) return 1;
  if (x == 0) return 0;
  if (y == 1) return x;
  long long d = poww(x, y / 2);
  d %= mod;
  if (y % 2) return (((d * d) % mod) * x) % mod;
  return (d * d) % mod;
}
vector<long long int> v;
pair<long long, string> ad[1000000];
bool vis[10000];
long long min1 = 0;
long long dp[100005];
long long n, m, sum1 = 0, sum2 = 0;
long long c(long long n, long long k) {
  long long f = 1;
  for (long long i = 0; i < k; i++) f *= n - i, f /= i + 1;
  return f;
}
int main() {
  long long t;
  cin >> t;
  double a[t];
  for (long long i = 0; i < t; i++) cin >> a[i];
  for (long long j = 0; j < t; j++) {
    long long x = 0;
    if (a[j] == 179) {
      cout << 360 << endl;
      continue;
    }
    for (long long i = 3; i <= 180; i++) {
      double y = i;
      double ans = 180 / y;
      for (long long v = 1; v < 200; v++)
        if (v * ans == a[j]) {
          if (((i - 2) * 180) / i < a[j]) continue;
          cout << i << endl;
          x = 1;
          i = 998244359;
        }
    }
    if (x == 0) cout << -1 << endl;
  }
  return 0;
}
