#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("avx")
using namespace std;
long long fpow(long long x, long long y, long long m) {
  long long temp;
  if (y == 0 || x == 1) return 1;
  temp = fpow(x, y / 2, m);
  if (y % 2 == 0)
    return ((temp) * (temp)) % m;
  else
    return (((x) % m) * ((temp * temp) % m)) % m;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void sieve(long long n) {
  bool prime[5 * 300005];
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= n; p++)
    if (prime[p] == true)
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
  prime[1] = 0;
}
inline long long read() {
  long long p = 1, ans = 0;
  char ch = getchar();
  while (ch < 48 || ch > 57) {
    if (ch == '-') p = -1;
    ch = getchar();
  }
  while (ch >= 48 && ch <= 57) {
    ans = (ans << 3) + (ans << 1) + ch - 48;
    ch = getchar();
  }
  return ans * p;
}
long long cnt, sum, mid, mx = -1e17, mn = 1e17, a[2 * 300005];
long long n, m, d, t, i, j, k, l, r, x, y, z;
bool f, f1, f2;
string s;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  n = read();
  vector<long long> s(n + 2);
  for ((i) = 1; (i) <= ((n + 1) / 2); (i)++) {
    a[i] = read();
    s[i] = a[i] + s[i - 1];
  }
  x = read();
  for (; i <= n; i++) s[i] = s[i - 1] + x;
  if (s[n] > 0) {
    cout << n;
    return 0;
  }
  if (x >= 0) {
    cout << -1;
  } else {
    vector<long long> dp(n + 2);
    sum = 0;
    for ((i) = 1; (i) <= ((n + 1) / 2); (i)++) {
      sum += x - a[i];
      dp[i] = min(dp[i - 1], sum);
    }
    for (k = ((n + 1) >> 1); k <= n; k++) {
      if (s[k] + dp[n - k] > 0) {
        cout << k;
        return 0;
      }
    }
    cout << -1;
  }
}
