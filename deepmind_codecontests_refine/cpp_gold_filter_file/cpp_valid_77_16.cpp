#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long INF = INT_MAX;
const long double pi = 4 * atan((long double)1);
template <class T>
inline T gcd(T a, T b) {
  if (b)
    return gcd(b, a % b);
  else
    return a;
}
template <class T>
inline T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
long long f[4000006];
signed main() {
  ios::sync_with_stdio();
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, m;
  scanf("%lld%lld", &n, &m);
  f[1] = 1;
  for (long long i = 2; i <= n; ++i) {
    f[i] += ((2 * f[i - 1] + 1) % m);
    f[i] = f[i] % m;
    if (i == 2) f[i]--;
    for (long long j = 2 * i; j <= n; j += i) {
      f[j] += (f[i] - f[i - 1]);
      f[j] = (f[j] + m) % m;
    }
  }
  cout << f[n];
}
