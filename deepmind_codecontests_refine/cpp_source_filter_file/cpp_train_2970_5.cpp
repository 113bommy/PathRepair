#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int MOD = 1e9 + 7;
const int INF32 = 1 << 30;
const long long INF64 = 1LL << 60;
const long double pi = acos(-1);
long long gcd(long long a, long long b) { return (!b ? a : gcd(b, a % b)); }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long mul(long long a, long long b) { return a * b % MOD; }
long long modpow(long long b, long long i) {
  long long s = 1;
  while (i) {
    if (i % 2) s = (s * b) % MOD;
    b = (b * b) % MOD;
    i /= 2;
  }
  return s;
}
long long inv(long long a) { return modpow(a, MOD - 2); }
void solve() {
  long long n, r;
  cin >> n >> r;
  cout << fixed << setprecision(10);
  cout << n * r * r / (1 / tan(pi / n / 2) + 1 / tan(pi / n));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
