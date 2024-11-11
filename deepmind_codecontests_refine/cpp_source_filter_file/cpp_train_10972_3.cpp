#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void checkMin(T& a, T b) {
  if (a > b) a = b;
}
template <typename T>
inline void checkMax(T& a, T b) {
  if (a < b) a = b;
}
template <class T>
inline T Min(T x, T y) {
  return (x > y ? y : x);
}
template <class T>
inline T Max(T x, T y) {
  return (x < y ? y : x);
}
long long mod = 1000000009;
long long n, m, k;
long long ans;
long long quickpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return ans;
}
int main() {
  cin >> n >> m >> k;
  ans = 0;
  long long wa = n - m;
  long long r = (n - m) * k;
  if (r >= n)
    ans = n - m;
  else {
    long long nn = n - r;
    long long a = nn / k;
    long long b = nn % k;
    ans = ((quickpow(2, a + 1) - 2 + mod) % mod) * k % mod;
    ans += b + wa * (k - 1) % mod;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
