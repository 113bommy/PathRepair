#include <bits/stdc++.h>
using namespace std;
const long long int Mod = 998244353;
const long long int mod = 1e9 + 7;
long long int Pow(long long int a, long long int b) {
  a = a % mod;
  long long int res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return (res % mod);
}
long long int modInverse(long long int a, long long int m) {
  return Pow(a, m - 2);
}
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
const int N = 5e6;
long long int dp[N + 1];
int spf[N + 1];
void fun() {
  for (int i = 1; i <= N; i++) {
    spf[i] = i;
    dp[i] = (i * (i - 1) / 2) % mod;
  }
  for (int i = 2; i <= sqrt(N); i++) {
    if (spf[i] == i) {
      for (int j = i * i; j <= N; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
  for (int i = 2; i <= N; i++) {
    dp[i] = ((i / spf[i]) * 1ll * dp[spf[i]] + dp[i / spf[i]]) % mod;
  }
}
void solve() {
  fun();
  int t, l, r;
  cin >> t >> l >> r;
  long long int res = 0, p = 1;
  for (int i = l; i <= r; i++) {
    res += p * dp[i] % mod;
    p = (p * 1ll * t) % mod;
  }
  cout << res % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
