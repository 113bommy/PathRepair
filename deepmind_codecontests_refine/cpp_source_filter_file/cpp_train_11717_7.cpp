#include <bits/stdc++.h>
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
inline long long fpow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
inline int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }
using namespace std;
long long p, q, n, a[N];
bool ok;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  long long q = 2;
  for (int i = 0; i < n; ++i) {
    long long x;
    cin >> x;
    if (x & 1) ok = true;
    q = fpow(q, x);
  }
  q *= inv(2);
  q %= MOD;
  p = q;
  if (!ok) {
    ++p;
    if (p > MOD) p -= MOD;
    p *= inv(3);
    p %= MOD;
  } else {
    --p;
    if (p < 0) p += MOD;
    p *= inv(3);
    p %= MOD;
  }
  cout << p << "/" << q << endl;
  return 0;
}
