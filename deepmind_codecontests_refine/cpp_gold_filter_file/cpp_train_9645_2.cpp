#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
long long max3(long long x, long long y, long long z) {
  return max(max(x, y), z);
}
long long min3(long long x, long long y, long long z) {
  return min(min(x, y), z);
}
const long long N = 1e5 + 10, M = 2e5 + 10, M2 = 1e6 + 10, mod = 1e9 + 7,
                inf = 1e17 + 10;
const long long INF = 1e9 + 7;
void add(long long& a, long long b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}
long long X[] = {0, 1, 0, -1};
long long Y[] = {-1, 0, 1, 0};
long long power(long long x, long long n) {
  long long result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = (result * x) % mod;
    x = ((x % mod) * (x % mod)) % mod;
    n = n / 2;
  }
  return result;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long a[601] = {0};
  for (long long i = 1; i < n + 1; i++) {
    long long x;
    cin >> x;
    a[x] = 1;
  }
  long long ans = 0;
  for (long long i = 1; i <= 600; i++)
    if (a[i]) ans++;
  cout << ans;
  return 0;
}
