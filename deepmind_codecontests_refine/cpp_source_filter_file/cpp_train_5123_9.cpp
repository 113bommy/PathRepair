#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 5;
const long long mod = 998244353;
long long dp[maxn];
long long power(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b % 2) return (power(a, b - 1) * a) % mod;
  long long T = power(a, b / 2LL);
  return (T * T) % mod;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    long long pi;
    cin >> pi;
    dp[i] = ((dp[i - 1] + 1) * ((100LL * power(pi, mod - 2)))) % mod;
  }
  cout << dp[n];
  return 0;
}
