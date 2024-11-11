#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9;
const long long linf = 1e18;
const double eps = 1e-9;
const double pi = acos(-1.0);
const long long MOD = 1e9 + 7;
inline long long mod(long long a, long long b = MOD) { return (a % b + b) % b; }
inline long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
inline long long xdiv(long long a, long long b) {
  if (a % b == 0)
    return a / b;
  else
    return a / b + 1;
}
inline long long fpow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
inline long long inv(long long a, long long m = MOD) {
  return fpow(a, m - 2, m);
}
template <typename T>
void prnt(T beg, T end) {
  for (T it = beg; it != end; it++) cout << *it << " ";
  cout << endl;
}
long long T;
const long long maxn = 2e3;
long long a[maxn], b[maxn];
long long n;
void solve() {
  cin >> n;
  for (long long i = (1); i <= (n); i++) cin >> a[i];
  for (long long i = (1); i <= (n); i++) cin >> b[i];
  long long fmx = INT_MIN;
  for (long long l = (1); l <= (n); l++) {
    long long sora = 0, sorb = 0;
    for (long long r = (l); r <= (n); r++) {
      sora |= a[r], sorb |= b[r];
      fmx = max(fmx, sora + sorb);
    }
  }
  cout << fmx;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
