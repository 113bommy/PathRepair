#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long n;
unsigned long long p, k, a[300010];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> p >> k;
  for (long long i = 0; i < n; i++) cin >> a[i];
  map<unsigned long long, long long> make_pair;
  for (long long i = 0; i < n; i++) {
    a[i] %= p;
    unsigned long long x = (((a[i] * a[i]) % p) * ((a[i] * a[i]) % p)) % p,
                       y = ((k * a[i]) % p);
    a[i] = (x >= y ? x - y : x + p - y);
    make_pair[a[i]]++;
  }
  long long s = 0;
  for (auto u : make_pair) {
    s += ((u.second) * (u.second - 1) / 2);
  }
  cout << s << '\n';
  return 0;
}
