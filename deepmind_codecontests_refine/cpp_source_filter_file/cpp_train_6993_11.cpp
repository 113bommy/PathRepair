#include <bits/stdc++.h>
using namespace std;
void fun() {}
long long mod = 1e9 + 7;
long long powe(long long x, long long y) {
  x = x % mod, y = y % (mod - 1);
  long long ans = 1;
  while (y > 0) {
    if (y & 1) {
      ans = (1ll * x * ans) % mod;
    }
    y >>= 1;
    x = (1ll * x * x) % mod;
  }
  return ans;
}
long long ad(long long x, long long y) { return (x % mod + y % mod) % mod; }
long long sub(long long x, long long y) {
  return (x % mod - y % mod + mod) % mod;
}
long long mul(long long x, long long y) {
  return ((x % mod) * (y % mod)) % mod;
}
long long divi(long long x, long long y) { return (mul(x, powe(y, mod - 2))); }
const long long N = 200005;
long long last[N];
long long a[N];
long long freq[N];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  fun();
  long long n, q;
  cin >> n >> q;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    last[a[i]] = i;
  }
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    long long start = i;
    long long end = last[a[i]];
    long long mx = 0;
    for (long long j = start; j <= end; j++) {
      end = max(last[a[j]], end);
      freq[a[j]]++;
      mx = max(freq[a[j]], mx);
    }
    sum += (end - i + 1 - mx);
    i = end + 1;
  }
  cout << sum << "\n";
}
