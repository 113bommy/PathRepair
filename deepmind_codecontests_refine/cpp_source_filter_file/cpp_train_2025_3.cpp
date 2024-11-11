#include <bits/stdc++.h>
using namespace std;
const long long maxs = 1e5 + 3;
const long long maxs1 = 1e3 + 4;
const long long mod = 1e9 + 7;
inline long long add(long long a, long long b) { return (mod + a + b) % mod; }
inline long long sub(long long a, long long b) { return (a - b + mod) % mod; }
inline long long mul(long long a, long long b) { return (1ll * a * b) % mod; }
long long fastpow(long long x, long long y) {
  long long res = 1;
  x = x % mod;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
long long inv(long long x) { return fastpow(x, mod - 2); }
vector<int> X;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k, i;
  cin >> n;
  long long a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n - 1; ++i) {
    if (a[i + 1] < a[i]) X.push_back(i);
  }
  if (X.empty())
    cout << 0;
  else {
    if (a[n - 1] > a[0] || X.size() > 1)
      cout << -1;
    else
      cout << n - *(X.rbegin());
  }
}
