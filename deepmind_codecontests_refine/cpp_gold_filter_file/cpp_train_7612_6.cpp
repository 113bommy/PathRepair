#include <bits/stdc++.h>
using namespace std;
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long gcd(long long a, long long b) {
  if (a < b)
    return gcd(b, a);
  else if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long isPrime(long long n) {
  long long p = (long long)sqrt(n);
  for (long long i = 2; 2 < p + 1 ? i < p + 1 : i > p + 1;
       2 < p + 1 ? i += 1 : i -= 1)
    if (n % i == 0) return 0;
  return 1;
}
long long pow(long long b, long long e) {
  if (e == 0)
    return 1;
  else if (e % 2 == 0) {
    long long a = pow(b, e / 2);
    return a * a;
  } else {
    long long a = pow(b, e / 2);
    return b * a * a;
  }
}
long long pow_m(long long x, long long y, long long m = 1000000007) {
  x = x % m;
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x;
    res %= m;
    y = y >> 1;
    x = x * x;
    x %= m;
  }
  return res;
}
long long modInverse(long long a, long long m) { return pow_m(a, m - 2, m); }
long long max(long long a, long long b) {
  if (a >= b)
    return a;
  else
    return b;
}
long long min(long long a, long long b) {
  if (a <= b)
    return a;
  else
    return b;
}
long long dp[static_cast<int>(2e5 + 100)][3];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n, l, r;
  cin >> n >> l >> r;
  long long a = r / 3 - (l - 1) / 3;
  long long b = (r + 2) / 3 - (l + 1) / 3;
  long long c = (r + 1) / 3 - l / 3;
  dp[1][0] = a;
  dp[1][1] = b;
  dp[1][2] = c;
  for (long long i = 2; 2 < n + 1 ? i < n + 1 : i > n + 1;
       2 < n + 1 ? i += 1 : i -= 1) {
    dp[i][0] = (dp[i - 1][0] * a % 1000000007 + dp[i - 1][1] * c % 1000000007 +
                dp[i - 1][2] * b % 1000000007) %
               1000000007;
    dp[i][1] = (dp[i - 1][0] * b % 1000000007 + dp[i - 1][1] * a % 1000000007 +
                dp[i - 1][2] * c % 1000000007) %
               1000000007;
    dp[i][2] = (dp[i - 1][0] * c % 1000000007 + dp[i - 1][1] * b % 1000000007 +
                dp[i - 1][2] * a % 1000000007) %
               1000000007;
  }
  cout << dp[n][0] << endl;
  return 0;
}
