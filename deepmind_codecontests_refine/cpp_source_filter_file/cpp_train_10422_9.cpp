#include <bits/stdc++.h>
using namespace std;
const long long max3 = 1003;
const long long max4 = 10004;
const long long max5 = 100005;
const long long max6 = 1000006;
const long long max7 = 10000007;
const long long lg4 = 13;
const long long lg5 = 17;
const long long lg6 = 20;
const long long INF = 2LL * 1000000000;
const long long INFLL = 9LL * 1000000000 * 1000000000;
const long long M = 1e9 + 7;
long long powmod(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
  }
  return res;
}
long long gcd(long long a, long long b) {
  while (b > 0) {
    long long t = a % b;
    a = b, b = t;
  }
  return a;
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long is_prime(long long n) {
  if (n <= 1 || n > 3 && (n % 2 == 0 || n % 3 == 0)) return 0;
  for (long long i = 5, t = 2; i * i <= n; i += t, t = 6 - t)
    if (n % i == 0) return 0;
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  int n;
  cin >> n;
  vector<long long> l(n), r(n);
  for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
  int ans = n;
  sort((l).begin(), (l).end());
  sort((r).begin(), (r).end());
  for (int i = 0; i < n; i++) ans += max(l[i], r[i]);
  cout << ans << "\n";
  return 0;
}
