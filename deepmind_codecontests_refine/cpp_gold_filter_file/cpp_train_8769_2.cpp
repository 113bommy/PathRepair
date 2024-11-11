#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("avx")
using namespace std;
long long fpow(long long x, long long y) {
  long long temp;
  if (y == 0) return 1;
  temp = fpow(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void sieve(long long n) {
  bool prime[5 * 100005];
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
long long cnt, sum = 0, mid, mx = -1e17, mn = 1e17, a[2 * 100005];
long long n, m, d, t, i, j, k, l, r, x, y, z;
bool f, f1, f2;
string s;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> x;
  vector<long long> d(n), a(n + n + 2), b(n + n + 2);
  for ((i) = 1; (i) <= (n); (i)++) cin >> d[i - 1];
  reverse(d.begin(), d.end());
  for (i = 0; i < n; i++) d.push_back(d[i]);
  a[0] = 0;
  b[0] = 0;
  for (i = 1; i <= n + n; i++) {
    a[i] = d[i - 1] + a[i - 1];
    b[i] = (d[i - 1] * (d[i - 1] + 1)) / 2 + b[i - 1];
  }
  mx = 1;
  z = x;
  for (i = 1; i <= n + n; i++) {
    sum = 0;
    x = z;
    l = i - 1;
    r = n + n;
    while (l < r) {
      mid = (l + r + 1) >> 1;
      if (a[mid] - a[i - 1] <= x)
        l = mid;
      else
        r = mid - 1;
    }
    sum = b[l] - b[i - 1];
    x -= a[l] - a[i - 1];
    if (x && l < 2 * n) {
      y = d[l] - x;
      sum += b[l + 1] - b[l] - (y * (y + 1)) / 2;
    }
    mx = max(sum, mx);
  }
  cout << mx;
  cout << "\n";
}
