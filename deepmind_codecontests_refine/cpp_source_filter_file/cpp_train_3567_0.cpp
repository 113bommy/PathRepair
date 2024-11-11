#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,avx2,popcnt,fma")
#pragma GCC optimize("fast-math")
using namespace std;
const long long mod = 1e9 + 7, mod2 = 998244353;
const long double eps = 1e-6;
const long long inf = 1e18;
const int base = 1e9;
const long double PI = 3.14159265358979;
int a[1000 * 1000], n, r1, r2, r3, d;
long long dp[1000 * 1000][2];
unsigned int bitcount(unsigned long long val) {
  return __builtin_popcount(val) + __builtin_popcount(val >> 32);
}
void local() { freopen("test.in", "r", stdin); }
void remote() {}
void read() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> r1 >> r2 >> r3 >> d;
  for (int i = 0; i < n; i++) cin >> a[i];
}
int main() {
  remote();
  read();
  dp[0][0] = a[0] * r1 + r3;
  dp[0][1] = min(a[0] * r1 + r1, r2);
  for (int i = 1; i < n; i++) {
    long long prev = min(dp[i - 1][0] + d, 3 * d + dp[i - 1][1] + r1);
    dp[i][1] = prev + min(a[i] * r1 + r1, r2);
    dp[i][0] =
        min(a[i] * r1 + r3 + prev, min(dp[i - 1][0], dp[i - 1][1] + r1) +
                                       3 * d + min(r2, a[i] * r1 + r1) + r1);
  }
  cout << min(dp[n - 1][0], n > 1 ? min(dp[n - 2][0], dp[n - 2][1] + r1) +
                                        2 * d + a[n - 1] * r1 + r3
                                  : INT64_MAX)
       << '\n';
  ;
}
